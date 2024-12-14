#ifndef STR_H
#define STR_H

// C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <exception.h>

#include "_format.h"

// A string of characters, with length
#define TYPENAME String

OBJECT (const char*) BASED (char*)
  int   length;
END_OBJECT("");

String *_(Concat)(String *other);
String *_(Cat)(const char *other);
String *_(Append)(char c);
String *_(Prepend)(char c);
String *_(Insert)(int index, char c);
String *_(SubString)(int start, int length);
String *_(Trim)();
String *_(ToLower)();
String *_(ToUpper)();

String *CONST (Copy)();

int CONST (Equals)(const String *other);
int CONST (Eq)(const char *other);
int CONST (Compare)(const String *other);
int CONST (Cmp)(const char *other);
int CONST (Contains)(const String *other);
int CONST (Cnt)(const char *other);
int CONST (StartsWith)(const char *other);
int CONST (EndsWith)(const char *other);

String *STATIC (Format)(const char *format, ...);
String *STATIC (ToString)(const void *object);
String *STATIC (ToTypeString)(const void *object, const Type *type);
String *STATIC (ToFormatString)(const void *object, const char *format);

FOREIGN_VIRTUAL(ToString,    String_Copy);
FOREIGN_VIRTUAL(KeyComparer, String_Cmp);
FOREIGN_VIRTUAL(Comparer,    String_Compare);

#undef TYPENAME
#endif
