/******************************************************************************
filename    primes1.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
week        6
due date    10/17/2018

Brief Description:
  Lab 6. Contains the definitions of is_prime and conjecture. is_prime takes
  a number and determines if it is a prime number. Conjecture takes in a range
  of numbers and show that each even number within the range is the sum of two 
  prime numbers.
  
******************************************************************************/
#include <stdio.h> /* printf */

#define FALSE 0
#define TRUE  1
/**************************************************************************
   Function: is_prime
 
Description: A function that checks if a number is a prime number.

     Inputs: number -- Number to check if it is prime.

    Outputs: Whether the integer is prime or not.
             1 is TRUE, 0 is FALSE
**************************************************************************/
int is_prime(int number)
{
  int i; /* Loop variable. */
  
  /* If number is 2, return true. We know 2 is prime. */
  if(number == 2)
  {
    /* Prime number. */
    return TRUE;
  }
  
  /* 1 and 0 are not primes. Even numbers are not primes. */
  if(number < 2 || number % 2 == 0)
  {
    /* Not prime, return false. */
    return FALSE;
  }
  
  /* Loop through all odd numbers from 3 to half the number. */
  for(i = 3; i < number / 2; i += 2)
  {
    /* 
     * Prime numbers are only divisible by itself. Thus anything that
     * can divide it and give a remainder of 0 means its divisible. Thus
     * not a prime number.
     */
    if(number % i == 0)
    {
      /* A number is divisible by it. */
      return FALSE;
    }
  }
  /* Passed the test. Thus it should be a prime. */
  return TRUE;
}

/**************************************************************************
   Function: find_conjecture
 
Description: Helper function that helps find two primes that add up to the 
             given number. This number should be even. 

     Inputs: number -- The even number to check.

    Outputs: Void.
**************************************************************************/
void find_conjecture(int number)
{
  int i, j; /* Loop variable. */
  
  /* We loop through all possible prime numbers from bottom up, up to half. */
  for(i = 0; i <= number / 2; i ++)
  {
    /* We only want to evaluate when i is prime. */
    if(!is_prime(i))
    {
      /* i is not prime, so continue to find a prime. */
      continue;
    }
    /* We do the same loop, except from the other side of possibilities. */
    for(j = number; j >= number / 2; j--)
    {
      /* Again, we only want to evaluate when j is prime.*/
      if(!is_prime(j))
      {
        /* j is not prime, so continue to find a prime. */
        continue;
      }

      /* 
       * i and j are both primes now.
       * Check if they add up to even number.
       */
      if((i + j) == number)
      {
        /* They add up. Print out the prompt. */
        printf("%3i = %3i + %3i\n", number, i, j);
        /* Return to get out of loop. */
        return;
          
      }
    }
  }
}

/**************************************************************************
   Function: conjecture
 
Description: Gets a range of numbers, and determines if the even numbers 
             within the range (inclusive) can be added by two prime numbers. 
             If it does print it out.

     Inputs: low  -- The min of the range to check.
             high -- The max of the range to check.

    Outputs: Whether the integer is prime or not.
             1 is TRUE, 0 is FALSE
**************************************************************************/
void conjecture(int low, int high)
{  
  /* If low is not an even number. */
  if(low % 2 != 0)
  {
    /* We set it to even for our loop to work. */
    low += 1;
  }

  /* Loop through all multiples of 2, which is even number. */
  for( ; low <= high; low += 2)
  {
    /* Find two prime numbers that add up to this even number. */
    find_conjecture(low);
  }
}