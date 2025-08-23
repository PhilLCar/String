#ifndef _FORMAT_H
#define _FORMAT_H

#include <diagnostic.h>
#include <string.h>
#include <stdlib.h>

// For printing
#define STRING_BUFFER_LENGTH 1 << 10

#define BUFFER(ACTION) ({ \
  char buffer[STRING_BUFFER_LENGTH]; \
  int  length = ACTION; \
  \
  if (length >= STRING_BUFFER_LENGTH) { \
    THROW (NEW (Exception) ("Buffer overflow!")); \
  } \
  \
  NEW (String) (buffer); \
})

// Returns the format string at the specified pointer, for instance:
// Let's say format is "%-32O something"
// whole: "%-32O"
// param: "-32"
// type:  "O"
// returns 5, which is equivalent to strlen(whole)
int _format_extract(const char *format, char **whole, char **param, char **type);

#endif