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

static bool is_character_a_numeral(char numeral_candidate)
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

static bool is_not_a_numeral(const char* numeral_candidate)
{
  for(int char_i=0;char_i<strlen(numeral_candidate);char_i++)
  {
   if(!is_character_a_numeral(numeral_candidate[char_i]))
   {
     return true;
   } 
  }
  return false;
}

static bool is_too_long(const char* numeral_candidate)
{
  return strlen(numeral_candidate) > 20;
}

static bool is_more_than_3_per_IXCM(const char* numeral_candidate)
{
  int count = 0;
   for(int i=0; i<strlen(numeral_candidate); i++)
   {
     if(numeral_candidate[i] == 'I')
       count++;
     if(count > 3)
       return true;
   }
   return false;
}

ValidationResult validate_numeral(const char* numeral_candidate)
{
  if(is_too_long(numeral_candidate))
    return TOO_LONG;

  if(is_not_a_numeral(numeral_candidate)) 
     return NOT_A_NUMERAL;

  if(is_more_than_3_per_IXCM(numeral_candidate))
    return MORE_THAN_3_PER_IXCM;
  return SUCCESS;
}

bool validate_buffer(size_t buffer_length)
{
   return  MAX_COMBINED_NUMERAL_SIZE <= buffer_length;
}