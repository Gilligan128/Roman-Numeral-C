#include <check.h>
#include "../src/subtractives.h"

//since these tests will look really familiar to the grouping tests, I will start htem off as a loop test
//some of this is duplciated from grouping tests but, following the "Rule of 3",
//I won't merge the code until I have 3 instances of it so I know for sure its actual duplication.
typedef struct  {
 char* input;
 char* expected;
} InputExpectedPair;

const InputExpectedPair substitue_out_scenarios[] = {
  {"IV", "IIII"},
  {"IX", "VIIII"}
};

START_TEST(substitutes_out_properly)
{
  char buffer[4096];
  strcpy(buffer, substitue_out_scenarios[_i].input);
  substitute_out_subtractives(buffer);
  ck_assert_str_eq(substitue_out_scenarios[_i].expected, buffer);
}
END_TEST

TCase* subtractive_in_tests(void)
{
  TCase* subtractives = tcase_create("subtractives in");
  return subtractives;
}

TCase* subtractive_out_tests(void)
{
  TCase* subtractives = tcase_create("subtractives out");
  tcase_add_loop_test(subtractives, substitutes_out_properly, 0, sizeof(substitue_out_scenarios)/sizeof(InputExpectedPair));
  return subtractives;
}


