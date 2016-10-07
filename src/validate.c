#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "validate.h"


ValidationResult error(char* message)
{
  ValidationResult error = {false, message};
  return error;
}

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

ValidationResult validate_numeral(char* numeral)
{
  ValidationResult result = {true, ""};
  if(strlen(numeral) > 20)
    return error("numeral too long");

  int char_i;
  for(char_i=0;char_i<strlen(numeral);char_i++)
  {
   if(!is_numeral(numeral[char_i]))
     return error("invalid numeral");
  }
  return result;
};
