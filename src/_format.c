#include "_format.h"

const char *_formats[] = {
  "%c",   // char
  "%d",   // signed char, short, int, long
  "%e",   // float 1.5+e1
  "%E",   // float 1.5+E1
  "%f",   // float 15.0
  "%g",   // float 15
  "%G",   // float 15
  "%i",   // signed int
  "%ld",  // signed long int, long etc
  "%li",  // signed long int
  "%lf",  // double
  "%Lf",  // long double
  "%lu",  // unsigned long, unsigned long int, etc
  "%lli", // long long int
  "%lld", // long long int, long long, etc
  "%llu", // unsigned long long, unsgiend long long int etc
  "%o",   // octal
  "%p",   // pointer
  "%s",   // char*
  "%u",   // unsigned int
  "%x",   // hexadecimal 0xf
  "%X",   // hexadecimal 0xF
  "%n",   // nothing
  "%%",   // %
  "%O",   // CUT Object
  "%Of"   // CUT Object (free)
};

/******************************************************************************/
int _startsw(const char *a, const char *b)
{
  int i;

  for (i = 0; a[i] && b[i]; i++) {
    if (a[i] != b[i]) return 0;
  }

  return i;
}

/******************************************************************************/
int _match(const char *format)
{
  int max   = 0;

  for (int i = 0; i < (sizeof(_formats) / sizeof(char*)); i++) {
    int match = _startsw(format, _formats[i] + 1);

    if (match > max) {
      max = match;
    }
  }

  return max;
}


////////////////////////////////////////////////////////////////////////////////
int _extract_format(const char *format, char buffer[])
{
  if (*format != '%') return 0;

  for (const char *c = format + 1; *c; c++) {
    int match = _match(c);

    if (match) {
      int size = c - format + match;

      memcpy(buffer, format, size);
      
      buffer[size] = 0;

      return size - 1;
    }
  }

  return 0;
}