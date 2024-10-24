#include <stdio.h>

#include <str.h>
#include <stringstream.h>
#include <str.charstream.h>

int main(void)
{
  printf("Yé!\n");

  CHECK_MEMORY

  String *test = NEW (String) ("J'aime les patates!\n");

  String *other = NEW (String) (test->base);

  if (String_equals(test, other))
  {
    printf("nice!\n");
  }

  String_concat(test, other);

  printf("%s\n", test->base);

  CHECK_MEMORY

  StringStream *s = NEW (StringStream) (test);

  String *line = csgetline((CharStream*)s);

  printf("%s\n", line->base);

  DELETE (line);

  DELETE (test);

  DELETE (s);

  CHECK_MEMORY

  STOP_WATCHING

  return 0;
}