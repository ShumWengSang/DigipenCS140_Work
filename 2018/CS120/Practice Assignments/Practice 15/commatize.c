/******************************************************************************
filename              commatize.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   15
due date              12/07/2018

Brief Description:
  Practice Assigment 14. Provides two functions that convert Windows-style text 
  file to a Unix-style text file and vice versa.
******************************************************************************/
/* This is the largest commatized string for a long int */  
#define MAXLEN 27
#define ASCII_COMMA 44  /* ASCII representation for comma */

/*******************************************************************************
   Function: commatize
 
Description: Given a number, converts it to string as well as giving it commas.

     Inputs: number - Number to commatize and convert to string.

    Outputs: pointer to a c-string array that contains the commatized string.
*******************************************************************************/
char *commatize(long long number)
{
  /* This is the return char array. */
  static char buffer[MAXLEN]; 
  
  int buffer_index = MAXLEN - 1;  /* current buffer index, but from last. */
  int i;                          /* Loop variable.                       */
  
  /* Record if number is negative */
  int is_neg = 0;
  
  /* Handle 0 */
  if(number == 0)
  {
    /* Set to 0. */
    buffer[buffer_index] = '0';
    
    /* Return the address of buffer. */
    return &buffer[buffer_index];
  }
  
  /* If number is negative */
  if(number < 0)
  {
    /* Record down. */
    is_neg = 1;
    
    /* Set the number to positive first. */
    number *= -1;
  }
  
  /* Set the buffer to 0. */
  for(i = 0; i < MAXLEN; i++)
  {
    buffer[i] = 0;
  }
  
  /* Get the last digit in each loop and process it. We start at 1. */
  for(i = 1; number > 0; i++)
  {
    /* Get the last digit. */
    int digit = number % 10;
    
    /* Convert to ASCII */
    digit += '0';
    
    /* Place digit at end of buffer. */
    buffer[buffer_index--] = digit;
    
    /* Every third number, */
    if(i % 3 == 0)
    {
      /* If this is not the last digit. */
      if((number / 10) > 0)
      {
        /* We add a comma. */
        buffer[buffer_index--] = ASCII_COMMA;
      }
    } 
    /* Move to the next digit. */
    number /= 10;
  }
  
  /* We check if it was originially a negative. If it is, we add a -. */
  if(is_neg)
  {
    buffer[buffer_index--] = '-';
  }
  
  /* Loop is done, return the pointer to the start of string. */
  return &buffer[buffer_index + 1];
}