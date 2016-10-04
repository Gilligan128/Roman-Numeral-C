#include <stdlib.h>
#include "validate.h"


ValidationResult error(char* message)
{
  ValidationResult error = {1};
  return error;
}

const char numeral_digits[] = {
 'I',
 'V',
 'X',
 'L',
 'C',
 'D',
 'M'
};

ValidationResult validate_numeral(char* numeral)
{
  int i;
  for(i=0; i<7; i++)
  { 
    ValidationResult result = {0, ""};
    if(numeral[0] == numeral_digits[i])
      return result; 
  }
  return error("invalid numeral");
};
