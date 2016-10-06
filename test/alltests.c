#include <check.h>
#include <stdlib.h>

#include "roman_test_cases.h"

Suite * acceptance_suite(void)
{
  Suite *s;
  s = suite_create("acceptance");
  suite_add_tcase(s, addition_tests());
  suite_add_tcase(s, subtraction_tests());
  return s;
}

Suite * unit_suite(void)
{
    Suite *s;
    s = suite_create("unit");
  
    suite_add_tcase(s, sort_tests());	
    suite_add_tcase(s, grouping_tests());
    suite_add_tcase(s, subtractive_tests());
    suite_add_tcase(s, validation_tests());
    suite_add_tcase(s, cross_out_tests());
    suite_add_tcase(s, roman_string_tests());
    return s;
}

int main(int arg1, char** arg2)
{
    int number_failed;
    SRunner *sr;

    sr = srunner_create(unit_suite());
    srunner_add_suite(sr, acceptance_suite());  

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
