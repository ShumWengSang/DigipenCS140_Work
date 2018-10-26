/******************************************************************************
filename    sieve.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
Lab         7
due date    10/24/2018

Brief Description:
  Lab 7. Find primen numbers using The Sieve of Erotoshenes. Find twin 
  primes, and Brun's Constant.
******************************************************************************/
#include <stdio.h> /* printf      */
#include <math.h>  /* sqrt        */
#include "sieve.h" /* TRUE, FALSE */

/******************************************************************************
   Function: sieve
 
Description: Finds all prime numbers between 0 and the length of the array.
             This will modify the given array and set the value of array[i] to
             1 (for TRUE) if *i* is a prime.

     Inputs: array  -- The array to modify if indexes are primes. This means 
                       the function will check if array[i] checks if *i*
                       is prime.
             size   -- The maximum number, from 0, to find all prime numbers.

    Outputs: None
******************************************************************************/
void sieve(int array[], int size)
{
  int i, j;           /* Loop iterators.                                     */
  int max_iterations; /* Holds the sqrt of size aka the number of iterations */
  
  /* Set all numbers in given array to true. */
  for(i = 0; i < size; i++)
  {
    array[i] = TRUE;
  }
  
  /* 1 and 0 are not primes. */
  array[0] = FALSE;
  array[1] = FALSE;
  
  /* Find the max amount of iterations by square rooting the size. */
  max_iterations = sqrt(size);
  
  /* Loop through 2 to the square root of size. */
  for(i = 2; i <= max_iterations; i++)
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

/******************************************************************************
   Function: twin_primes
 
Description: Finds and returns the number of twin primes in the given array. 
             A twin prime are two prime numbers with a difference of two.

     Inputs: primes  -- The array that represents numbers, with prime numbers
                        (as indexes) being TRUE (1). Array[i] as true
                        (1) means i is a prime. Array[i] as false (0) means it
                        is not a prime.
             size    -- The size of the array passed in.

    Outputs: Outputs the amount of twin primes found (int).
******************************************************************************/
int twin_primes(const int primes[], int size)
{
  int i;              /* Loop iterator.                                      */
  int prime_num = 0;  /* The amount of prime numbers currently.              */
  int last_prime = 2; /* Holds the last known prime. Two is the first prime. */
  
  /* Loop through primes array starting from first prime, which is 2. */
  for(i = 2; i < size; i++)
  { 
    /* Is the number prime? */
    if(primes[i] == TRUE)
    {
      /* Compare with the last prime numbers. Is the difference two? */
      if((i - last_prime) == 2)
      {
        /* Print the prompt while preincrementing the number of twin_primes. */
        printf("twin prime #%4i: %4i and %4i\n", ++prime_num, last_prime, i);
      }
      /* Set last_prime for use in next iteration. */
      last_prime = i;
    }
  }
  /* Return the number of twin primes found. */
  return prime_num;
}

/******************************************************************************
   Function: brun_constant
 
Description: Finds the sum of all the reciprocals of the sum of all twin primes
             found in primes. This sum is also known as Brun's Constant.

     Inputs: primes  -- The array that represents numbers, with prime numbers
                        (as indexes) being TRUE (1). Array[i] as true
                        (1) means i is a prime. Array[i] as false (0) means it
                        is not a prime.
             size    -- The size of the array passed in.

    Outputs: Outputs the brun constant calculated (double)
******************************************************************************/
double brun_constant(const int primes[], int size)
{  
  int i;              /* Loop iterator.                    */
  double output = 0;  /* The Brun's constant to output.    */
  
  /* Loop through the primes array from 2. */
  for(i = 2; i < size; i++)
  {
    /* Is the number prime? */
    if(primes[i] == TRUE)
    {
      /* Is the supposed twin number a prime? */
      if(primes[i + 2] == TRUE)
      {
        /* Add the sum of the reciprocals of the two primes to output. */
        output += (1.0 / i) + (1.0 / (i + 2));
      }
    }
  }
  /* Return the calculated Brun's constant. */
  return output;
}