#include <check.h>
#include "../src/validate.h"

typedef struct 
{
  char* input;
  int expected;
}InputExpectedPair;

const InputExpectedPair validation_scenarios[] = {
  {"I", 0},
  {"A", 1},
};

START_TEST(must_be_valid_numeral)
{
  ValidationResult actual = validate_numeral(validation_scenarios[_i].input);
  ck_assert_int_eq(validation_scenarios[_i].expected, actual.code);
}
END_TEST

TCase* validation_tests(void)
{
  TCase* validation = tcase_create("validation");
  tcase_add_loop_test(validation, must_be_valid_numeral, 0, sizeof(validation_scenarios)/sizeof(InputExpectedPair));
  return validation;
}
