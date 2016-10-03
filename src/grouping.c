#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "grouping.h"

typedef struct {
 char * group;
 char replacement;
} Replacement;

const Replacement groups[] = {
 {"VV", 'X'},
 {"IIIII", 'V'},
 {"XXXXX", 'L'},
 {"LL", 'C'},
 {"CCCCC", 'D'},
 {"DD", 'M'}
};

void combine_groups(char * numeral)
{ 
  int i;
  for(i=0;i<(sizeof(groups)/sizeof(Replacement));i++)
  {
    replace_group(numeral, groups[i]);
  }
}

void replace_group(char * numeral, Replacement group)
{
  while(1)
  { 
   char buffer[4096];
   char* location = strstr(numeral, group.group);
   
   if(!location)
     break;  
  
   strncpy(buffer, numeral, location-numeral);
   sprintf(buffer+(location-numeral), "%c%s", group.replacement, location + strlen(group.group)); 
   strcpy(numeral, buffer);
  }  
}

