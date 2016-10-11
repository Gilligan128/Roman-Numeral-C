//Public API for Roman arithmetic
#ifndef ROMAN_MATH
#define ROMAN_MATH

#include <stdbool.h>

//it is recommended to validate inputs with this before any other function use.
bool validate_numeral(const char* numeral);

//PRECONDITION: buffer size is at least 42 bytes.
//PRECONDITION: inputs have already been validated via validate_numerals()
void add_numerals(char * result, size_t result_length, const char * firstNumeral, const char * secondNumeral);

//PRECONDITION: buffer size is at least 42 bytes.
//PRECONDITION: inputs have already been validated via validate_numerals()
void subtract_numerals(char* result, size_t result_length, const char* first_numeral, const char* second_numeral);

#endif
