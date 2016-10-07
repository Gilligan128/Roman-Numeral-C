#include <stdlib.h>
#include <check.h>

#include "../src/roman_math.h"

START_TEST(subtracts_nothing)
{
  char result[4] = "";
  subtract_numerals(result, "I", "");
  ck_assert_str_eq("I", result);
}
END_TEST

START_TEST(subtracts_complex_numeral)
{
  char result[20] = "";
  subtract_numerals(result, "CXXIX", "XLIII");
  ck_assert_str_eq("LXXVI", result);
}
END_TEST

TCase* subtraction_tests(void)
{
  TCase* subtraction = tcase_create("subtraction");
  tcase_add_test(subtraction, subtracts_nothing);
  return subtraction;
}

