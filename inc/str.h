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

String *_(concat)(String *other)            ALIAS (concat);
String *_(append)(char c)                   ALIAS (append);
String *_(prepend)(char c)                  ALIAS (prepend);
String *_(inject)(int index, char c)        ALIAS (inject);
String *_(substring)(int start, int length) ALIAS (substring);
String *_(trim)()                           ALIAS (trim);
int     _(equals)(String *other)            ALIAS (equals);
int     _(contains)(String *other)          ALIAS (contains);

#undef TYPENAME

// Stream extension
#define TYPENAME Stream

String *_(getline)() ALIAS (sgetline);

#undef TYPENAME
#endif
