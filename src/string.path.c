#include <string.path.h>

#ifdef STRING_PATH_H

#define TYPENAME Path

String *STATIC (File)(const char *path)
{
  return BUFFERIZE(fnamext(path, sizeof(buffer), buffer));
}

String *STATIC (FileName)(const char *path)
{
  return BUFFERIZE(fname(path, sizeof(buffer), buffer));
}

String *STATIC (Extension)(const char *path)
{
  return BUFFERIZE(fext(path, sizeof(buffer), buffer));
}

String *STATIC (Folder)(const char *path)
{
  String *result = BUFFERIZE(fpath(path, sizeof(buffer), buffer));

  while (result && result->length > 1 && result->base[result->length - 1] == PATH_MARKER) {
    // Remove the trailing path marker
    String_SubString(result, 0, -1);
  }

  return result;
}

String *STATIC (Combine)(const char *path, const char *file)
{
  return BUFFERIZE(pcombine(path, file, sizeof(buffer), buffer));
}

#undef TYPENAME
#endif