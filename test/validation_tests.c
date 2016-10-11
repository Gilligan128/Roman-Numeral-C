#include <check.h>
#include <stdbool.h>

#include "../src/roman_math.h"
#include "../src/validate.h"

typedef struct 
{
  char* input;
  ValidationResult expected;
}ValidationScenario;

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
  {"MAAAA", NOT_A_NUMERAL}
};

START_TEST(must_be_valid_numeral)
{
  ValidationResult result = validate_numeral(valid_numeral_scenarios[_i].input);
  ck_assert_int_eq(result, valid_numeral_scenarios[_i].expected);
}
END_TEST

START_TEST(must_be_less_than_21_characters)
{ 
  ValidationResult result = validate_numeral("IIIIIIIIIIIIIIIIIIIII");
  ck_assert_int_eq(result, TOO_LONG);
}
END_TEST

START_TEST (too_short_buffer_results_in_error)
{     
  bool success = validate_buffer(41);
        
  ck_assert(!success);
}
END_TEST

const ValidationScenario less_than_3_scenarios[] = {
 // {"IIII", MORE_THAN_3}
};

START_TEST (must_have_3_or_less_of_the_same_numerals)
  ValidationResult result = validate_numeral(less_than_3_scenarios[_i].input);
  ck_assert_int_eq(result, less_than_3_scenarios[_i].expected);
END_TEST


TCase* validation_tests(void)
{
  size_t scenario_size = sizeof(ValidationScenario);
  TCase* validation = tcase_create("numeral validation");
  tcase_add_loop_test(validation, must_be_valid_numeral, 0, sizeof(valid_numeral_scenarios)/scenario_size);
  tcase_add_test(validation, must_be_less_than_21_characters);
  tcase_add_test(validation, too_short_buffer_results_in_error);
 // tcase_add_loop_test(validation, must_have_3_or_less_of_the_same_numerals, 0, sizeof(less_than_3_scenarios)/scenario_size);
  return validation;
}
