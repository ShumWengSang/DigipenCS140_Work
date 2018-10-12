/***************************************************************************
filename    squares2.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
lab week    3
due date    12/07/2018

Brief Description:
  Practice Assigment 2. Finds all respective squared and cubed numbers
  between the user's two numbers, and must be a multiple of the first number.

***************************************************************************/
#include <stdio.h> /* printf */
/**************************************************************************
   Function: main
 
Description: Requests the user to enter two numbers. Find all the respective
             squared and cubed numbers between the two numbers that is a 
             multiple of stride and display it.

     Inputs: void

    Outputs: Exit Status of the program (integer).
**************************************************************************/
int main(void)
{
  int i;      /* Loop variable.  */
  int range;  /* User Input One. */
  int stride; /* User Input Two. */
  
  /* Printf the prompt. */
  printf("Enter two integers greater than 0: ");
  
  /* Take in range and stride.*/
  scanf("%i %i", &range, &stride);

  /* Start the printing of the table. */
  printf("\n Value     Value^2    Value^3\n");
  printf("-----------------------------\n");
  
  /* We start at the user's first number and end it on the other. */
  for(i = stride; i <= range; i += stride)
  {
    /* Print the number we are on, and the respective sqaured and cubed form. */
    printf("%5i%12i%12i\n", i, i * i, i * i * i);
  }
  /* Return success. */
  return 0;
}