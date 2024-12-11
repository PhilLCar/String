#if defined(FILE_H) || defined(STRING) || 1
// TODO: remove 1

#ifndef STRING_FILE_H
#define STRING_FILE_H

// CUT
#include <str.h>
#include <file.h>

// Static Class
#define TYPENAME Path

String *STATIC (File)(const char *path);
String *STATIC (FileName)(const char *path);
String *STATIC (Extension)(const char *path);
String *STATIC (Folder)(const char *path);
String *STATIC (Combine)(const char *path, const char *file);


#undef TYPENAME
#endif

#endif
