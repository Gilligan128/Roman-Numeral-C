#include <stdlib.h>
#include <string.h>
#include "sort.h"

static int compare_numeral(const void * a, const void * b)
{
  const char firstNumeral = (const char )a;
  const char secondNumeral = (const char )b;

  return 1;
}

void sort_descending(char * numeral)
{
  qsort(numeral, strlen(numeral), sizeof(char), compare_numeral);
}


