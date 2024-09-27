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

void  _(close)()            VIRTUAL (close);
void *_(peek) ()            VIRTUAL (peek);
void *_(get)  ()            VIRTUAL (get);
void  _(unget)(void *token) VIRTUAL (unget);

#undef TYPENAME
#endif
