#include <check.h>

#include "../src/sort.h"

START_TEST(sorts_a_reversed_numeral)
{
   char inputOutput[] = "IVXLCDM";
   sort_descending(inputOutput);
   ck_assert_str_eq("MDCLXVI", inputOutput);	
}
END_TEST

START_TEST(sorts_a_muddled_numeral)
{
   char inputOutput[] = "MMLXCVDI";
   sort_descending(inputOutput);
   ck_assert_str_eq("MMDCLXVI", inputOutput);	
}
END_TEST

TCase* sort_tests(void)
{
  TCase* sorting = tcase_create("sorting");
  tcase_add_test(sorting, sorts_a_reversed_numeral);
  tcase_add_test(sorting, sorts_a_muddled_numeral);
  return sorting;
}
