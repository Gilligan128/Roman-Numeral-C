#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "roman_math.h"
#include "constants.h"
#include "validate.h"

static const char numeral_digits[] = {
    'I',
    'V',
    'X',
    'L',
    'C',
    'D',
    'M'};

static bool is_character_a_numeral(char numeral_candidate)
{
  int i;
  for (i = 0; i < 7; i++)
  {
    if (numeral_candidate == numeral_digits[i])
    {
      return true;
    }
  }
  return false;
}

static bool is_not_a_numeral(const char *numeral_candidate)
{
  for (int char_i = 0; char_i < strlen(numeral_candidate); char_i++)
  {
    if (!is_character_a_numeral(numeral_candidate[char_i]))
    {
      return true;
    }
  }
  return false;
}

static bool is_too_long(const char *numeral_candidate)
{
  return strlen(numeral_candidate) > 20;
}

static bool has_more_than_3_of(const char* numeral_candidate, char character)
{
  int count = 0;
  for (int candidate_i = 0; candidate_i < strlen(numeral_candidate); candidate_i++)
    {
      if (numeral_candidate[candidate_i] == character)
        count++;
      if (count > 3)
        return true;
    }
  return false;
}

static bool has_more_than_3_per_IXCM(const char *numeral_candidate)
{
  const char no_more_than_3_of_these[] = {'I', 'X', 'C', 'M'};
  for (int char_i = 0; char_i < 4; char_i++)
  {
    if(has_more_than_3_of(numeral_candidate,no_more_than_3_of_these[char_i]))
      return true;
  }
  return false;
}



ValidationResult validate_numeral(const char *numeral_candidate)
{
  if (is_too_long(numeral_candidate))
    return TOO_LONG;

  if (is_not_a_numeral(numeral_candidate))
    return NOT_A_NUMERAL;

  if (has_more_than_3_per_IXCM(numeral_candidate))
    return MORE_THAN_3_PER_IXCM;
  return SUCCESS;
}

bool validate_buffer(size_t buffer_length)
{
  return MAX_COMBINED_NUMERAL_SIZE <= buffer_length;
}