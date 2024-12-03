#if defined(FILE_H) || 1
// TODO: Replace 1 with defined(STRING)
// TODO: Standardize those library interfaces to a certain point

#ifndef STRING_FILE_H
#define STRING_FILE_H

// CUT
#include <str.h>
#include <file.h>

// "static class"
#define TYPENAME Path

String *STATIC (File)(const char *path);
String *STATIC (FileName)(const char *path);
String *STATIC (Extension)(const char *path);
String *STATIC (Folder)(const char *path);
String *STATIC (Combine)(const char *path, const char *file);


#undef TYPENAME
#endif

#endif
