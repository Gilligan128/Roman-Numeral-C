#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "roman_string.h"
#include "grouping.h"

typedef struct {
 char * group;
 char replacement;
} Replacement;

const Replacement groups[] = {
 {"IIIII", 'V'},
 {"VV", 'X'},
 {"XXXXX", 'L'},
 {"LL", 'C'},
 {"CCCCC", 'D'},
 {"DD", 'M'}
};

void replace_group(char * numeral, Replacement group)
{
  replace_substring(numeral, group.group, (char[2]){group.replacement, '\0'});
}

void combine_groups(char * numeral)
{ 
  int i;
  for(i=0;i<(sizeof(groups)/sizeof(Replacement));i++)
  {
    replace_group(numeral, groups[i]);
  }
}



