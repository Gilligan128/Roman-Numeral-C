//Public API for Roman arithmetic
#ifndef ROMAN_MATH
#define ROMAN_MATH

#include <stdbool.h>

typedef struct
{
  bool success;
  char* message;
} ValidationResult;

ValidationResult validate_numeral(char* numeral);
void add_numerals(char * result, const char * firstNumeral, const char * secondNumeral);
void subtract_numerals(char* result, const char* first_numeral, const char* second_numeral);

#endif
