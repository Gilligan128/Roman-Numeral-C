#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subtractives.h"

typedef struct {
  char* contracted;
  char* expanded;
}Subtractive;

void substitute_out_subtractives(char * numeral)
{
  Subtractive subtractive = { "IV", "IIII"};
  char buffer[4096];
  char* location = strstr(numeral, subtractive.contracted);
   
  if(!location)
    return;  

  strncpy(buffer, numeral, location-numeral);
  sprintf(buffer+(location-numeral), "%s%s", subtractive.expanded, location + strlen(subtractive.contracted)); 
  strcpy(numeral, buffer);
}

void substitute_in_subtractives(char * numeral)
{

}
