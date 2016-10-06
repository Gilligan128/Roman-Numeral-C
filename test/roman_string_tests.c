#include <check.h>

#include "../src/roman_string.h"

START_TEST(replace_empty_string_does_nothing)
{
  char inputOutput[] = "stuff";
  replace_substring(inputOutput, "", "s");
  ck_assert_str_eq("stuff", inputOutput);
}
END_TEST

TCase* roman_string_tests(void)
{
  TCase* roman_string = tcase_create("string");
  tcase_add_test(roman_string, replace_empty_string_does_nothing);
  return roman_string;
}
