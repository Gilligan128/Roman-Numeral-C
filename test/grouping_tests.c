#include <check.h>
#include "../src/grouping.h"

typedef struct  {
 char* input;
 char* expected;
} GroupingScenario;

const GroupingScenario grouping_scenarios[] = 
{
  {"", ""},
  {"VV", "X"},
  {"VVII", "XII"},
  {"VVVV", "XX"},
  {"IIIII", "V"},
  {"XXXXX", "L"},
  {"LL", "C"},
  {"CCCCC", "D"},
  {"DD", "M"}
};

START_TEST(groups_properly)
{
  char buffer[10];
  strcpy(buffer, grouping_scenarios[_i].input);
  combine_groups(buffer);
  ck_assert_str_eq(grouping_scenarios[_i].expected, buffer);
}
END_TEST

START_TEST(groups_in_correct_order_of_precedence)
{
  char inputOutput[] = "DCCCCLXXXXVIIIII";
  combine_groups(inputOutput);
  ck_assert_str_eq("M",inputOutput);
}
END_TEST

typedef struct 
{
  char* numeral;
  char group;
  char* expected;
}ExpansionScenario;

static const ExpansionScenario expansion_scenarios[] = 
{
  {"", 'I', ""},
  {"V", 'I', "IIIII"},
  {"X", 'I', "VV"},
  {"XV", 'I', "XIIIII"},
  {"XV", 'V', "VVV"}
};

START_TEST(expands_groups)
{ 
  char buffer[10];
  strcpy(buffer, expansion_scenarios[_i].numeral);
  expand_smallest_numeral_greater_than_currrent_numeral(buffer, expansion_scenarios[_i].group);
  ck_assert_str_eq(expansion_scenarios[_i].expected, buffer);
}
END_TEST

TCase* grouping_tests(void)
{
  TCase* grouping = tcase_create("grouping");
  tcase_add_loop_test(grouping, groups_properly, 0, sizeof(grouping_scenarios)/sizeof(GroupingScenario));
  tcase_add_test(grouping, groups_in_correct_order_of_precedence);
  tcase_add_loop_test(grouping, expands_groups, 0, sizeof(expansion_scenarios)/sizeof(ExpansionScenario));
  return grouping;
}
