/***************************************************************************
filename            coins.c
author              Roland Shum
DP email            roland.shum@digipen.edu
course              CS120
section             A
Practice Assignment 13
due date            10/31/2018

Brief Description:
  Practice Assignment 13. Definitions of print_coins and calculate_coins. 
  Print_coins prints to the console which combinations of coins can add up
  to the given value. calculate_coins calculates what is the exact combinations
  of coins needed to get the user value, using the amount of coins the user 
  specifies.
***************************************************************************/
#include <stdio.h> /* printf */
/**************************************************************************
   Function: print_coins
 
Description: Takes in the halves, quarters, dimes, nickels, and pennies
             and prints them out. Will not print if count is 0.
             
     Inputs: halves   - The amount of halves.
             quarters - The amount of quarters.
             dimes    - The amount of dimes.
             nickels  - The amount of nickels.
             pennies  - The amount of pennis.

    Outputs: Returns nothing. Will print to console the amount of coins 
             passed in in their respective coin name.
**************************************************************************/
void print_coins(int halves, int quarters, int dimes, int nickels, 
                 int pennies)
{
  /* Get the sum of the coins added together. */
  int sum = halves * 50 + quarters * 25 + dimes * 10 + nickels * 5 
            + pennies;
  
  /* Print the sum to screen, in float. */
  printf("You can make $%.2f with ", sum / 100.0);
  /* Print the respective coin names with the amount given, if any. */
  if (halves)
    printf("%i hal%s  ", halves, (halves > 1) ? "ves" : "f");
  if (quarters)
    printf("%i quarter%s  ", quarters, (quarters > 1) ? "s" : "");
  if (dimes)
    printf("%i dime%s  ", dimes, (dimes > 1) ? "s" : "");
  if (nickels)
    printf("%i nickel%s  ", nickels, (nickels > 1) ? "s" : "");
  if (pennies)
    printf("%i penn%s  ", pennies, (pennies > 1) ? "ies" : "y");
  
 /* A new line to end the sentance. */
  printf("\n");
}

/**************************************************************************
   Function: calculate_coins
 
Description: Finds all variations of coins needed for them to add up to 
             value, given that all the coins given are used.
             
     Inputs: value     - The value the coins all add up to.
             num_coins - The number of coins we have to use.

    Outputs: Returns nothing. Will print to console the amount of coins 
             passed in in their respective coin name, and how many variations
             there are.
**************************************************************************/
void calculate_coins(int value, int num_coins)
{
  int i, j, k, l, m;   /* Loop variables, also the coin representatives. */
  int method_ways = 0; /* The amount of ways that it could be calculated. */
 
  /* Find all variations of halfs. */
  for(i = 0; i <= num_coins; i++)
  {
   /* Find all variations of quaters. */ 
    for(j = 0; j + i <= num_coins; j++)
    {
      /* Find all variations of dimes. */
      for(k = 0; k + j + i <= num_coins; k++)
      {
        /* Find all variations of nickles. */
        for(l = 0; l + j + k + i <= num_coins; l++)
        {
          /* Find all variations of pennies. */
          for(m = 0; m + l + j + k + i <= num_coins; m++)
          {
            /* If we are using all the coins given to us. */
            if((m + l + j + k + i) == num_coins)
            {
              /* And they add up to the value given to us. */
              if(i * 50 + j * 25 + k * 10+ l * 5 + m == value)
              {
                /* We print it out!. */
                print_coins(i, j, k, l, m);
                
                /* And increment the amount of variations. */
                method_ways ++;
              }
            }
          }
        }
      }
    }
  }
  
  /* If there is no way to find the value using all the coins given. */
  if(!method_ways)
  {
    /* Print that its not possible. */
    printf("It is not possible to make $%4.2f from %i coins.\n", value
           / 100.f, num_coins);
  }
  else if (method_ways == 1)  /* There is only one way to find value. */
  {
    printf("There is %i possible way to make $%.2f from %i coins.\n", 
           method_ways, value / 100.f, num_coins);
  }
  else /* Else meaning there are ways to find value using all coins. */
  {
    /* Print how many different variations are possible to find value. */
    printf("There are %i possible ways to make $%.2f from %i coins.\n", 
           method_ways, value / 100.f, num_coins);
  }
}
