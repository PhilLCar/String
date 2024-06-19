#include <stdio.h>

#include <str.h>

int main(void)
{
  printf("Yé!\n");

  CHECK_MEMORY

  String *test = NEW (String) ("J'aime les patates!\n");

  CHECK_MEMORY

  Stream *s = fromString(test);

  while (1)
  {
    char c = sgetc(s);

    if (s->eos) break;

    printf("%c", c);
  }

  fflush(stdout);

  DELETE (test)

  DELETE (s);

  CHECK_MEMORY

  STOP_WATCHING

  return 0;
}