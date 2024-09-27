#include <stringstream.h>

#define TYPENAME StringStream

////////////////////////////////////////////////////////////////////////////////
StringStream *_(cons)(String *current)
{
  if (this)
  {
    CharStream_cons(BASE(0), NEW (String) (current->base));
    this->pos = 0;
  }

  return this;
}

////////////////////////////////////////////////////////////////////////////////
void _(free)()
{
  CharStream_free(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
void _(close)()
{
  DELETE (*BASE(2));
}

////////////////////////////////////////////////////////////////////////////////
void *_(peek)()
{
  String *base = *BASE(2);

  long c = (long)base->base[this->pos];

  if (!c) c = EOF;

  return (void*)c;
}

////////////////////////////////////////////////////////////////////////////////
void *_(get)()
{
  void *peek = StringStream_peek(this);

  if (peek != EOS) ++this->pos;

  return peek;
}

////////////////////////////////////////////////////////////////////////////////
void _(unget)(void *token)
{
  String *base = *BASE(2);

  if (this->pos) {
    String_prepend(base, (long)token);
  } else {  
    base->base[--this->pos] = (long)token;
  }
}
