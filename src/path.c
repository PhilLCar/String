#include <path.h>

#ifdef STRING_FILE_H

#define TYPENAME Path

String *STATIC (File)(const char *path)
{
  return BUFFERIZE(filenamewopath(path, sizeof(buffer), buffer));
}

String *STATIC (FileName)(const char *path)
{
  return BUFFERIZE(filenamewoext(path, sizeof(buffer), buffer));
}

String *STATIC (Extension)(const char *path)
{
  return BUFFERIZE(fileext(path, sizeof(buffer), buffer));
}

String *STATIC (Folder)(const char *path)
{
  String *result = BUFFERIZE(filepath(path, sizeof(buffer), buffer));

  while (result && result->length > 1 && result->base[result->length - 1] == PATH_MARKER) {
    // Remove the trailing path marker
    String_SubString(result, 0, -1);
  }

  return result;
}

String *STATIC (Combine)(const char *path, const char *file)
{
  return BUFFERIZE(filepathcombine(path, file, sizeof(buffer), buffer));
}

#undef TYPENAME
#endif