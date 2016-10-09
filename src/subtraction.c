#include <stdlib.h>
#include <string.h>

#include "sort.h"
#include "subtractives.h"
#include "cross_out.h"
#include "roman_math.h"
#include "constants.h"

void subtract_numerals(char* result,size_t result_length, const char* first_numeral, const char* second_numeral)
{
  if(!validate_buffer(result))
    return;
  result[0] = '\0';
  char first_numeral_substituted[MAX_NUMERAL_SIZE];
  char second_numeral_substituted[MAX_NUMERAL_SIZE];
  strcpy(first_numeral_substituted, first_numeral);
  strcpy(second_numeral_substituted, second_numeral);
  
  substitute_out_subtractives(first_numeral_substituted);
  substitute_out_subtractives(second_numeral_substituted);
  strcat(result, first_numeral_substituted);
  cross_out_numerals(result, second_numeral_substituted);
  sort_descending(result);
  substitute_in_subtractives(result);
}
