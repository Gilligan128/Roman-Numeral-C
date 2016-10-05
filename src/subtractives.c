#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "roman_string.h"
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

void substitute_out_subtractives(char * numeral)
{
  int i;
  for(i=0; i<sizeof(subtractives)/sizeof(Subtractive);i++)
  {
    replace_substring(numeral, subtractives[i].contracted, subtractives[i].expanded);
  }
}

void substitute_in_subtractives(char * numeral)
{
  int i;
  for(i=0; i<sizeof(subtractives)/sizeof(Subtractive);i++)
  {
    replace_substring(numeral, subtractives[i].expanded, subtractives[i].contracted);
  }
}
