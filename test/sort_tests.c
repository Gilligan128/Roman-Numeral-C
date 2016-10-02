#include <check.h>

#include "../src/sort.h"

START_TEST(reverses_a_numeral)
{
   const char* numeral_reference = "IVXLCDM"; //so I don't forget all the numerals
   char inputOutput[] = "MDCLXVI";
   sort_descending(inputOutput);
   ck_assert_str_eq("IVXLCDM", inputOutput);	
}
END_TEST

TCase* sort_tests(void)
{
  TCase* sorting = tcase_create("sorting");
  tcase_add_test(sorting, reverses_a_numeral);
  return sorting;
}
