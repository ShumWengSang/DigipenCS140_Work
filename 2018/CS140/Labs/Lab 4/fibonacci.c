/***************************************************************************
filename    fibonacci.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     C
lab week    4
due date    03/10/2018

Brief Description:
  Print a table of N amount of fibonacci number and their fibonacci quotient,
  where N is a user input between 2 and 46. Entering 1 exits the program.

***************************************************************************/
#include <stdio.h>        /* printf*/

#define SUCCESS        0
#define USER_EXIT_NUM  1
#define TRUE           1
#define FIRST_FIB_NUM  0
#define SECOND_FIB_NUM 1
#define MIN_INPUT_NUM  2
#define MAX_INPUT_NUM  46

/**************************************************************************
   Function: main

Description: Prints a table of N amount of fibonacci number and their
             fibonacci quotient, where N is a user input between 2 and 45.
             Entering 1 exits the program

     Inputs: void

    Outputs: Exit Status of the program (integer).
**************************************************************************/
int main(void)
{
  int i;                 /* Loop iterator                                */
  int user_input;        /* User input                                   */
  int fib_trail_num;     /* Holds Fn-2, where n is our current iteration */
  int fib_last_num;      /* Holds Fn-1, where n is our current iteration */
  int current_fib_num;   /* Holds Fn, where n is our current iteration   */
  double fib_quo;        /* Holds the quotient, not exactly needed.      */

  /* Program keeps running until player enters 1 to exit.*/
  do
  {
    /*
     * Prints the user prompt. User will enter a finobacci index
     * to be calculated. Clamped between MIN_INPUT_NUM and MAX_INPUT_NUM
     */
    printf("Enter the Fibonacci number to calculate.\n");      
    printf("The number must be an integer between 2 and 46."); 
    printf(" (Enter 1 to quit): ");                            
    scanf("%i", &user_input); /*User inputs into user_input              */

    /* If user input is 1, break the loop and exit the program.          */
    if (user_input == USER_EXIT_NUM)
    {
      return SUCCESS;         /* We exit the program                     */
    }

    /* If user input is not within our range, we restarting the loop     */
  }
  while (MIN_INPUT_NUM > user_input || user_input > MAX_INPUT_NUM);
  /* User input is within our range. Proceed to print table.             */
  
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

  /* Start looping until it exceeds user input.*/
  for (i = MIN_INPUT_NUM; i <= user_input; i++)
  {
    /*Calculate the current fib number by adding the last two.  */
    current_fib_num = fib_last_num + fib_trail_num;
    /*Calculate the fib quotient, can be done in printf instead */
    fib_quo = (double)current_fib_num / (double)fib_last_num;
    /*Print formatted version of the current fib number and the quotient.     */
    printf("%2i%14i%21.16f\n", i , current_fib_num, fib_quo);
    fib_trail_num = fib_last_num;   /* Prepare next iteration of fib_trail_num*/
    fib_last_num = current_fib_num; /* Prepare next iteration of fib_last_num */
  }

  return SUCCESS; /*RETURN SUCCESS*/
}
