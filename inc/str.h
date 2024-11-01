#ifndef STR_UTILS
#define STR_UTILS

// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

// A string of characters, with length
#define TYPENAME String

OBJECT (const char*) INHERIT (char*)
  int   length;
END_OBJECT("");

String *_(Concat)(String *other);
String *_(Append)(char c);
String *_(Prepend)(char c);
String *_(Insert)(int index, char c);
String *_(SubString)(int start, int length);
String *_(Trim)();

int CONST (Equals)(const String *other);
int CONST (Eq)(const char *other);
int CONST (Compare)(const String *other);
int CONST (Cmp)(const char *other);
int CONST (Contains)(const String *other);
int CONST (Cnt)(const char *other);
int CONST (StartsWith)(const char *other);
int CONST (EndsWith)(const char *other);

#undef TYPENAME
#endif
