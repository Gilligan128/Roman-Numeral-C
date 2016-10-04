#ifndef VALIDATION
#define VALIDATION

typedef struct
{
  int code;
  char* message;
} ValidationResult;

ValidationResult validate_numeral(char* numeral);

#endif
