#include <check.h>

#include "../src/sort.h"

START_TEST(reverses_a_numeral)
{
   char* inputOutput = "MLCDXVI";
   sort_descending(inputOutput);
   check_assert_str_eq("IVXDCLM", inputOutput);	
}
END_TEST

TCase* sortTests(void)
{
  TCase* sorting = tcase_create("sorting");
 // tcase_add_test(sorting, reverses_a_numeral);
  return sorting;
}
