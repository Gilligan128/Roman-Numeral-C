#include <stdlib.h>

#include "cross_out.h"

void cross_out_numerals(char* numeral, char* what_to_cross_out)
{
  if(strcmp(numeral, what_to_cross_out) == 0)
    strcpy(numeral, "");
}
