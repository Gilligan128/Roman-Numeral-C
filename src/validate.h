#ifndef VALIDATION
#define VALIDATION

#include <stdbool.h>

typedef struct
{
  bool success;
  char* message;
} ValidationResult;

ValidationResult validate_numeral(char* numeral);

#endif
