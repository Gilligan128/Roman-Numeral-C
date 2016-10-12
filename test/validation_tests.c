#include <check.h>
#include <stdbool.h>

#include "../src/roman_math.h"
#include "../src/validate.h"

typedef struct
{
  char *input;
  ValidationResult expected;
} ValidationScenario;

const ValidationScenario valid_numeral_scenarios[] = {
    {"I", SUCCESS},
    {"V", SUCCESS},
    {"X", SUCCESS},
    {"L", SUCCESS},
    {"C", SUCCESS},
    {"D", SUCCESS},
    {"M", SUCCESS},
    {"MDCLXVI", SUCCESS},
    {"A", NOT_A_NUMERAL},
    {"MAAAA", NOT_A_NUMERAL}};

START_TEST(must_be_valid_numeral)
{
  ValidationResult result = validate_numeral(valid_numeral_scenarios[_i].input);
  ck_assert_int_eq(result, valid_numeral_scenarios[_i].expected);
}
END_TEST

START_TEST(too_short_buffer_results_in_error)
{
  bool success = validate_buffer(41);

  ck_assert(!success);
}
END_TEST

const char *less_than_or_equal_to_3_scenarios[] = {
    "IIII",
    "IIIII",
    "XXXX",
    "CCCC",
    "MMMM"};
START_TEST(must_have_3_or_less_per_digit)
ValidationResult result = validate_numeral(less_than_or_equal_to_3_scenarios[_i]);
ck_assert_int_eq(result, MORE_THAN_3_PER_IXCM);
END_TEST

const char *only_1_scenarios[] = {
    "VV",
    "VVV",
    "LL",
    "DD"};
START_TEST(must_have_only_1_per_digit)
{
  ValidationResult result = validate_numeral(only_1_scenarios[_i]);
  ck_assert_int_eq(result, MORE_THAN_1_PER_VLD);
}
END_TEST

TCase *validation_tests(void)
{
  size_t scenario_size = sizeof(ValidationScenario);
  size_t string_size = sizeof(char *);
  TCase *validation = tcase_create("numeral validation");
  tcase_add_loop_test(validation, must_be_valid_numeral, 0, sizeof(valid_numeral_scenarios) / scenario_size);
  tcase_add_test(validation, too_short_buffer_results_in_error);
  tcase_add_loop_test(validation, must_have_3_or_less_per_digit, 0, sizeof(less_than_or_equal_to_3_scenarios) / string_size);
  tcase_add_loop_test(validation, must_have_only_1_per_digit, 0, sizeof(only_1_scenarios) / string_size);
  return validation;
}
