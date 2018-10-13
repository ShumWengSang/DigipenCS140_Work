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
  
  /* 1 and 0 are not prime. We don't care about negative ints here. */
  if(number < 2)
  {
    /* Not prime, return false. */
    return FALSE;
  }
  
  /* If number is 2, return true. We know 2 is prime. */
  if(number == 2)
  {
    /* Prime number. */
    return TRUE;
  }
  
  /* Loop through all odd numbers from 3 to half the number. */
  for(i = 3; i < number / 2; i += 2)
  {
    /* 
     * Prime numbers are only divisible by itself. Thus anything that
     * can divide it and give a remainder of 0 means its divisible. Thus
     * not a prime number.
     */
    if(i % number != 0)
    {
      /* Just return false.*/
      return FALSE;
    }
  }
  /* Passed the test. Thus it should be a prime. */
  return TRUE;
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
  low++;
  high++;
}