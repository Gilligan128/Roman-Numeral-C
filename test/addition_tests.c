#include <check.h>
#include "addition_tests.h"
#include "../src/addition.h"

START_TEST (adds_simple_numeral_to_nothing)
{
 	//at this point I realize I have no idea how to do test doubles in C.
	//but lets see how much trouble I get into.
        char result[100];
        result[0] = '\0';

	add_numerals(result, "I","");

	ck_assert_str_eq(result, "I");
}
END_TEST




TCase *addition_tests()
{
  TCase *additionCase = tcase_create("addition");
  tcase_add_test(additionCase, adds_simple_numeral_to_nothing);	
  return additionCase;
}



