/******************************************************************************
filename    dice1.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
week        6
due date    12/07/2018

Brief Description:
  Practice Assignment 6. The program prompts the user for how many times it
  will roll 5 dice. It will then count how many times all the dice are the same
  values. After all the rolls, it will display how many times it received a 
  five of a kind, and display the percentages.
  
******************************************************************************/
#include <stdio.h> /* printf, scanf       */
#include "PRNG.h"  /* ut_srand, RandomInt */

#define AMOUNT_OF_DIES 5
/**************************************************************************
   Function: main
 
Description: The program prompts the user for how many times it
             will roll 5 dice. It will then count how many times 
             all the dice are the same values. After all the rolls, 
             it will display how many times it received a five of a kind, 
             and display the percentages.

     Inputs: void

    Outputs: Exit Status of the program (integer). Always 0.
**************************************************************************/
int main(void)
{
  int user_input; /* User Input. Amount of rolls to do. */
  int i, j;      /* Loop variables.                     */


  /* Seed the pseudo-random number generator.                   */
  /* DON'T CHANGE THIS WHEN UPLOADING TO THE SUBMISSION SERVER! */
  /* If you change this, your output won't match when you diff. */
  ut_srand(0, 0);

  do
  { 
    int five_of_a_kind = 0; /* Record the amount of 5 of a kind rolls. */
    
    /* Prompt the user for how many times to roll. */
    printf("How many times do you want to roll the dice? (0=quit) ");

    /* Retrieve the amount of times to roll. */
    scanf("%i", &user_input);

    /* If userinput is 0, exit the program. */
    if(user_input == 0)
    {
      break;
    }
    
    /* Roll as many times as user dictates. */
    for(i = 0; i < user_input; i++)
    {
      /* Create an array that stores the dice roll values. */
      int dice[AMOUNT_OF_DIES];

      /* Roll each die and get a random amount. */
      for(j = 0; j < AMOUNT_OF_DIES; j++)
      {
        /* Get a random amount for each die. */
        dice[j] = RandomInt(1, 6);
      }

      /*
       * Its easier to prove things are not equal to each other
       * then to prove they are all equal. We assume its five of 
       * a kind, until proven false. So we add five_of_a_kind.
       */
      five_of_a_kind++;

      /* Check each die. */
      for(j = 0; j < AMOUNT_OF_DIES; j++)
      {
        /*If dice does not equal to dice[0], then its not all equal. */
        if(dice[j] != dice[0])
        {
          /* Proven false, so take away. */
          five_of_a_kind--;
          
          /* We can break out of this loop now since its proven false. */
          break;
        }
      }
    }

    /* Print the amount of times the user had five of a kind. */
    printf("After %i rolls, you had 5 of a kind %i ",
           user_input, five_of_a_kind);

    /* Print time instead of times if yahtzee once */
    if(five_of_a_kind == 1)
    {
     printf("time.\n");
    }
    else
    {
      printf("times.\n");
    }

    /* Calculates the percentage of five of a kind and prints it out. */
    printf("This is a percentage of %.8f.\n\n",
           (double)five_of_a_kind / (double)user_input);
  }
  /* We only quit by breaking, in the code above. */
  while (1);

  /* Return success. */
  return 0;
}
