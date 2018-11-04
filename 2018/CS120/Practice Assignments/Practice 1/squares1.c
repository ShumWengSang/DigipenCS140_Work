/***************************************************************************
filename              squares1.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   1
due date              12/07/2018

Brief Description:
  Practice Assigment 1. Loops where we loop and print out the values of 1 to 20
  and their squared values.

***************************************************************************/
#include <stdio.h>    /*printf*/
/**************************************************************************
   Function: main
 
Description: Prints the values of 1 to 20 and their
             respective squared values.

     Inputs: void

    Outputs: Exit Status of the program (integer). Always 0.
**************************************************************************/
int main(void)
{
  int i;                                  /*Loop iterator         */
  printf("   Value     Value*Value\n");   /*Print Table           */
  printf("------------------------\n");   /*Print Table Next Line */
  
  /*Iterate 20 times and print the number and its squared form. */
  for(i = 1; i <= 20; i++)
  {
    printf("%6i:%12i\n", i , i * i);
  }
  
  return 0;  /*RETURN SUCCESS */
}
