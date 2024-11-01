#include <stdio.h>

#include <str.h>
#include <stringstream.h>
#include <string.charstream.h>

int main(void)
{
  printf("Yé!\n");

  CHECK_MEMORY

  String *test = NEW (String) ("J'aime les patates!\n");

  String *other = NEW (String) (test->base);

  if (String_Equals(test, other))
  {
    printf("nice!\n");
  }

  String_Concat(test, other);

  printf("%s\n", test->base);

  CHECK_MEMORY

  StringStream *s = NEW (StringStream) (test);

  String *line = CharStream_GetLine((CharStream*)s);

  printf("%s\n", line->base);

  DELETE (line);

  DELETE (test);

  DELETE (s);

  CHECK_MEMORY

  STOP_WATCHING

  return 0;
}