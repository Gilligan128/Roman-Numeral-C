//Public API for Roman arithmetic
#ifndef ROMAN_MATH
#define ROMAN_MATH

#include <stdbool.h>

bool validate_numeral(char* potential_error_message, const char* numeral);
//result must be a null-terminating buffer.
void add_numerals(char * result, size_t result_length, const char * firstNumeral, const char * secondNumeral);
//result must be a null-terminating buffer.
void subtract_numerals(char* result, size_t result_length, const char* first_numeral, const char* second_numeral);

#endif
