#include <stdlib.h>
#include <string.h>
#include "sort.h"

static char NumeralSorts[] = {  //is this cheating?
  'I',
  'V',
  'X',
  'L',
  'C',
  'D',
  'M'
};

static int find_sort_order(char numeral)
{
  int i;
  for(i=0; i< sizeof(NumeralSorts); i++)
  {
    if(NumeralSorts[i] == numeral)
	return i;
  }
  return 0;
}

static int compare_numeral_descending(const void * a, const void * b)
{
  const char firstNumeral = *(const char *)a;
  const char secondNumeral = *(const char *)b;
  
  return find_sort_order(secondNumeral) - find_sort_order(firstNumeral);
}

void sort_descending(char numeral[])
{
  qsort(numeral, strlen(numeral), sizeof(char), compare_numeral_descending);
}




