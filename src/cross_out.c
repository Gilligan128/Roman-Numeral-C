#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "roman_string.h"
#include "grouping.h"
#include "cross_out.h"

void cross_out_numerals(char* numeral, char* what_to_cross_out)
{
   for(int i=0;i<strlen(what_to_cross_out);i++)
   {
      int original_length = 0;
      while(!strchr(numeral, what_to_cross_out[i]) && strlen(numeral) != original_length)
      {
        original_length = strlen(numeral);
        expand_group(numeral, 0);  
      }
      replace_substring_once(numeral, (char[2]){what_to_cross_out[i], '\0'}, "");
   }	
} 
