#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "roman_math.h"

static const char numeral_digits[] = {
 'I',
 'V',
 'X',
 'L',
 'C',
 'D',
 'M'
};

static bool is_numeral(char numeral_candidate)
{
   int i; 
   for(i=0; i<7; i++)
   { 
     if(numeral_candidate == numeral_digits[i])
     {
       return true;
     } 
   }
   return false;
}

bool validate_numeral(char* potential_error_message, char* numeral)
{
  size_t buffer_length = strlen(potential_error_message);
  if(strlen(numeral) > 20)
  {
     snprintf(potential_error_message, buffer_length, "%s",  "numeral too long");
    return false;
  }

  int char_i;
  for(char_i=0;char_i<strlen(numeral);char_i++)
  {
   if(!is_numeral(numeral[char_i]))
   {
     snprintf(potential_error_message, buffer_length, "%s", "invalid numeral");
     return false;
   } 
  }
  return true;
}
