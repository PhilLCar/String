#ifndef STR_UTILS
#define STR_UTILS

// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CUT
#include <diagnostic.h>
#include <oop.h>

// A string of characters, with length
#define TYPENAME String

OBJECT (const char*) INHERIT (char*)
  int   length;
END("");

String *_(concat)(String *other);
String *_(append)(char c);
String *_(prepend)(char c);
String *_(inject)(int index, char c);
String *_(substring)(int start, int length);
String *_(trim)();
int     _(equals)(String *other);
int     _(contains)(String *other);
int     _(cequals)(const char *other);
int     _(ccontains)(const char *other);
int     _(starts_with)(const char *other);
int     _(ends_with)(const char *other);

#undef TYPENAME
#endif
