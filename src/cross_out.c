#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "roman_string.h"
#include "grouping.h"
#include "sort.h"
#include "cross_out.h"

static bool cannot_cross_out_enough(int original_length, int current_length)
{
  return original_length == current_length;
}

void cross_out_numerals(char* numeral, char* what_to_cross_out)
{
   for(int i=0;i<strlen(what_to_cross_out);i++)
   {
      int original_length = 0;
      while(!strchr(numeral, what_to_cross_out[i]))
      {
        original_length = strlen(numeral);
        expand_smallest_group_greater_than(numeral, what_to_cross_out[i]);  
        if(cannot_cross_out_enough(original_length, strlen(numeral)))
        {
	         strcpy(numeral, "");
           return;
        }
      }
      replace_substring_once(numeral, (char[2]){what_to_cross_out[i], '\0'}, "");
   }	
} 
