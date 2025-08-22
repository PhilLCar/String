#include <stdio.h>

#include <str.h>
#include <print.h>

//__declspec(allocate("virtual$1")) const VirtualTable vt = {};

int main(void)
{
  String *ok = NEW (String) ("Allo!");

  // Those two lines must give the same outptu
  printf("Je dis: %8s %d %E\n", "Allo!", 1, .45);
  print("Je dis: %+8Of %d %E\n", ok, 1, .45);

  printf("Yeah!\n");

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