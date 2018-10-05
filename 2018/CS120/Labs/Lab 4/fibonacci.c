/***************************************************************************
filename    fibonacci.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     C
lab week    4
due date    10/03/2018

Brief Description:
  Print a table of N amount of fibonacci number and their fibonacci quotient,
  where N is a user input between 2 and 46. Entering 1 exits the program.

***************************************************************************/
#include <stdio.h>        /* printf*/

#define SUCCESS        0  /* Return 0 for main. */
#define EXIT_PROGRAM  1  /* User enters this number to exit program.  */
#define FIRST_FIB_NUM  0  /* No calc needed for first fib, this is it. */
#define SECOND_FIB_NUM 1  /* And this is the second fib number.        */
#define MIN_INPUT_NUM  2  /* User needs to enter above this number.    */
#define MAX_INPUT_NUM  46 /* User needs to enter below this number.    */
/**************************************************************************
   Function: main

Description: Prints a table of N amount of fibonacci number and their
             fibonacci quotient, where N is a user input between 2 and 45.
             Entering 1 exits the program

     Inputs: void

    Outputs: Exit Status of the program, Int(always 0 in this case)
**************************************************************************/
int main(void)
{
  int i;               /* Loop iterator                                */
  int user_input;      /* User input                                   */
  int fib_trail_num;   /* Holds Fn-2, where n is our current iteration */
  int fib_last_num;    /* Holds Fn-1, where n is our current iteration */
  int current_fib_num; /* Holds Fn, where n is our current iteration   */
  double fib_quo;      /* Holds the quotient                           */
  
 /*
  * Prints the user prompt and keep printing it until the user
  * enters a valid number. Entering 1 exits the program.
  * Valid numbers are from MIN_INPUT_NUM to MAX_INPUT_NUM.
  */
  do
  {
    /* Print user prompt. */
    printf("Enter the Fibonacci number to calculate.\n");
    printf("The number must be an integer between 2 and 46.");
    printf(" (Enter 1 to quit): ");

    /* Take in user input. */
    scanf("%i", &user_input);

    /* If user input is 1, we exit the program. */
    if (user_input == EXIT_PROGRAM)
    {
      return SUCCESS; /* We exit the program. */
    }
  }
  /* If user input is not within our range, we reprompt him. */
  while (MIN_INPUT_NUM > user_input || user_input > MAX_INPUT_NUM);
  
  /* 
   * The following printfs print the Table Header and
   * the first two rows as they do not need to be calculated.
   */
  printf("\n");
  printf("           Fibonacci        Fibonacci\n");   
  printf(" N           number          quotient\n");   
  printf("-------------------------------------\n");   
  printf(" 0             0                  N/A\n");   
  printf(" 1             1                  N/A\n");   
  
  /* Manually set the trailing numbers for 1st and 2nd rows */
  fib_last_num = SECOND_FIB_NUM;
  fib_trail_num = FIRST_FIB_NUM;

  /* Start looping from 2 till it exceeds user input. */
  for (i = MIN_INPUT_NUM; i <= user_input; i++)
  {
    /* Calculate the required numbers. */
    current_fib_num = fib_last_num + fib_trail_num;
    fib_quo = (double)current_fib_num / (double)fib_last_num;

    /* And print them out in a formatted version. */
    printf("%2i%14i%21.16f\n", i , current_fib_num, fib_quo);

    /* 
     * Prepare next iteration of loop by
     * setting the last and trailing numbers.
     */
    fib_trail_num = fib_last_num;
    fib_last_num = current_fib_num;
  }

  return SUCCESS; /* RETURN SUCCESS */
}
