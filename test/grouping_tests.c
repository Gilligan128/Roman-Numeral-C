#include <check.h>
#include "../src/grouping.h"

START_TEST(groups_VV_into_X)
{
   char inputOutput[] = "VV";
   combine_groups(inputOutput);
   ck_assert_str_eq("X", inputOutput);
}
END_TEST

TCase* grouping_tests(void)
{
  TCase* grouping = tcase_create("grouping");
  tcase_add_test(grouping, groups_VV_into_X);
  return grouping;
}
