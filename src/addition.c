#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "roman_math.h"
#include "sort.h"
#include "subtractives.h"
#include "grouping.h"


void add_numerals(char* result,size_t result_length, const char * first_numeral, const char * second_numeral)
{
   const int MAX_NUMERAL = 20;
   
   if(result_length < 81)
   {
       sprintf(result, "%s", "Buffer must be 81+ size", result_length);
       return;
   }

   char first_numeral_substituted[MAX_NUMERAL];
   char second_numeral_substituted[MAX_NUMERAL];
   strcpy(first_numeral_substituted, first_numeral);
   strcpy(second_numeral_substituted, second_numeral);
   
   substitute_out_subtractives(first_numeral_substituted);
   substitute_out_subtractives(second_numeral_substituted);
   strcpy(result, first_numeral_substituted);
   strcat(result, second_numeral_substituted);
   sort_descending(result);
   combine_groups(result);
   substitute_in_subtractives(result);
   return result;
}


