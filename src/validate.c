#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "roman_math.h"
#include "constants.h"
#include "validate.h"


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

VALIDATION_RESULT validate_numeral(const char* numeral)
{
  if(strlen(numeral) > 20)
  {
    return INVALID;
  }

  int char_i;
  for(char_i=0;char_i<strlen(numeral);char_i++)
  {
   if(!is_numeral(numeral[char_i]))
   {
     return INVALID;
   } 
  }
  return SUCCESS;
}

bool validate_buffer(size_t buffer_length)
{
   return  MAX_COMBINED_NUMERAL_SIZE <= buffer_length;
}