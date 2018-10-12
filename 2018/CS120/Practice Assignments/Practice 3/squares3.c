/******************************************************************************
filename    squares3.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
week        5
due date    12/07/2018

Brief Description:
  Practice Assignment 3. 
  The program asks the user for two numbers. It will then find the difference
  between the numbers. It will then find all multiples of the itself between 0
  and the second user number. It will print those numbers, and their respective
  squared and cubed form.
  
******************************************************************************/
#include <stdio.h>  /* printf */
/**************************************************************************
   Function: main
 
Description: Requests the user to enter two numbers. Find all the respective
             squared and cubed numbers between the two numbers that is a 
             multiple of the difference of both numbers and display it.

     Inputs: void

    Outputs: Exit Status of the program (integer).
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
    printf("Enter two integers greater then 0: ");
    
    /* Take in user input. */
    scanf("%i %i", &range, &stride);
    
    /* If the range or stride is less then 0, we keep asking. */
    if(range <= 0 || stride <= 0)
      continue;
  
    /* We quit the loop when the user gives a valid number. */
  }while(range >= 1290 || range <= 0);

  /* Print the table top. */
  printf(" Value     Value^2    Value^3\n");
  printf("-----------------------------\n");
  
  /* Loop  */
  for(i = stride; i <= range; i += stride)
  {
    printf("%5i%12i%12i\n", stride, stride * stride, stride * stride * stride);
  }
  return 0;
}