#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "roman_string.h"
#include "grouping.h"

typedef struct {
 char* expanded;
 char* combined;
} NumeralGroup;

static const NumeralGroup groups[] = {
 {"IIIII", "V"},
 {"VV", "X"},
 {"XXXXX", "L"},
 {"LL", "C"},
 {"CCCCC", "D"},
 {"DD", "M"}
};


void combine_groups(char * numeral)
{ 
  int i;
  for(i=0;i<(sizeof(groups)/sizeof(NumeralGroup));i++)
  {
   replace_substring(numeral, groups[i].expanded, groups[i].combined);
  }
}

void expand_next_smallest_group(char* numeral)
{  
   if(strlen(numeral) == 0)
     return;
   
   char buffer[40];
   for(int i=0;i<6;i++)
   {
     if(strstr(numeral, groups[i].combined))
     {
      replace_substring_once(numeral, groups[i].combined, groups[i].expanded);
      break;
     }
   }
}





