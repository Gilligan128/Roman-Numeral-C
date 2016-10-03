#include <check.h>
#include <stdlib.h>

#include "roman_test_cases.h"


Suite * roman_numeral_suite(void)
{
    Suite *s;
    s = suite_create("roman-numeral");
    suite_add_tcase(s, addition_tests());
    suite_add_tcase(s, sort_tests());	
    suite_add_tcase(s, grouping_tests());
    suite_add_tcase(s, subtractive_tests());
    return s;
}


int main(int arg1, char** arg2)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = roman_numeral_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
