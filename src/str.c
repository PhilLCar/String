#include <str.h>

#define TYPENAME String

////////////////////////////////////////////////////////////////////////////////
String *_(Construct)(const char *cstr)
{
  if (this) {
    int   len  = (int)strlen(cstr);
    void *base = malloc((len + 1) * sizeof(char));

    if (base) {
      this->length = len;
      this->base   = base;
      strcpy(base, cstr);
    } else {
      THROW(NEW (MemoryAllocationException)());
    }
  } else {
    THROW(NEW (MemoryAllocationException)());
  }

  return this;
}

////////////////////////////////////////////////////////////////////////////////
void _(Destruct)()
{
  if (this && this->base) {
    free(this->base);
    this->base = NULL;
  }
}

////////////////////////////////////////////////////////////////////////////////
String *_(Concat)(String *other)
{
  char *n = realloc(this->base, (this->length + other->length + 1) * sizeof(char));

  if (n) {
    strcpy(n + this->length, other->base);
    this->base    = n;
    this->length += other->length;
  } else {
    DELETE (this);
  }
  
  DELETE (other);

  return this;
}

////////////////////////////////////////////////////////////////////////////////
String *_(Cat)(const char *other)
{
  return String_Concat(this, NEW (String) (other));
}

////////////////////////////////////////////////////////////////////////////////
String *_(Append)(char c)
{
  char *n = realloc(this->base, (this->length + 2) * sizeof(char));

  if (n) {
    this->base                 = n;
    this->base[this->length]   = c;
    this->base[++this->length] = 0;
  } else {
    DELETE (this);
  }

  return this;
}

////////////////////////////////////////////////////////////////////////////////
String *_(Prepend)(char c)
{
  char *n = realloc(this->base, (this->length + 2) * sizeof(char));

  if (n) {
    this->base = n;
    for (int i = ++this->length; i > 0; i--) this->base[i] = this->base[i - 1];
    this->base[0] = c;
  } else {
    DELETE (this);
  }

  return this;
}

////////////////////////////////////////////////////////////////////////////////
String *_(Insert)(int index, char c)
{
  char *n = realloc(this->base, (this->length + 2) * sizeof(char));

  if (n) {
    this->base = n;
    for (int i = this->length + 1; i > index; i--) this->base[i] = this->base[i - 1];
    this->base[index] = c;
  } else {
    DELETE (this);
  }

  return this;
}

////////////////////////////////////////////////////////////////////////////////
String *_(SubString)(int start, int length)
{
  char *s;

  if (length <= 0) length = this->length - start + length;
  s = malloc((length + 1) * sizeof(char));

  if (s) {
    for (int i = 0; i < length; i++) {
      s[i] = this->base[start + i];
    }
    s[length] = 0;
    free(this->base);
    this->base   = s;
    this->length = length;
  } else {
    DELETE (this);
  }
  
  return this;
}

////////////////////////////////////////////////////////////////////////////////
String *_(Trim)()
{
  int start, length;

  for (start = 0; start < this->length; start++) {
    char c = this->base[start];
    if (c != ' ' && c != '\t' && c != '\n' && c != '\r') break;
  }

  for (length = this->length - start; length > 0; length--) {
    char c = this->base[start + length - 1];
    if (c != ' ' && c != '\t' && c != '\n' && c != '\r') break;
  }

  return String_SubString(this, start, length);
}

////////////////////////////////////////////////////////////////////////////////
String *_(ToLower)()
{
  for (int i = 0; i < this->length; i++)
  {
    char *base = this->base;

    if (base[i] >= 'A' && base[i] <= 'Z') base[i] += 'a' - 'A';
  }

  return this;
}

////////////////////////////////////////////////////////////////////////////////
String *_(ToUpper)()
{
  for (int i = 0; i < this->length; i++)
  {
    char *base = this->base;

    if (base[i] >= 'a' && base[i] <= 'z') base[i] += 'A' - 'a';
  }

  return this;
}

////////////////////////////////////////////////////////////////////////////////
String *CONST (Copy)()
{
  return NEW (String) (this->base);
}

////////////////////////////////////////////////////////////////////////////////
int CONST (Equals)(const String *other)
{
  return other->length == this->length && !strcmp(other->base, this->base);
}

////////////////////////////////////////////////////////////////////////////////
int CONST (Eq)(const char *other)
{
  return !strcmp(other, this->base);
}

////////////////////////////////////////////////////////////////////////////////
int CONST (Compare)(const String *other)
{
  return strcmp(other->base, this->base);
}

////////////////////////////////////////////////////////////////////////////////
int CONST (Cmp)(const char *other)
{
  return strcmp(other, this->base);
}

/******************************************************************************/
int STATIC (contains)(const char *acon, int alen, const char *bcon, int blen)
{
  int   match = 0;
  int   pos   = -1;

  for (int j = 0; j <= alen - blen; j++) {
    match = acon[j] == bcon[0];
    for (int i = 1; match && i < blen; i++) {
      match &= acon[i + j] == bcon[i];
    }
    if (match) {
      pos = j;
      break;
    }
  }

  return pos;
}

////////////////////////////////////////////////////////////////////////////////
int CONST (Contains)(const String *other)
{
  return String_contains(this->base, this->length, other->base, other->length);
}

////////////////////////////////////////////////////////////////////////////////
int CONST (Cnt)(const char *other)
{
  return String_contains(this->base, this->length, other, strlen(other));
}

////////////////////////////////////////////////////////////////////////////////
int CONST (StartsWith)(const char *other)
{
  int starts = 1;

  for (int i = 0; other[i]; i++) {
    if (other[i] != this->base[i]) {
      starts = 0;
      break;
    }
  }

  return starts;
}

////////////////////////////////////////////////////////////////////////////////
int CONST (EndsWith)(const char *other)
{ 
  int ends = 1;
  int size = strlen(other);

  for (int i = 0; other[i]; i++) {
    if (other[i] != this->base[this->length - size + i]) {
      ends = 0;
      break;
    }
  }

  return ends;
}

/******************************************************************************/
String *_(justify)(const char *param)
{
  char c = param[0];

  if (c == '+') {
    int size = atoi(param + 1);

    while (size > this->length) {
      String_Prepend(this, ' ');
    }
  } else if (c == '-') { 
    int size = -atoi(param);

    while (size > this->length) {
      String_Append(this, ' ');
    }

  } else if (c) { // center
    int size = atoi(param);

    while (size > this->length) {
      (this->length % 2 ? String_Append : String_Prepend)(this, ' ');
    }
  }

  return this;
}

/******************************************************************************/
String *STATIC (format)(const char *format, va_list list)
{
  String *buffer = NEW (String) ("");

  for (int i = 0; format[i]; i++) {
    if (format[i] == '%') {
      char *fmtbuf, *prmbuf, *typbuf;

      i += _format_extract(&format[i], &fmtbuf, &prmbuf, &typbuf);

      if (typbuf[0] == 'O') {
        void   *object = va_arg(list, void*);
        String *print  = NULL;

        if (prmbuf[0] == '(' || prmbuf[0] == '[') {
          char *type    = strchr(prmbuf, '(');
          char *format  = strchr(prmbuf, '[');
          char *justify = IFNULL(strrchr(prmbuf, ']'), strchr(prmbuf, ')'));

          // type must always come before (or it means it's for another format)
          if (type > format)    type        = NULL;
          if (type)           *(type++)     = 0;
          if (type && format) *(format - 1) = 0;
          if (format)         *(format++)   = 0;
          
          *(justify++) = 0;

          print = String_justify(String_ToStringFormat(object, type ? findtype(type) : gettype(object), format), justify);
        } else {
          print = String_justify(String_ToString(object), prmbuf);
        }

        if (typbuf[1] == 'f') {
          DELETE(object);
        }

        String_Concat(buffer, print);
      } else {
        va_list  copy;
        String  *result = BUFFERIZE(({ va_copy(copy, list); vsnprintf(buffer, sizeof(buffer), fmtbuf, copy);}); va_end(copy))

        // Advance the real list (not the copy)
        vsnprintf(NULL, 0, fmtbuf, list);

        String_Concat(buffer, result);
      }

      free(fmtbuf);
      free(prmbuf);
      free(typbuf);
    } else {
      String_Append(buffer, format[i]);
    }
  }

  return buffer;
}

////////////////////////////////////////////////////////////////////////////////
String *STATIC (Format)(const char *format, ...)
{
  va_list argv;
  va_start(argv, format);

  String *formatted = String_format(format, argv);

  va_end(argv);

  return formatted;
}

////////////////////////////////////////////////////////////////////////////////
String *STATIC (ToString)(const void *object)
{
  return String_ToStringFormat(object, object ? gettype(object) : NULL, NULL);
}

////////////////////////////////////////////////////////////////////////////////
String *STATIC (ToStringType)(const void *object, const Type *type)
{
  return String_ToStringFormat(object, type, NULL);
}

/******************************************************************************/
String *STATIC (ToStringFormat)(const void *object, const Type *type, const char *format)
{
  String *result = NULL;

  if (object) {
    switch (type->category) {
    case TYPES_FLOAT:
      if (!strcmp(type->name, "float")) {
        result = String_Format("%g", *(float*)object);
#ifndef WIN
      } else if (!strcmp(type->name, "__float128")) {
        result = String_Format("%g", *(__float128*)object);
#endif
      } else {
        // Default to double
        result = String_Format("%g", *(double*)object);
      }      
      break;
    case TYPES_POINTER:
      result = String_Format("%p", object);
      break;
    case TYPES_OBJECT:
      {
        if (format && format[0]) {
          ConstVirtualFunction toStringFormat = constvirtual(type, "ToStringFormat");

          if (toStringFormat) {
            result = toStringFormat(object, format);
          }
        } else {
          ConstVirtualFunction toString = constvirtual(type, "ToString");

          if (toString) {
            result = toString(object);
          }
        }

        result = IFNULL(result, String_Format("{%s at %p}", type->name, object));
      }
      break;
    case TYPES_SIGNED:
      {
        switch (type->size) {
          case 1:
            result = String_Format("%c", *(char*)object);
            break;
          case 2:
            result = String_Format("%d", *(short*)object);
            break;
          case 8:
            result = String_Format("%ld", *(long*)object);
            break;
          // Default to int
          case 4:
          default:
            result = String_Format("%d", *(int*)object);
            break;
        }
      }
      break;
    case TYPES_UNSIGNED:
      {
        switch (type->size) {
          case 1:
            result = String_Format("%u", *(unsigned char*)object);
            break;
          case 2:
            result = String_Format("%u", *(unsigned short*)object);
            break;
          case 8:
            result = String_Format("%lu", *(long*)object);
            break;
          // Default to uint
          case 4:
          default:
            result = String_Format("%u", *(unsigned int*)object);
            break;
        }
      }
      break;
    default:
      THROW (NEW (Exception) ("Displaying this type is not implemented yet!"));
    }
  } else {
    result = NEW (String) ("(null)");
  }

  return result;
}


#undef TYPENAME
