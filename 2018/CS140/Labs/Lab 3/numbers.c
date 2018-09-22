/******************************************************************************
filename    numbers.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
lab week    3
due date    09/27/2018

Brief Description:
  This program takes in 3 numbers and outputs the 
  corresponding Sin, Cos, Tan, and aTan numbers.
  
******************************************************************************/
#include <math.h>               /* sin(), cos(), tan(), atan()*/
#include <stdio.h>              /* printf(), scanf()          */

int main (void)
{
  float input_1;                /* User input one  */
  float input_2;                /* User input two  */
  float input_3;                /* User input three*/
  
  /* Asks user for input.*/
  printf("Enter 3 numbers between 0 and 9.999: ");
  
  /* Waits user for input three floats.*/
  scanf("%f %f %f", &input_1, &input_2, &input_3);
  
  /* A new line to start the table. */
  printf("\n");
  
  /* Format the header of the table nicely.*/
  printf("Number      sin      cos      tan      atan\n");
  printf("-------------------------------------------\n");
  
  /*
   * Printing the outcome of sin, cost, tan, and atan 
   * after passing in user's first input and converting
   * the outcome to float.
   *
   * The original number shall show up to 5 decimal points
   * while the others shall have a standard width of 8
   * and show 3 decimal points.
   */
  printf("%.5f %8.3f %8.3f %8.3f %8.3f\n",
         input_1,(float)sin(input_1), (float)cos(input_1),
         (float)tan(input_1), (float)atan(input_1));
  
  /* Do the same for the second input.*/
  printf("%.5f %8.3f %8.3f %8.3f %8.3f\n",
         input_2,(float)sin(input_2), (float)cos(input_2),
         (float)tan(input_2), (float)atan(input_2));
  
  /* Do the same for the last input.*/
  printf("%.5f %8.3f %8.3f %8.3f %8.3f\n",
         input_3,(float)sin(input_3), (float)cos(input_3),
         (float)tan(input_3), (float)atan(input_3));
  
  /* return success*/
  return 0;
}
