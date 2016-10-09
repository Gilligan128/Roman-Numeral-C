#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "roman_math.h"
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

bool validate_numeral(const char* numeral)
{
  if(strlen(numeral) > 20)
  {
    fprintf(stderr, "VALIDATION ERROR: numeral too long\n");
    return false;
  }

  int char_i;
  for(char_i=0;char_i<strlen(numeral);char_i++)
  {
   if(!is_numeral(numeral[char_i]))
   {
     fprintf(stderr,"VALIDATION ERROR: invalid numeral\n");
     return false;
   } 
  }
  return true;
}

bool validate_buffer(size_t buffer_length)
{
   if(buffer_length < 81)
   {
       fprintf(stderr, "ERROR: Buffer must be 81+ size", buffer_length);
       return false; 
   }
   return true;
}