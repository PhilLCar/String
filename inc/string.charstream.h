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

// Puts the line as is
void    _(putline)(const char *line);
// Puts the line and generates escape sequences based on the specified escape char
void    _(writeline)(const char *line);

__attribute__((unused)) static String *(*csgetline)  (CharStream*)                   = CharStream_getline;
__attribute__((unused)) static String *(*csreadline) (CharStream*)                   = CharStream_readline;
__attribute__((unused)) static void    (*csputline)  (CharStream*, const char *line) = CharStream_putline;
__attribute__((unused)) static void    (*cswriteline)(CharStream*, const char *line) = CharStream_writeline;


#undef TYPENAME
#endif
