#ifndef _FORMAT_H
#define _FORMAT_H

#include <diagnostic.h>
#include <string.h>
#include <stdlib.h>

// For printing
#define STRING_INIT_BUFFER_LENGTH   1 << 10
#define STRING_MAX_BUFFER_LENGTH    1 << 20

#define BUFFERIZE(ACTION) ({\
  String *result = NULL;\
  \
  for (int i = STRING_INIT_BUFFER_LENGTH; ; i <<= 1) {\
    if (i >= STRING_MAX_BUFFER_LENGTH) {\
      THROW (NEW (Exception) ("Buffer overflow!"));\
      break;\
    } else {\
      char buffer[i];\
      int  len = ACTION;\
  \
      if (len < sizeof(buffer)) {\
        result = NEW (String) (buffer);\
        break;\
      }\
    }\
  }\
  \
  result;\
});

// Returns the format string at the specified pointer, for instance:
// Let's say format is "%-32O something"
// whole: "%-32O"
// param: "-32"
// type:  "O"
// returns 5, which is equivalent to strlen(whole)
int _format_extract(const char *format, char **whole, char **param, char **type);

#endif