#include "../list.h"
#include "list_test.h"

void print_status(Status status)
{
  if (status)
    printf("  ✅  ");
  else
    printf("  ❌  ");
}

void describe(Char_ptr message)
{
  static int test_number = 1;
  printf("%d => %s\n",test_number, message);
  test_number++;
}

void assert_equal(int actual, int expected, Char_ptr description)
{
  Status status = actual == expected;
  print_status(status);
  printf("%s\n", description);
}