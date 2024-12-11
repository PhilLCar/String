#include <stdio.h>

#include <str.h>
#include <print.h>

int main(void)
{
  String *ok = NEW (String) ("Allo!");

  print("Je dis: %Of %d %E\n", ok, 1, .45);

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

  DELETE (test);

  CHECK_MEMORY

  STOP_WATCHING

  return 0;
}