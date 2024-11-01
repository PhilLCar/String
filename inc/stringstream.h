#ifndef STRINGSTREAM_H
#define STRINGSTREAM_H

// CUT
#include <diagnostic.h>
#include <str.h>
#include <charstream.h>

#define TYPENAME StringStream

OBJECT (String *string) INHERIT (CharStream)
  int pos;
END_OBJECT(NULL);

void  _(Close)()      VIRTUAL (Close);
int   _(Peek) ()      VIRTUAL (Peek);
int   _(Get)  ()      VIRTUAL (Get);
void  _(Unget)(int c) VIRTUAL (Unget);
void  _(Put)  (int c) VIRTUAL (Put);

#undef TYPENAME
#endif
