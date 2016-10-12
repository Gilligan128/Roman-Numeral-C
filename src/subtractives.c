#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "roman_string.h"
#include "subtractives.h"

typedef struct
{
  char *contracted;
  char *expanded;
} Subtractive;

const Subtractive subtractives[] = {
    {"CM", "DCCCC"},
    {"CD", "CCCC"},
    {"XC", "LXXXX"},
    {"XL", "XXXX"},
    {"IX", "VIIII"},
    {"IV", "IIII"},
};

static int subtractive_count()
{
  return sizeof(subtractives) / sizeof(Subtractive);
}

void substitute_out_subtractives(char *numeral)
{
  for (int i = 0; i < subtractive_count(); i++)
  {
    replace_substring(numeral, subtractives[i].contracted, subtractives[i].expanded);
  }
}

void substitute_in_subtractives(char *numeral)
{
  for (int i = 0; i < subtractive_count(); i++)
  {
    replace_substring(numeral, subtractives[i].expanded, subtractives[i].contracted);
  }
}

void remove_subtractives(char *numeral)
{
  for (int i = 0; i < subtractive_count(); i++)
  {
    replace_substring(numeral, subtractives[i].contracted, "");
  }
}