#include "validate.h"


ValidationResult error(char* message)
{
  ValidationResult error = {1, message};
  return error;
}


ValidationResult validate_numeral(char* numeral)
{
  if(strcmp(numeral, "I") != 0)
    return error("invalid numeral");

  ValidationResult result = {0, ""};
  return result;
};
