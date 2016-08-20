#include <check.h>

#include "addition_tests.h"

START_TEST (first_test)
{
  ck_abort_msg("though this seems a failure, it means you are wired up! congrats!");
}
END_TEST


TCase *addition_tests()
{
  TCase *additionCase = tcase_create("addition");
  tcase_add_test(additionCase, first_test);	
  return additionCase;
}



