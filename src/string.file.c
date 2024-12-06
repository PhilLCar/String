#include <string.file.h>

#ifdef STRING_FILE_H

#define TYPENAME Path

String *STATIC (File)(const char *path)
{
  char buffer[4096];

  filenamewopath(path, buffer, sizeof(buffer));

  return NEW (String) (buffer);
}

String *STATIC (FileName)(const char *path)
{
  char buffer[4096];

  filenamewopath(path, buffer, sizeof(buffer));
  filenamewoext(buffer, buffer, sizeof(buffer));

  return NEW (String) (buffer);
}

String *STATIC (Extension)(const char *path)
{
  char buffer[4096];

  fileext(path, buffer, sizeof(buffer));

  return NEW (String) (buffer);
}

String *STATIC (Folder)(const char *path)
{
  char buffer[4096];

  int len = filepath(path, buffer, sizeof(buffer));

  if (len > 0) {
    // Remove the trailing path marker
    buffer[len - 1] = 0;
  }

  return NEW (String) (buffer);
}

String *STATIC (Combine)(const char *path, const char *file)
{
  char buffer[4096];

  filepathcombine(path, file, buffer, sizeof(buffer));

  return NEW (String) (buffer);
}

#undef TYPENAME
#endif