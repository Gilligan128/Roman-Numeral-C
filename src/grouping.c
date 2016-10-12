#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "roman_string.h"
#include "grouping.h"

typedef struct
{
  char *expanded;
  char *combined;
} NumeralGroup;

static const NumeralGroup groups[] = {
    {"IIIII", "V"},
    {"VV", "X"},
    {"XXXXX", "L"},
    {"LL", "C"},
    {"CCCCC", "D"},
    {"DD", "M"}};

void combine_groups(char *numeral)
{
  int i;
  for (i = 0; i < (sizeof(groups) / sizeof(NumeralGroup)); i++)
  {
    replace_substring(numeral, groups[i].expanded, groups[i].combined);
  }
}

void expand_smallest_numeral_greater_than_currrent_numeral(char *numeral, char numeral_to_be_greater_than)
{
  if (strlen(numeral) == 0)
    return;

  bool is_greater_than_group = false;
  if (numeral_to_be_greater_than == 'I')
    is_greater_than_group = true;

  for (int i = 0; i < 6; i++)
  {
    if (strstr(numeral, groups[i].combined) && is_greater_than_group)
    {
      replace_substring_once(numeral, groups[i].combined, groups[i].expanded);
      break;
    }

    if (groups[i].combined[0] == numeral_to_be_greater_than)
      is_greater_than_group = true;
  }
}
