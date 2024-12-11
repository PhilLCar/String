#include <print.h>

String *String_format(const char *format, va_list list);

////////////////////////////////////////////////////////////////////////////////
void fprints(FILE *stream, String *string)
{
  fprintf(stream, "%s", string->base);
  fflush(stream);

  DELETE (string);
}

////////////////////////////////////////////////////////////////////////////////
void sprints(char buffer[], String *string)
{
  sprintf(buffer, "%s", string->base);

  DELETE (string);
}

////////////////////////////////////////////////////////////////////////////////
void prints(String *string)
{
  printf("%s", string->base);
  fflush(stdout);

  DELETE (string);
}

////////////////////////////////////////////////////////////////////////////////
void fprint(FILE *stream, const char *format, ...)
{
  va_list argv;
  va_start(argv, format);

  fprints(stream, String_format(format, argv));

  va_end(argv);
}

////////////////////////////////////////////////////////////////////////////////
void sprint(char buffer[], const char *format, ...)
{
  va_list argv;
  va_start(argv, format);

  sprints(buffer, String_format(format, argv));

  va_end(argv);
}

////////////////////////////////////////////////////////////////////////////////
void print(const char *format, ...)
{
  va_list argv;
  va_start(argv, format);

  prints(String_format(format, argv));

  va_end(argv);
}