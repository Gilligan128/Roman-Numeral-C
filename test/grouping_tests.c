#include <check.h>
#include "../src/grouping.h"

typedef struct  {
 char* input;
 char* expected;
} InputExpectedPair;

const InputExpectedPair scenarios[] = 
{
  {"", ""},
  {"VV", "X"},
  {"VVII", "XII"},
  {"VVVV", "XX"}
};

START_TEST(groups_properly)
{
  char buffer[4096];
  strcpy(buffer, scenarios[_i].input);
  combine_groups(buffer);
  ck_assert_str_eq(scenarios[_i].expected, buffer);
}
END_TEST


TCase* grouping_tests(void)
{
  TCase* grouping = tcase_create("grouping");
  tcase_add_loop_test(grouping, groups_properly, 0, sizeof(scenarios)/sizeof(InputExpectedPair));
  return grouping;
}
