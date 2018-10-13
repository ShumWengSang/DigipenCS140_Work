/******************************************************************************
filename    sumdigits.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
week        5
due date    12/07/2018

Brief Description:
  Practice Assignment 5. The program prints out the sum and product 
  of the digits in a user-given integer.          
  
******************************************************************************/
#include <stdio.h> /* printf */
/**************************************************************************
   Function: main
 
Description: The program prints out the sum and product of the digits
             in a user-given integer. 

     Inputs: void

    Outputs: Exit Status of the program (integer). Always 0.
**************************************************************************/
int main(void)
{
  int userinput;    /* User input                     */
  int c_userinput;  /* Copy of User Input             */
  int i;            /* Loop variable                  */
  int sum = 0;      /* The sum of the digits.         */
  int product = 1;  /* The product of all the digits. */
  
  /* Prompt the user for input. */
  printf("Enter an integer (1 to 2,147,483,647 without commas): ");
  
  /* Retreive user input. */
  scanf("%i", &userinput);
  
  /* Copy the userinput to process. */
  c_userinput = userinput;
  
  /* Get the last digit in each loop and process it. */
  for(i = 0; c_userinput > 0; i++)
  {
    /* Get the last digit. */
    int digit = c_userinput % 10;
    
    /* Add the digit to the sum. */
    sum += digit;
    
    /* Multiply the product into the max product. */
    product *= digit;
    
    /* Move to the next digit. */
    c_userinput/= 10;
  }
  /* Print the sum and product of the integers. */
  printf("The sum of the digits in %i is %i.\n",userinput, sum);
  printf("The product of the digits in %i is %i.\n", userinput, product);

  /* Return success. */
  return 0;
}