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
  {"I", true},
  {"V", true},
  {"X", true},
  {"L", true},
  {"C", true},
  {"D", true},
  {"M", true},
  {"MDCLXVI", true},
  {"A", false},
  {"MAAAA", false}
};

START_TEST(must_be_valid_numeral)
{
  char error_message[40];
  bool actual = validate_numeral(error_message, validation_scenarios[_i].input);
  ck_assert(validation_scenarios[_i].expected == actual);
}
END_TEST

START_TEST(must_be_less_than_21_characters)
{ 
  char error_message[40];
  bool result = validate_numeral(error_message, "IIIIIIIIIIIIIIIIIIIII");
  ck_assert(!result);
}
END_TEST

START_TEST (too_short_buffer_results_in_error)
{     
  bool success = validate_buffer(80);
        
  ck_assert(!success);
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
