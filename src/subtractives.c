#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subtractives.h"

typedef struct {
  char* contracted;
  char* expanded;
}Subtractive;

const Subtractive subtractives[] = {
  {"CM", "DCCCC"},
  {"CD", "CCCC"},  
  {"XC", "LXXXX"},
  {"XL", "XXXX"},
  {"IX", "VIIII"},
  {"IV", "IIII"},
};

void substitute_string(char * numeral, const char* needle, const char* replacement)
{
  while(1) 
  {
    char buffer[4096];
    char* location = strstr(numeral,needle);
   
    if(!location)
      break;  

    strncpy(buffer, numeral, location-numeral);
    sprintf(buffer+(location-numeral), "%s%s", replacement, location + strlen(needle)); 
    strcpy(numeral, buffer);
  }
}

void substitute_out_subtractives(char * numeral)
{
  int i;
  for(i=0; i<sizeof(subtractives)/sizeof(Subtractive);i++)
  {
    substitute_string(numeral, subtractives[i].contracted, subtractives[i].expanded);
  }
}

void substitute_in_subtractives(char * numeral)
{
  int i;
  for(i=0; i<sizeof(subtractives)/sizeof(Subtractive);i++)
  {
    substitute_string(numeral, subtractives[i].expanded, subtractives[i].contracted);
  }
}
