#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subtractives.h"

typedef struct {
  char* contracted;
  char* expanded;
}Subtractive;

const Subtractive subtractives[] = {
  {"IX", "VIIII"},
  {"IV", "IIII"},
  {"XL", "XXXX"},
  {"XC", "LXXXX"},
  {"CD", "CCCC"},
  {"CM", "DCCCC"}
};

void substitute_out_subtractive(char * numeral, Subtractive subtractive)
{
  char buffer[4096];
  char* location = strstr(numeral, subtractive.contracted);
   
  if(!location)
    return;  

  strncpy(buffer, numeral, location-numeral);
  sprintf(buffer+(location-numeral), "%s%s", subtractive.expanded, location + strlen(subtractive.contracted)); 
  strcpy(numeral, buffer);
}

void substitute_out_subtractives(char * numeral)
{
  int i;
  for(i=0; i<sizeof(subtractives)/sizeof(Subtractive);i++)
  {
    substitute_out_subtractive(numeral, subtractives[i]);
  }
}

void substitute_in_subtractives(char * numeral)
{
  
}
