#if defined(FILE_H) || defined(STRING) || 1
// TODO: remove 1

#ifndef STRING_PATH_H
#define STRING_PATH_H

// CUT
#include <diagnostic.h>
#include <str.h>
#include <file.h>
#include <path.h>

#include "string.export.h"

// Static Class
#define TYPENAME Path

STRING_EXPORT String *STATIC (File)(const char *path);
STRING_EXPORT String *STATIC (FileName)(const char *path);
STRING_EXPORT String *STATIC (Extension)(const char *path);
STRING_EXPORT String *STATIC (Folder)(const char *path);
STRING_EXPORT String *STATIC (Combine)(const char *path, const char *file);


#undef TYPENAME
#endif

#endif
