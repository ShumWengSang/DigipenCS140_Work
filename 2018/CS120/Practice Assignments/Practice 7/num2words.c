/******************************************************************************
filename    num2words.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
week        7
due date    12/07/2018

Brief Description:
  Practice Assignment 7. Definition for number_to_words function. This function
  takes in a two digit number and changes it into its word form.
  
******************************************************************************/
#include <stdio.h> /* printf */

#define DIGITS 2
/**************************************************************************
   Function: number_to_words
 
Description: Takes a two-digit number and prints out its respective
             English word.

     Inputs: number  -- The number to parse.

    Outputs: void
**************************************************************************/
void number_to_words(int number)
{
  
  int digit; /* This will hold the last digit. */
  int i;     /* Loop variable. */
   
  /* The ones place, holds all the exceptions. */
  const char * ones[20] = { "", "one", "two", "three", "four", "five",
                               "six", "seven", "eight", "nine", "ten", "eleven",
                               "twelve", "thirteen", "fourteen", "fifteen", 
                               "sixteen", "seventeen", "eighteen", "nineteen"
                          };
                             
  /* The tens place.*/
  const char * tens[9] = { "", "twenty", "thirty", "fourty", "fifty", "sixty",
                              "seventy", "eighty", "ninety"
                         };
 

  for(i = 0; i < DIGITS; i++)
  {
      digit = number % 10;
      if(digit < 20)
      {
        
      }
  }
  
  
}