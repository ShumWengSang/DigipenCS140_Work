/******************************************************************************
filename              squares3.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   3
due date              12/07/2018

Brief Description:
  Practice Assignment 3. 
  The program asks the user for two positive numbers, named range and stride.
  It will then print multiples of its stride, along with their respective 
  squared and cubed numbers, until the number is greater then range.
  
******************************************************************************/
#include <stdio.h>  /* printf */

#define MAX_RANGE 1290
/**************************************************************************
   Function: main
 
Description: Requests the user to enter two numbers. Find all the respective
             squared and cubed numbers between the two numbers that is a 
             multiple of stride, until range is hit. Prints the stride,
             stride squared, and stride cubed to console.

     Inputs: void

    Outputs: Exit Status of the program (integer). Always 0.
**************************************************************************/
int main(void)
{
  int i;      /* Loop variable.  */
  int range;  /* User input one. */
  int stride; /* User input two. */
  
  /* Keep prompting user input. */
  do
  { 
    /* Print the prompt. */
    printf("Enter two integers greater than 0: ");
    
    /* Take in user input. */
    scanf("%i %i", &range, &stride);
    
    /* If the range is within range. */
    if(range > 0 && range < MAX_RANGE)
    {
      /* If the stride is within range. */
      if(stride > 0 && stride < MAX_RANGE)
      {
        /* We continue to the next part. */
        break;
      }
    }
    /* We keep asking until break statement is hit. */
  }while(1);
  printf("\n");
  /* Print the table top. */
  printf(" Value     Value^2    Value^3\n");
  printf("-----------------------------\n");
  
  /* Increment i by stride, until range is smaller. */
  for(i = stride; i <= range; i += stride)
  {
    /* Print the respective number, number^2, and number^3. */
    printf("%5i%12i%12i\n", i, i * i, i * i * i);
  }
  /* Return success. */
  return 0;
}