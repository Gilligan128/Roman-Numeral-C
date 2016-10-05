#include <stdlib.h>
#include <check.h>

#include "../src/subtraction.h"

START_TEST(subtracts_nothing)
{
  char result[4] = "";
  subtract_numerals(result, "1", "");
  ck_assert_str_eq("1", result);
}
END_TEST

TCase* subtraction_tests(void)
{
  TCase* subtraction = tcase_create("subtraction");
  tcase_add_test(subtraction, subtracts_nothing);
  return subtraction;
}

