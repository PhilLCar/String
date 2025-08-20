#ifndef PRINT_H
#define PRINT_H

#include <diagnostic.h>
#include <str.h>

#include "string.export.h"

STRING_EXPORT void fprints(FILE *stream, String *string);
STRING_EXPORT void sprints(char buffer[], String *string);
STRING_EXPORT void prints(String *string);

STRING_EXPORT void fprint(FILE *stream, const char *format, ...);
STRING_EXPORT void sprint(char buffer[], const char *format, ...);
STRING_EXPORT void print(const char *format, ...);

#endif