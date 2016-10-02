#include <stdlib.h>
#include <string.h>
#include "sort.h"

typedef struct 
{
  int sortValue;
  char numeral;
}
NumeralSort;

static NumeralSort NumeralSorts[] = {
 { 0, 'I'},
 {1, 'V'},
 {2, 'X'},
 {3, 'L'},
 {4, 'C'},
 {5, 'D'},
 {6, 'M'}
};

static int find_sort_order(char numeral)
{
  int i;
  for(i=0; i< sizeof(NumeralSorts)/sizeof(NumeralSort); i++)
  {
    if(NumeralSorts[i].numeral == numeral)
	return NumeralSorts[i].sortValue;
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


