/***************************************************************************
filename    sieve.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
Lab         7
due date    10/25/2018

Brief Description:
  Lab 3. Find primen numbers using The Sieve of Erotoshenes. Find twin 
  primes, and Brun's Constant.
***************************************************************************/
#include <stdio.h> /* printf      */
#include <math.h>  /* sqrt        */
#include "sieve.h" /* TRUE, FALSE */

/**************************************************************************
   Function: sieve
 
Description: Finds all prime numbers between 0 and the length of the array.

     Inputs: array  -- The array to hold all the numbers.
             length -- The length of the array passed in.

    Outputs: If the given phrase is a palindrome. 1 for TRUE. 0 for FALSE.
**************************************************************************/
void sieve(int array[], int size)
{
  int i, j;
  int max_iterations;
  
  /* Set all numbers to true. */
  for(i = 0; i < size; i++)
  {
    array[i] = TRUE;
  }
  /* 1 and 0 are not primes. */
  array[0] = FALSE;
  array[1] = FALSE;
  
  max_iterations = sqrt(size);
  
  for(i = 2; i < max_iterations; i++)
  {
    /* If the array is already crossed out, we ignore. */
    if(array[i] == FALSE)
      continue;
    /* Find all multiples of i. */
    for(j = i + 1; j < size; j++)
    {
      /* j is a multiple of i. */
      if(j % i == 0)
      {
        /* Set them to 0. */
        array[j] = FALSE;
      }
    }
  }
}

int twin_primes(const int primes[], int size)
{
  int i;
  int prime_num = 0;
  int last_prime = 2;
  
  
  for(i = 0; i < size; i++)
  { 

    if(primes[i] == TRUE)
    {
      if((i - last_prime) == 2)
      {
        printf("twin prime #%4i: %4i and %4i\n", ++prime_num, last_prime, i);

      }
      last_prime = i;
    }
  }
  
  return prime_num;
}

double brun_constant(const int primes[], int size)
{  
  int i;
  double output = 0;
  int last_prime = 2;
  
  for(i = 0; i < size; i++)
  {
    if(primes[i] == TRUE)
    {
      if((i - last_prime) == 2)
      {
        output += (1.0 / i) + (1.0 / last_prime);
      }
      last_prime = i;
    }
  }
  
  return output;
}