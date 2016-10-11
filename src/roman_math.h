//Public API for Roman arithmetic
#ifndef ROMAN_MATH
#define ROMAN_MATH

#include <stdbool.h>

typedef enum {
  SUCCESS,
  TOO_LONG,
  NOT_A_NUMERAL,
  MORE_THAN_3_PER_DIGIT
} ValidationResult;

//it is recommended to validate inputs with this before any other function use.
ValidationResult validate_numeral(const char* numeral);

//PRECONDITION: buffer size is at least 42 bytes.
//PRECONDITION: inputs have already been validated via validate_numeral()
void add_numerals(char * result, size_t result_length, const char * firstNumeral, const char * secondNumeral);

//PRECONDITION: buffer size is at least 42 bytes.
//PRECONDITION: inputs have already been validated via validate_numeral()
void subtract_numerals(char* result, size_t result_length, const char* first_numeral, const char* second_numeral);

#endif
