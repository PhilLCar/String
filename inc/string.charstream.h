#if defined(CHARSTREAM_H) || 1
// TODO: Replace 1 with defined(STRING)

#ifndef STRING_CHARSTREAM_H
#define STRING_CHARSTREAM_H

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <charstream.h>
#include <str.h>

#define TYPENAME CharStream

// Gets the line as is
String *_(GetLine)();

// Gets the line and interprets what's after the escape char
String *_(ReadLine)();

// Reads and consume the stream
String *_(ReadToEnd)();

#undef TYPENAME
#endif

#endif
