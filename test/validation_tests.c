#include <check.h>
#include <stdbool.h>

#include "../src/roman_math.h"

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
  ValidationResult actual = validate_numeral(validation_scenarios[_i].input);
  ck_assert(validation_scenarios[_i].expected == actual.success);
}
END_TEST

START_TEST(must_be_less_than_20_characters)
{ 
  ValidationResult actual = validate_numeral("IIIIIIIIIIIIIIIIIIIII");
  ck_assert(!actual.success);
}
END_TEST

TCase* validation_tests(void)
{
  TCase* validation = tcase_create("validation");
  tcase_add_loop_test(validation, must_be_valid_numeral, 0, sizeof(validation_scenarios)/sizeof(InputExpectedPair));
  tcase_add_test(validation, must_be_less_than_20_characters);
  return validation;
}
