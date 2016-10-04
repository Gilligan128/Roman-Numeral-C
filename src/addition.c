#include <stdlib.h>
#include <string.h>

#include "addition.h"
#include "sort.h"
#include "subtractives.h"
#include "grouping.h"

static const int MAX_NUMERAL = 20;
char* add_numerals(char * result,const char * firstNumeral, const char * secondNumeral)
{
   result[0] = '\0';
   
   char firstNumeralSubstituted[MAX_NUMERAL];
   char secondNumeralSubstituted[MAX_NUMERAL];
   strcpy(firstNumeralSubstituted, firstNumeral);
   strcpy(secondNumeralSubstituted, secondNumeral);
   
   substitute_out_subtractives(firstNumeralSubstituted);
   substitute_out_subtractives(secondNumeralSubstituted);

   strcat(result, firstNumeralSubstituted);
   strcat(result, secondNumeralSubstituted);
   sort_descending(result);
   combine_groups(result);
   substitute_in_subtractives(result);
   return result;
}


