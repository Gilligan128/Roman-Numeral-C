#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "roman_math.h"
#include "constants.h"
#include "validate.h"
#include "subtractives.h"

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

static bool has_more_than_n_of(const char *numeral_candidate, int n, char character)
{
  int count = 0;
  for (int candidate_i = 0; candidate_i < strlen(numeral_candidate); candidate_i++)
  {
    if (numeral_candidate[candidate_i] == character)
      count++;
    if (count > n)
      return true;
  }
  return false;
}

static bool has_more_than_3_per_IXCM(const char *numeral_candidate)
{
  const char no_more_than_3_of_these[] = {'I', 'X', 'C', 'M'};
  for (int char_i = 0; char_i < sizeof(no_more_than_3_of_these); char_i++)
  {
    if (has_more_than_n_of(numeral_candidate, 3, no_more_than_3_of_these[char_i]))
      return true;
  }
  return false;
}

static bool has_more_than_1_per_VLD(const char *numeral_candidate)
{
  const char only_1_of_these[] = {'V', 'L', 'D'};
  for (int char_i = 0; char_i < sizeof(only_1_of_these); char_i++)
  {
    if (has_more_than_n_of(numeral_candidate, 1, only_1_of_these[char_i]))
      return true;
  }
  return false;
}

ValidationResult validate_numeral(const char *numeral_candidate)
{
  char buffer[MAX_COMBINED_NUMERAL_SIZE];
  strcpy(buffer, numeral_candidate);
  remove_subtractives(buffer);

  if (is_not_a_numeral(buffer))
    return NOT_A_NUMERAL;

  if (has_more_than_3_per_IXCM(buffer))
    return MORE_THAN_3_PER_IXCM;

  if (has_more_than_1_per_VLD(buffer))
    return MORE_THAN_1_PER_VLD;
  return SUCCESS;
}

bool validate_buffer(size_t buffer_length)
{
  return MAX_COMBINED_NUMERAL_SIZE <= buffer_length;
}