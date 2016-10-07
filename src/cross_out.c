#include <stdlib.h>
#include <string.h>

#include "roman_string.h"
#include "cross_out.h"

void cross_out_numerals(char* numeral, char* what_to_cross_out)
{
  int original_length = strlen(numeral);
  if(strlen(numeral) < strlen(what_to_cross_out))
  { 
    strcpy(numeral, "");
    return;
  }
  
  //for(int cross_out_index=0;cross_out_index<strlen(what_to_cross_out);i++)
  
  if(strchr(numeral, what_to_cross_out[0])) 
  {
     replace_substring_once(numeral, (char[2]){what_to_cross_out[0], '\0'}, "");
  }
  else 
  {
    expand_group(numeral, 0);
    replace_substring_once(numeral, (char[2]){what_to_cross_out[0], '\0'}, "");
  }
 	
} //xI - V
