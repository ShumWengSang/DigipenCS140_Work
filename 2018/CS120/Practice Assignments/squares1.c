/***************************************************************************
filename    squares1.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     C
lab week    2
due date    07/12/2018

Brief Description:
  Practice Assigment for loops where we loop 
  and print out the values of 1 to 20

***************************************************************************/
#include <stdio.h>    /*printf*/
/**************************************************************************
   Function: main
 
Description: Prints the values of 1 to 20 and their
             respective squared values

     Inputs: void

    Outputs: Exit Status of the program (integer).
**************************************************************************/
int main(void)
{
  int i;                                  /*Loop iterator*/
  printf("   Value     Value*Value\n");   /*Print Table*/
  printf("------------------------\n");   /*Print Table Next Line*/
  
  /*Iterate 20 times and print the number and its squared form*/
  for(i = 1; i <= 20; i++)
  {
    printf("%6i:%12i\n", i , i * i);
  }
  
  return 0;  /*RETURN SUCCESS*/
}
