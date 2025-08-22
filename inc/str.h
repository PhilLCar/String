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
#include "string.export.h"

// A string of characters, with length
#define LIB_EXPORT STRING_EXPORT
#define TYPENAME String

OBJECT (const char*) INHERIT (char*)
  int   length;
END_OBJECT("");

STRING_EXPORT String *_(Concat)(String *other);
STRING_EXPORT String *_(Cat)(const char *other);
STRING_EXPORT String *_(Append)(char c);
STRING_EXPORT String *_(Prepend)(char c);
STRING_EXPORT String *_(Insert)(int index, char c);
STRING_EXPORT String *_(SubString)(int start, int length);
STRING_EXPORT String *_(Trim)();
STRING_EXPORT String *_(ToLower)();
STRING_EXPORT String *_(ToUpper)();

STRING_EXPORT String *CONST (Copy)();

STRING_EXPORT int CONST (Equals)(const String *other);
STRING_EXPORT int CONST (Eq)(const char *other);
STRING_EXPORT int CONST (Compare)(const String *other);
STRING_EXPORT int CONST (Cmp)(const char *other);
STRING_EXPORT int CONST (Contains)(const String *other);
STRING_EXPORT int CONST (Cnt)(const char *other);
STRING_EXPORT int CONST (StartsWith)(const char *other);
STRING_EXPORT int CONST (EndsWith)(const char *other);

STRING_EXPORT String *STATIC (Format)(const char *format, ...);
STRING_EXPORT String *STATIC (ToString)(const void *object);
STRING_EXPORT String *STATIC (ToStringType)(const void *object, const Type *type);
STRING_EXPORT String *STATIC (ToStringFormat)(const void *object, const Type *type, const char *format);

FOREIGN_VIRTUAL(ToString,    String_Copy);
FOREIGN_VIRTUAL(KeyComparer, String_Cmp);
FOREIGN_VIRTUAL(Comparer,    String_Compare);

#undef TYPENAME
#undef LIB_EXPORT
#endif
