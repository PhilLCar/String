#ifndef STR_UTILS
#define STR_UTILS

// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <stream.h>

// A string of characters, with length
#define TYPENAME String

OBJECT (const char*) INHERIT (char*)
  int   length;
END_OBJECT;

STREAMABLE(ss);

String *_(concat)(String *other);
String *_(append)(char c);
String *_(prepend)(char c);
String *_(inject)(int index, char c);
String *_(substring)(int start, int length);
String *_(trim)();
int     _(equals)(String *other);
int     _(contains)(String *other);

#undef TYPENAME

// Stream extension
#define TYPENAME Stream

String *_(getline)();

#undef TYPENAME
#endif
