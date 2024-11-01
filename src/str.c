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
String *_(Append)(char c)
{
  char *n = realloc(this->base, (this->length + 2) * sizeof(char));

  if (n) {
    this->base                  = n;
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
    for (int i = this->length + 1; i > 0; i--) this->base[i] = this->base[i - 1];
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

#undef TYPENAME
