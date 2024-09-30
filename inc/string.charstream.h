#ifndef STRING_CHARSTREAM_H
#define STRING_CHARSTREAM_H

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <charstream.h>
#include <str.h>

#define TYPENAME CharStream

String *_(getline)();
String *_(readline)(char esc);

__attribute__((unused)) static String *(*sgetline) (CharStream*)       = CharStream_getline;
__attribute__((unused)) static String *(*sreadline)(CharStream*, char) = CharStream_readline;


#undef TYPENAME
#endif
