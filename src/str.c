#include <str.h>

#define TYPENAME String

////////////////////////////////////////////////////////////////////////////////
TYPENAME *_(cons)(const char *cstr)
{
  if (_this) {
    int   len  = (int)strlen(cstr);
    void *base = malloc((len + 1) * sizeof(char));

    if (base) {
      _this->length = len;
      _this->base   = base;
      strcpy(base, cstr);
    } else {
      free(_this);
      _this = NULL;
    }
  }

  return _this;
}

////////////////////////////////////////////////////////////////////////////////
void _(free)()
{
  if (_this) free(_this->base);
}

////////////////////////////////////////////////////////////////////////////////
TYPENAME *_(concat)(TYPENAME *other)
{
  char *n = realloc(_this->base, (_this->length + other->length + 1) * sizeof(char));

  if (n) {
    strcpy(n + _this->length, other->base);
    _this->base    = n;
    _this->length += other->length;
  } else {
    DELETE (_this);
  }
  DELETE (other);

  return _this;
}

////////////////////////////////////////////////////////////////////////////////
TYPENAME *_(append)(char c)
{
  char *n = realloc(_this->base, (_this->length + 2) * sizeof(char));

  if (n) {
    _this->base                  = n;
    _this->base[_this->length]   = c;
    _this->base[++_this->length] = 0;
  } else {
    DELETE (_this);
  }

  return _this;
}

////////////////////////////////////////////////////////////////////////////////
TYPENAME *_(prepend)(char c)
{
  char *n = realloc(_this->base, (_this->length + 2) * sizeof(char));

  if (n) {
    _this->base = n;
    for (int i = _this->length + 1; i > 0; i--) _this->base[i] = _this->base[i - 1];
    _this->base[0] = c;
  } else {
    DELETE (_this);
  }

  return _this;
}

////////////////////////////////////////////////////////////////////////////////
TYPENAME *_(inject)(int index, char c)
{
  char *n = realloc(_this->base, (_this->length + 2) * sizeof(char));

  if (n) {
    _this->base = n;
    for (int i = _this->length + 1; i > index; i--) _this->base[i] = _this->base[i - 1];
    _this->base[index] = c;
  } else {
    DELETE (_this);
  }

  return _this;
}

////////////////////////////////////////////////////////////////////////////////
TYPENAME *_(substring)(int start, int length)
{
  char *s;

  if (length <= 0) length = _this->length - start + length;
  s = malloc((length + 1) * sizeof(char));

  if (s) {
    for (int i = 0; i < length; i++) {
      s[i] = _this->base[start + i];
    }
    s[length] = 0;
    free(_this->base);
    _this->base   = s;
    _this->length = length;
  } else {
    DELETE (_this);
  }
  return _this;
}

////////////////////////////////////////////////////////////////////////////////
TYPENAME *_(trim)() {
  int start, length;

  for (start = 0; start < _this->length; start++) {
    char c = _this->base[start];
    if (c != ' ' && c != '\t') break;
  }
  for (length = _this->length - start; length > 0; length--) {
    char c = _this->base[start + length - 1];
    if (c != ' ' && c != '\t') break;
  }
  return String_substring(_this, start, length);
}

////////////////////////////////////////////////////////////////////////////////
int _(equals)(TYPENAME *other)
{
  return !strcmp(_this->base, other->base);
}

////////////////////////////////////////////////////////////////////////////////
int _(contains)(TYPENAME *other)
{
  char *acon  = _this->base;
  int   alen  = _this->length;
  char *bcon  = other->base;
  int   blen  = strlen(bcon); // Allow to call this method with a char *
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

// Streamable
//==============================================================================

////////////////////////////////////////////////////////////////////////////////
StringStream *_(open)()
{
  StringStream *ss = malloc(sizeof(StringStream));

  if (ss) {
    ss->base = NEW (String) (_this->base);
    ss->pos  = 0;
  }

  return ss;
}

////////////////////////////////////////////////////////////////////////////////
void STATIC (close)(StringStream *ss)
{
  DELETE (ss->base);
  free(ss);
}

////////////////////////////////////////////////////////////////////////////////
int STATIC (getc)(StringStream *ss)
{
  int c = ss->base->base[ss->pos];

  if (!c) c = EOF;
  else ss->pos++;

  return c;
}

////////////////////////////////////////////////////////////////////////////////
void STATIC (ungetc)(StringStream *ss, int c)
{
  if (ss->pos > 0) {
    ss->base->base[--ss->pos] = c;
  }
}

////////////////////////////////////////////////////////////////////////////////
int STATIC (peek)(StringStream *ss)
{
  int c;

  if (!ss->base->base[ss->pos]) c = EOF;
  else {
    c = ss->base->base[ss->pos + 1];
    if (!c) c = EOF;
  }

  return c;
}

#undef TYPENAME

#define TYPENAME Stream
////////////////////////////////////////////////////////////////////////////////
String *_(getline)()
{
	String *line = NEW (String) ("");
	char c;

	while((c = Stream_getc(_this)) != '\n' && c != EOF) String_append(line, c);

	if (c == EOF && !line->length) {
		DELETE (line);
	}

  return line;
}