/******************************************************************************
filename              strtoint.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   17
due date              12/07/2018

Brief Description:
  Practice Assigment 17. Definition of strtoint, where we convert a given
  number in string form to its int form. Ex : c-string '1024' returns 1024 in 
  int.
*******************************************************************************/
#include <string.h> /* strlen */
/*******************************************************************************
   Function: strtoint
 
Description: Converts a given number in string to its int form. Ex: Given
             c-string '1024' returns 1024 in int.

     Inputs: string  - c-string number to convert to int. Elements must be from
                       '0' to '9', and a '-' in front, if number is negative.

    Outputs: Returns the given number in the string in int form.
*******************************************************************************/
int strtoint(const char string[])
{
  int i, j;                        /* Loop variable.              */ 
  int result = 0;                  /* The converted number.       */
  int is_neg = 0;                  /* Is the string a negative?   */
  int str_length = strlen(string); /* Length of the given string. */
  
  /* We will loop backwards, so this tells us where to end. Set to 0. */
  char end_index = 0;
  
  /* Check if the first element is '-', to check for negative number. */
  if(string[0] == '-')
  {
    /* For the incoming loop, make sure it ends when a '-' is found */
    end_index = '-';
    
    /* Record that it is a negative number. */
    is_neg = 1;
  }
  
  /* Loop through the string backwards until the sign, if there is one. */
  for(j = 0, i = str_length - 1; string[i] != end_index; i--, j++)
  {
    int k;         /* Loop variable. */
    int power = 1; /* Current power. */
    
    /* POW func. Loop as many times to get the current power. */
    for(k = 0; k < j; k++)
    {
      /* If pow 1, gives 10. If pow 0, gives 1. If pow 2, gives 100. */
      power *= 10;
    }
    /* 
     * Convert the number from char to int,then multiply by power and 
     * add to result.
     */
    result += (string[i] - '0') * power;
  }
  /* Remember to turn to negative if it is negative. */
  if(is_neg)
  {
    /* Turn to negative. */
    result *= -1;
  }
  
  return result;
}