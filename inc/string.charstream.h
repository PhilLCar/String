#ifndef STRING_CHARSTREAM_H
#define STRING_CHARSTREAM_H

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <charstream.h>
#include <str.h>

#define TYPENAME CharStream

// Gets the line as is
String *_(getline)();
// Gets the line and interprets what's after the escape char
String *_(readline)();

__attribute__((unused)) static String *(*csgetline)  (CharStream*) = CharStream_getline;
__attribute__((unused)) static String *(*csreadline) (CharStream*) = CharStream_readline;

#undef TYPENAME
#endif
