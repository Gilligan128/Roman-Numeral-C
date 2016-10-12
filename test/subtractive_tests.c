#include <check.h>
#include <stdbool.h>

#include "../src/subtractives.h"
#include "../src/constants.h"

typedef struct
{
  char *input;
  char *expected;
} InputExpectedPair;

const InputExpectedPair substitute_out_scenarios[] = {
    {"IV", "IIII"},
    {"IX", "VIIII"},
    {"XL", "XXXX"},
    {"XC", "LXXXX"},
    {"CD", "CCCC"},
    {"CM", "DCCCC"},
    {"IVIV", "IIIIIIII"}};

START_TEST(substitutes_out_properly)
{
  char buffer[10];
  strcpy(buffer, substitute_out_scenarios[_i].input);
  substitute_out_subtractives(buffer);
  ck_assert_str_eq(buffer, substitute_out_scenarios[_i].expected);
}
END_TEST

const InputExpectedPair substitute_in_scenarios[] = {
    {"IIII", "IV"},
    {"VIIII", "IX"},
    {"XXXX", "XL"},
    {"LXXXX", "XC"},
    {"CCCC", "CD"},
    {"DCCCC", "CM"},
    {"DCCCCCCCC", "CMCD"}};
START_TEST(substitutes_in_properly)
{
  char buffer[MAX_COMBINED_NUMERAL_SIZE];
  strcpy(buffer, substitute_in_scenarios[_i].input);
  substitute_in_subtractives(buffer);
  ck_assert_str_eq(buffer, substitute_in_scenarios[_i].expected);
}
END_TEST

const InputExpectedPair subtractive_scenarios[] = {
    {"IV", ""}};
START_TEST(removes_subtractives)
{
  char buffer[MAX_COMBINED_NUMERAL_SIZE];
  strcpy(buffer, subtractive_scenarios[_i].input);
  remove_subtractives(buffer);
  ck_assert_str_eq(buffer, subtractive_scenarios[_i].expected);
}
END_TEST

TCase *subtractive_tests(void)
{
  TCase *subtractives = tcase_create("subtractives out");
  size_t input_expected_len = sizeof(InputExpectedPair);
  tcase_add_loop_test(subtractives, substitutes_out_properly, 0, sizeof(substitute_out_scenarios) / input_expected_len);
  tcase_add_loop_test(subtractives, substitutes_in_properly, 0, sizeof(substitute_in_scenarios) / input_expected_len);
  tcase_add_loop_test(subtractives, removes_subtractives, 0, sizeof(subtractive_scenarios) / input_expected_len);
  return subtractives;
}
