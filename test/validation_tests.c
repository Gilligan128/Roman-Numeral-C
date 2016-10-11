#include <check.h>
#include <stdbool.h>

#include "../src/roman_math.h"
#include "../src/validate.h"

typedef struct 
{
  char* input;
  bool expected;
}InputExpectedPair;

const InputExpectedPair validation_scenarios[] = {
  {"I", SUCCESS},
  {"V", SUCCESS},
  {"X", SUCCESS},
  {"L", SUCCESS},
  {"C", SUCCESS},
  {"D", SUCCESS},
  {"M", SUCCESS},
  {"MDCLXVI", SUCCESS},
  {"A", INVALID},
  {"MAAAA", INVALID}
};

START_TEST(must_be_valid_numeral)
{
  VALIDATION_RESULT actual = validate_numeral(validation_scenarios[_i].input);
  ck_assert_int_eq(actual, validation_scenarios[_i].expected);
}
END_TEST

START_TEST(must_be_less_than_21_characters)
{ 
  VALIDATION_RESULT result = validate_numeral("IIIIIIIIIIIIIIIIIIIII");
  ck_assert(result != SUCCESS);
}
END_TEST

START_TEST (too_short_buffer_results_in_error)
{     
  VALIDATION_RESULT success = validate_buffer(41);
        
  ck_assert_int_eq(success,SUCCESS);
}
END_TEST


TCase* validation_tests(void)
{
  TCase* validation = tcase_create("numeral validation");
  tcase_add_loop_test(validation, must_be_valid_numeral, 0, sizeof(validation_scenarios)/sizeof(InputExpectedPair));
  tcase_add_test(validation, must_be_less_than_21_characters);
  tcase_add_test(validation, too_short_buffer_results_in_error);
  return validation;
}
