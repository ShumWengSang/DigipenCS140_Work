/***************************************************************************
filename    triple_cube.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     C
lab week    5
due date    10/10/2018

Brief Description:
  Holds the definitions of print_cubes and print_pythagorean_triples, both of
  which prints a numbers.                                               

***************************************************************************/
#include <stdio.h> /* printf */

#define NUM_OF_DIGITS 3
/**************************************************************************
   Function: print_cubes

Description: Prints all 3-digit integers with the cube property. The function
             goes through all three digit numbers and parses them into their
             digit forms. Then it checks if the sum of the cubes of the digits
             matches with the original number.

     Inputs: void (Nothing)

    Outputs: void (Nothing)
**************************************************************************/
void print_cubes(void)
{
  int i = 0; /* Loop iterator. */
  for(i = 100; i <= 999; ++i)
  {

    unsigned j;                /* Loop iterator.               */
    int digits[NUM_OF_DIGITS]; /* We store each digit here.    */
    int sum = 0;               /* The sum of the digits cubed. */
    int original = i;          /* A copy of i.                 */  
    
    /* We loop through each digit, finding it, cube it, and adding it to SUM. */
    for(j = 0; j < NUM_OF_DIGITS; ++j)
    {      
      /* Get the last digit of the number. Store it. */
      digits[j] =  original % 10;
      
      /* Add the digit cubed to sum. */
      sum += digits[j] * digits[j] * digits[j]; 
      
      /* Move to the next digit WITH truncation. */
      original /= 10;
    }
    
    /* If sum is the original number, print it out. */
    if(sum == i)
    {
      /* Print out the original numbers and its digit components. */
      printf("%i has the cube property. (%i + %i + %i)\n",
             i,
             digits[2] * digits[2] * digits[2],
             digits[1]* digits[1] * digits[1],
             digits[0]* digits[0] * digits[0]);
    }
  }
}

/**************************************************************************
   Function: print_pythagorean_triples

Description: Prints all the numbers ranging from USER INPUT LOW to USER INPUT
             HIGH that are Pythagorean triplets, triplets being a^2 + b^2 = c^2

     Inputs: low -- User input for range. This is the floor, or minimum to 
                    check.
            
             high -- User input for range. This is the ceiling, or max to check.

    Outputs: void (Nothing)
**************************************************************************/
void print_pythagorean_triples(int low, int high)
{
  int i, j, k;            /* Loop variables,                    */
  int triple_counter = 1; /* Count how many triplets there are. */ 
  
  /* For within the range of low to high. */
  for(i = low ; i < high; ++i)
  { 
    /* 
     * We set j to i, to avoid duplications by going 
     * through numbers we already have.
     */
    for(j = i; j < high; ++j)
    {  
      /* 
       * Notice that i + j is always > k. Thus we only need to check 
       * till i + j, or the highest value, whichever is lower.
       */
      int ceiling = ((i + j) > high) ? (high) : (i + j);
      /* Notice that k will always be bigger then j. So we loop from there. */
      for(k = j; k < ceiling ; ++k)
      {
        /* If the sum of i^2 and j^2 is the same as k^2, print it. */
        if((i * i)+ (j * j) == (k * k))
        {
          /* Print the counter, the numbers, and the proof. */
          printf("Triple #%3i: %3i,%3i,%3i --> %4i + %4i = %4i\n",
                 triple_counter++, i , j, k, i * i, j * j, k * k);
          /* We found one, so break out of the loop. */
          break;
        }
      }
    }
  }
}
