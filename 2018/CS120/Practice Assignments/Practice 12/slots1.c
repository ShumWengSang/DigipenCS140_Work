/***************************************************************************
filename            slots1.c
author              Roland Shum
DP email            roland.shum@digipen.edu
course              CS120
section             A
Practice Assignment 12
due date            10/31/2018

Brief Description:
  program that similates a slot machine with 3 slots. The player will start out
  with 100 points. Each time the player requests another spin, 3 random numbers
  (from 1 to 5) will be generated. If two of the slots are the same, the player
  will win 15 points. If all 3 are the same, the player wins 30 points. This 
  continues until the player chooses to quit, or the player has less than 10 
  points left. (Each spin costs 10 points).
***************************************************************************/
#include <stdio.h> /* printf     */
#include "PRNG.h"  /* PRNG stuff */

#define SPIN_COST       10  /* The price to spin.                     */
#define NO_WIN          0   /* INT representation of no combo.        */
#define TWO_OF_A_KIND   1   /* INT representation of two of a kind.   */
#define THREE_OF_A_KIND 2   /* INT representation of three of a kind. */
/******************************************************************************
   Function: detect_combo
 
Description: This function takes in an array and finds of any combo can be
             detected. A combo is a two of a kind or a three of a kind. 
             0 - No Wins.
             1 - Two of a Kind.
             2 - Three of a Kind.
             
     Inputs: arr  - Array where each index represents the number, and the value
                    of the index represents the amount of times it appears.
             size - The size of the array.

    Outputs: INTS the represents if the player won. 0 means no win. 1 means
             2 of the same. 2 means 3 of the same. Else means nothing.
******************************************************************************/
int detect_combo(int arr[], int size)
{
  int combo_count = NO_WIN;  /* The combos detected, default no win. */
  int i;                     /* Loop Variable.                       */
  
  /* Loop through array. */
  for(i = 0; i < size; i++)
  {
    /* Element value is the number of times appeared. Check for two. */
    if(arr[i] == 2)
    {
      /* There is a combo of 2 of a kind. */
      combo_count = TWO_OF_A_KIND;
      /* Combo found. No need to do more. */
      break;
    }
    /* Check for combo of three. */
    else if(arr[i] == 3)
    {
      /* There is a combo of 3 of a kind. */
      combo_count = THREE_OF_A_KIND;
      /* Combo found. No need to do more. */
      break;
    }
  }
  /* Returns a 0 normally, or a combo count represented by an INT. */
  return combo_count;
}

/******************************************************************************
   Function: spin_slots
 
Description: This function takes the amount of slots to spin, and spins 
             random numbers between 1 and 5 for them. It will call detect_combo
             and return the INT the that represents the combo won, if any.
             
     Inputs: spint_amount - The amount of slots to spin.

    Outputs: INTS the represents if the player won. 0 means no win. 1 means
             2 of the same. 2 means 3 of the same. Else means nothing. Also
             prints out the slot numbers.
******************************************************************************/
int spin_slots(int spin_amount)
{
  int i;               /* Loop Variable.                         */
  int spin_results[3]; /* Array to hold the result of each spin. */
  
  /* Array to hold the numbers of times each spin generates the number.*/
  int numbers[5] = {0}; 
  
  /* Spin as many times as passed in. */
  for(i = 0 ; i < spin_amount; i++)
  {
    /* Generate a random result from the spin, from 1 - 6. */
    spin_results[i] = RandomInt(1, 5);
    
    /* Add one to record the amount of times spin_results[i] has appeared. */
    numbers[spin_results[i] - 1]++;
  }
  /* Print out the results of the spin. */
  printf(" %i  %i  %i \n", spin_results[0], spin_results[1], spin_results[2]);
  
  /* Detect combo and return the INT representing it. */
  return detect_combo(numbers, 5);
}

/******************************************************************************
   Function: main
 
Description: A slot machine program. Player starts with 100 points, and each
             spin costs 10 points. Getting 2 of the same awards 15, and three
             of the same awards 30. Player can choose to spin or quit, until
             he has less then 10 points left.

     Inputs: void

    Outputs: 0 for Success (Always).
******************************************************************************/
int main(void)
{
  int user_input;        /* Variable to store user input.     */
  int money_count = 100; /* The amount of money the user has. */
  
  /* Seed the PRNG */
  ut_srand(5, 2);

  /* Print out the instructions */
  printf("You start with 100 points. Each play costs 10 points.\n");
  printf("There are 3 slots, each contains 5 different values.\n");
  printf("If you get 2 of the same, you win 15 points.\n");
  printf("If you get 3 of the same, you win 30 points.\n");
  printf("Here we go!\n\n");

  do
  {
    /* Spin 3 times and store the int representatino of combo in result. */
    int result = spin_slots(3);
    
    /* Each spin costs 10. */
    money_count -= SPIN_COST;
    
    /* User wins nothing. */
    if(result == NO_WIN)
    {
      printf("You didn't win anything. ");
    }
    /* If the user wins a 2 of a kind combo. */
    else if(result == TWO_OF_A_KIND)
    {
      /* Two of a kind wins 15. */
      money_count += 15;
      
      /* Print the two of a kind prompt */
      printf("You win 15 points. ");
    }
    else if(result == THREE_OF_A_KIND)
    {
      /* Three of a kind! Win 30! */
      money_count += 30;
      
      /* print the prompt for a big win. */
      printf("BIG WINNER! You get 30 points!! ");
    }
    /* print the amount of money the player has left. */
    printf("You now have %i points.\n", money_count);
    
    /* if the user does not have enough money.*/
    if(money_count < SPIN_COST)
    {
      /* Tell the user he doesn't have enough money. */
      printf("You don't have enough to play. Go home. \n");
        
      /*break out of the while loop and end program.*/
      break;
    }
    
    /* Prompt the user if he wants to continue. */
    printf("\nPlay again? (1=yes,0=no) ");
    
    /* Read the user input. */
    scanf("%i", &user_input);
    
    /* If user presses zero, quit the game. */
    if(user_input == 0)
    {
      /* End the loop. */
      break;
    }
  }
  /* Loop always runs. Terminated by break statements above. */
  while(1);
  
  /* One more end line to end it. */
  printf("\n");

  return 0;
}
