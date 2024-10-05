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
String *_(insert)(int index, char c);
String *_(substr)(int start, int length);
String *_(trim)();
int     _(equals)(const String *other);
int     _(eq)(const char *other);
int     _(compare)(const String *other);
int     _(cmp)(const char *other);
int     _(contains)(const String *other);
int     _(cont)(const char *other);
int     _(strw)(const char *other);
int     _(endw)(const char *other);

#undef TYPENAME
#endif
