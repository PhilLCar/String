#ifndef CUTEXCEPTION_H
#define CUTEXCEPTION_H

// CUT
#include <diagnostic.h>
#include <exception.h>
#include <str.h>

#include "string.export.h"

#define LIBEXPORT STRING_EXPORT
#define TYPENAME CutException

OBJECT (const char *message, ...) INHERIT (Exception)
END_OBJECT("An error occured!");

#undef TYPENAME
#undef LIBEXPORT

#endif