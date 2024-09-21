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
#include <object_array.h>

// A string of characters, with length
#define TYPENAME String

OBJECT (const char*) INHERIT (char*)
  int   length;
END_OBJECT;

String      *_(concat)(String *other);
String      *_(append)(char c);
String      *_(prepend)(char c);
String      *_(inject)(int index, char c);
String      *_(substring)(int start, int length);
String      *_(trim)();
int          _(equals)(String *other);
int          _(contains)(String *other);
int          _(cequals)(const char *other);
int          _(ccontains)(const char *other);
int          _(starts_with)(const char *other);
int          _(ends_with)(const char *other);
ObjectArray *_(split)(String *other);
ObjectArray *_(csplit)(const char *other);

STREAMABLE;

#undef TYPENAME
// Stream extension
#define TYPENAME Stream

String *_(getline)();
String *_(readline)(char esc);

__attribute__((unused)) static String *(*sgetline)(Stream*)  = Stream_getline;
__attribute__((unused)) static String *(*sreadline)(Stream*, char) = Stream_readline;

#undef TYPENAME
#endif
