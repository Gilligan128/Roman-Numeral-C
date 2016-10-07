#include <check.h>

#include "../src/cross_out.h"

typedef struct  {
 char* input;
 char* to_cross_out;
 char* expected;
} CrossOutScenario;

static const CrossOutScenario cross_out_scenarios[] = {
  {"I", "I", ""},
  {"I", "II", ""},
  {"II", "I", "I"},
  {"V", "I", "IIII"},
  //{"VV", "I", "VIIII"}
};

START_TEST(crosses_out_properly)
{
  char buffer[40];
  strcpy(buffer, cross_out_scenarios[_i].input);
  cross_out_numerals(buffer, cross_out_scenarios[_i].to_cross_out);
  ck_assert_str_eq(cross_out_scenarios[_i].expected, buffer);
}
END_TEST

TCase* cross_out_tests(void)
{
  TCase* cross_out = tcase_create("cross out");
  tcase_add_loop_test(cross_out, crosses_out_properly, 0, sizeof(cross_out_scenarios)/sizeof(CrossOutScenario));
  return cross_out;
}
