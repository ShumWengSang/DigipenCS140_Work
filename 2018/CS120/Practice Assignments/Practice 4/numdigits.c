/******************************************************************************
filename              numdigits.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   4
due date              12/07/2018

Brief Description:
  Practice Assignment 4. The program prints out the number of digits in a 
  given number provided by the user.
  
******************************************************************************/
#include <stdio.h> /* printf */
/**************************************************************************
   Function: main
 
Description: The program prints out the number of digits in a 
             given number provided by the user.

     Inputs: void

    Outputs: Exit Status of the program (integer). Always 0.
**************************************************************************/
int main(void)
{
  int userinput;   /* User input.         */
  int c_userinput; /* Copy of user input. */
  int i;           /* Loop variable.      */
  
  /* Print prompt. */
  printf("Enter an integer (1 to 2,147,483,647 without commas): ");
  
  /* Retreive user input. */
  scanf("%i", &userinput);
  
  /* Set the copy of userinput to userinput. */
  c_userinput = userinput;
  
  /* Loop until the copy is less then 0. i is the digit number. */
  for(i = 0; c_userinput > 0; i++)
  { 
    /* 
     * Divide by 10 returns a new number with the last digit gone.
     * Truncation intended.
     */
    c_userinput/= 10;
  }
  /* Print the amount of digit in the userinput. */
  printf("The number of digits in %i is %i.\n", userinput, i);
  
  /* Return success */
  return 0;
}