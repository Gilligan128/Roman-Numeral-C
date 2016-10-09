//Public API for Roman arithmetic
#ifndef ROMAN_MATH
#define ROMAN_MATH

#include <stdbool.h>

//it is recommended to validate inputs with this before any other function use.
bool validate_numeral(const char* numeral);
//assumes inputs already validated with validate_numeral().
void add_numerals(char * result, size_t result_length, const char * firstNumeral, const char * secondNumeral);
//assumes inputs already validated with validate_numeral().
void subtract_numerals(char* result, size_t result_length, const char* first_numeral, const char* second_numeral);

#endif
