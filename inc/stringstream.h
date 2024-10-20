#ifndef STRINGSTREAM_H
#define STRINGSTREAM_H

// CUT
#include <diagnostic.h>
#include <str.h>
#include <charstream.h>

#define TYPENAME StringStream

OBJECT (String *string) INHERIT (CharStream)
  int pos;
END(NULL);

void  _(close)()      VIRTUAL (close);
int   _(peek) ()      VIRTUAL (peek);
int   _(get)  ()      VIRTUAL (get);
void  _(unget)(int c) VIRTUAL (unget);
void  _(put)  (int c) VIRTUAL (put);

#undef TYPENAME
#endif
