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
  "%Of",  // CUT Object (free)
};

/******************************************************************************/
int _format_startsw(const char *a, const char *b)
{
  int i;

  for (i = 0; a[i] && b[i]; i++) {
    if (a[i] != b[i]) return 0;
  }

  return i;
}

/******************************************************************************/
int _format_match(const char *format)
{
  int max = 0;

  for (int i = 0; i < (sizeof(_formats) / sizeof(char*)); i++) {
    int match = _format_startsw(format, _formats[i] + 1);

    if (match > max) {
      max = match;
    }
  }

  return max;
}


////////////////////////////////////////////////////////////////////////////////
int _format_extract(const char *format, char **whole, char **param, char **type)
{
  if (*format != '%') return 0;

  for (const char *c = format + 1; *c; c++) {
    int match = 0;

    if (*c == '[') {
      // Reach the next closing bracket
      while (*c && *c != ']') ++c;
    } else if (*c == '(') {
      // Reach the next closing parenthesis
      while (*c && *c != ')') ++c;
    } else {
      match = _format_match(c);
    }

    if (match) {
      int size = c - format + match;

      if (whole) {
        *whole = malloc(size + 1);

        memcpy(*whole, format, size);
        (*whole)[size] = 0;
      }

      if (param) {
        int psize =  c - format - 1;

        *param = malloc(psize + 1);

        memcpy(*param, format + 1, psize);
        (*param)[psize] = 0;
      }

      if (type) {
        *type = malloc(match + 1);

        memcpy(*type, c, match);
        (*type)[match] = 0;
      }

      return size - 1;
    }
  }

  return 0;
}