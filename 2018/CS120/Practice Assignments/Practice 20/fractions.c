/******************************************************************************
filename              fractions.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   20
due date              12/14/2018

Brief Description:
  Practice Assigment 20. 
*******************************************************************************/
#include "fractions.h"
/*******************************************************************************
   Function: GCD
 
Description: Given two ints, finds the GCD (greaters common divisor) of both
             numbers. 

     Inputs: a - An int number above 0.
             b - An int number above 0.

    Outputs: The GCD of both a and b.
*******************************************************************************/
int GCD(int a, int b)
{
  int m, n; /* The two numbers. */
  int r;    /* Remainder */

  /* Handle a being negatives. */
  if (a < 0)
  {
    a *= -1;
  }
  /* Handle b being negative. */
  if (b < 0)
  {
    b *= -1;
  }
  
  /* Handle 0 cases. If either a or b is 0. */
  if(a == 0 || b == 0)
  {
    /* If b is 0, we return a. */
    if(a > b)
    {
      return a;
    }
    /* If a is 0, we return b. */
    else if (a < b)
    {
      return b;
    }
    /* If they are both 0, we return 0. */
    else
    {
      return 0;
    }
  }
  
  /* M must be bigger then N. */
  if(a > b)
  {
    /* A is bigger, so set it to M. */
    m = a;
    n = b;
  }
  else
  {
    /* B is bigger, so set that to M. */
    m = b;
    n = a;
  }
  /* Assign the remainder of m/n to r */
  r = m % n;
  
  /* Loop, while remainder is no 0. */
  while (r != 0)
  {
    m = n;      /* M is now N.       */
    n = r;      /* N is now R.       */
    r = m % n;  /* Refind remainder. */
  }
  /* Return the greater common divisor. */
  return n;
}

/*******************************************************************************
   Function: add_fractions
 
Description: Given two FRACTIONS, add them as you would a normal fraction, and
             return the result.

     Inputs: a - The first FRACTION to add.
             b - The second FRACTION to add.

    Outputs: A fraction that is the result of fraction adding (a + b)
*******************************************************************************/
struct FRACTION add_fractions(const struct FRACTION *a, 
                              const struct FRACTION *b)
{
  struct FRACTION result; /* The result of the operation. */
  int greatest_common_deno; /* GCD of result's numerator and demonimator. */
  
 /*
  *  AA    BB       
  *  
  *  A     C       AD     BC       AD + BC            
  * --- + ---  =  ---- + ----  =  ---------
  *  B     D       BD     BD          BD     
  * 
  * Denominator = aa.dem * bb.dem
  * Num = aa.num * bb.dem + bb.num * aa.dem
  */
  result.denominator = a->denominator * b->denominator;
  result.numerator = a->numerator * b->denominator;
  result.numerator += b->numerator * a->denominator;
  
  /* Find the GCD to simplify fraction. */
  greatest_common_deno = GCD(result.numerator, result.denominator);
  
  /* If it is greater then 0, then we simplify. */
  if(greatest_common_deno > 1)
  {
    /* Divide by GCD to simplify. */
    result.numerator /= greatest_common_deno;
    result.denominator /= greatest_common_deno;
  }
  /* Return the result. */
  return result;
}

/*******************************************************************************
   Function: subtract_fractions
 
Description: Given two FRACTIONS, subtract them as you would a normal fraction,
             and return the result.

     Inputs: a - The first FRACTION to subtract.
             b - The second FRACTION to subtract.

    Outputs: A fraction that is the result of fraction subtract (a - b)
*******************************************************************************/
struct FRACTION subtract_fractions(const struct FRACTION *a,
                                   const struct FRACTION *b)
{
  /* Copy the struct over so we can modify it. */
  struct FRACTION neg_b = *b;
  
  /* Make b's copy a negative version of it. */
  neg_b.numerator *= -1;
  
  /* a - b is the same as a + (-b) */
  return add_fractions(a, &neg_b);
}

/*******************************************************************************
   Function: multiply_fractions
 
Description: Given two FRACTIONS, multiply them as you would a normal fraction,
             and return the result.

     Inputs: a - An int number above 0.
             b - An int number above 0.

    Outputs: The GCD of both a and b.
*******************************************************************************/
struct FRACTION multiply_fractions(const struct FRACTION *a, 
                                   const struct FRACTION *b)
{
  struct FRACTION result; /* Result of the operation. */
  int greatest_common_deno; /* GCD for simplification.  */
  
  /*
   * a      c      a * c
   *--- *  ---  = -------
   * b      d      b * d
   * 
   * Multiply denominators to get resultant denominator
   * Multiply numerators to get resultant numerator
   */
  result.numerator = a->numerator * b->numerator;
  result.denominator = a->denominator * b->denominator;

  /* Find the GCD to simplify fraction. */
  greatest_common_deno = GCD(result.numerator, result.denominator);

  /* If it is greater then 0, then we simplify. */
  if (greatest_common_deno > 1)
  {
    /* Divide by GCD to simplify. */
    result.numerator /= greatest_common_deno;
    result.denominator /= greatest_common_deno;
  }
  /* Return the result. */
  return result;
  
  /* Return the result. */
  return result;
}

/*******************************************************************************
   Function: GCD
 
Description: Given two ints, finds the GCD (greaters common divisor) of both
             numbers. 

     Inputs: a - An int number above 0.
             b - An int number above 0.

    Outputs: The GCD of both a and b.
*******************************************************************************/
struct MIXED_FRACTION reduced_to_mixed(const struct FRACTION *fraction)
{
  struct MIXED_FRACTION result; /* The result to store and return.        */
  int b_is_neg = 0;      /* boolean to check if fraction is a neg number. */
  
  /* Set the incoming fraction to result fraction so we can modify. */
  result.proper_fraction = *fraction;
  
  /* Set the whole number to 0 at first. */
  result.whole_number = 0;
  
  /* If the fraction is a negative, we begin by checking if either are neg. */
  if(fraction->numerator < 0 || fraction->denominator < 0)
  {
    /* If both are negative, its a positive number. */
    if(fraction->numerator < 0 && fraction->denominator < 0)
    {
      /* Set both numerator and denominator to positve.*/
      result.proper_fraction.numerator *= -1;
      result.proper_fraction.denominator *= -1;
    }
    else if(fraction->numerator < 0)  /* The numerator is negative only. */
    {
      /* Set the numerator to be positive, and record that it is a negative. */
      result.proper_fraction.numerator *= -1;
      b_is_neg = 1;
    }
    else /* else the denominator is negative */
    {
      result.proper_fraction.numerator *= -1;
      b_is_neg = 1;
    }
  }
  
  /* The fraction is ready. While the numerator is greater then denominator, */
  while(result.proper_fraction.numerator >= result.proper_fraction.denominator)
  {
    /* If numerator is 0, then its a whole number and we can break out. */
    if (result.proper_fraction.numerator == 0)
    {
      break;
    }
    /* Subtract one value worth of denominator from numerator. */
    result.proper_fraction.numerator -= result.proper_fraction.denominator;
    
    /* We increase the whole number count. */
    result.whole_number++;
  }
  
  /* Was the original number a negative number? */
  if(b_is_neg)
  {
    /* Set the numerator to negative. */
    result.proper_fraction.numerator *= -1;
  }
  
  /* Return the result */
  return result;
}
