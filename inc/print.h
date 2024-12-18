#ifndef PRINT_H
#define PRINT_H

#include <diagnostic.h>
#include <str.h>

void fprints(FILE *stream, String *string);
void sprints(char buffer[], String *string);
void prints(String *string);

void fprint(FILE *stream, const char *format, ...);
void sprint(char buffer[], const char *format, ...);
void print(const char *format, ...);

#endif