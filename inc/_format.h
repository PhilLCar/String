#ifndef _FORMAT_H
#define _FORMAT_H

#include <string.h>

// Returns the format string at the specified pointer, for instance:
// Let's say format is "%-32O something"
// whole: "%-32O"
// param: "-32"
// type:  "O"
// returns 5, which is equivalent to strlen(whole)
int _format_extract(const char *format, char whole[], char param[], char type[]);

#endif