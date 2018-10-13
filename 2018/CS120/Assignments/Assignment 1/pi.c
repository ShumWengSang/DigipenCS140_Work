/******************************************************************************
filename    pi.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
week        5
due date    09/10/2018

Brief Description:
  The file contains the function definitions for cirple_pi and
  leibniz_pi. Both functions return PI by using two different methods.
  
******************************************************************************/
#include <math.h> /* sqrt */

#define RADIUS 2.0
#define TWO_FACTOR 2.0
#define POSITIVE 1
#define NEGATIVE -1
/**************************************************************************
   Function: circle_pi
 
Description: Takes in n amount of rectangles and calculates the approximate
             area of a quater of a circle by filling n amount of rectangles
             into it, and calculating the area of all the rectangles. This is 
             also known as PI. Radius of the circle is given to be 2.
       
     Inputs: rectangles -- The amount of rectangles to fit onto the quarter
             circle
   
    Outputs: The approximatarea amount of PI, also the area of the quarter
             circle.
**************************************************************************/
double circle_pi(int rectangles)
{
  int i; /*loop variable*/

  double halfwidth;  /* Half of the width a rectangle.   */
  double totalArea;  /* Holds the total area for return. */
  
  /*Set to zero. */
  totalArea = 0;
  
  /* 
   * Width = (radius / number of rectangles). 
   * Divide by two to get half of it. 
   */
  halfwidth = (RADIUS / rectangles) / TWO_FACTOR;  
  
  for(i = 1; i <= rectangles; i++)
  { 
    double base;   /* The base of the triangle, used to find height.    */
    double height; /* The height, used to find the area of the new rec. */
    
    /* 
     * Calculate the midpoint of the current rectangle by
     * (width * previous iteration number) + halfwidth
     */
    base = (halfwidth * TWO_FACTOR) * (i - 1) + halfwidth;

    /*
     * Use the midpoint to find the height, Pythagoreas Theorem
     * height^2 = (r^2 - b^2)
     */
    height = sqrt((RADIUS * RADIUS) - (base * base));
    
    /* Find new area and add to total, using base * height. */
    totalArea =  totalArea + (halfwidth * TWO_FACTOR * height);
  }
  
  /* Return the total area. */
  return totalArea;
}

/**************************************************************************
   Function: leibniz_pi
 
Description: Takes in n amount of iterations and returns the approximate
             value of a quarter of PI, by the leibniz formula. The formula is
             quarter_of_PI = 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 ... 
             Notice that if we let n be the nth term in the formula, the formula
             to find the denominator becomes (n * 2) - 1.
       
     Inputs: rectangles -- The amount of rectangles to fit onto the quarter
             circle
   
    Outputs: The approximatarea amount of PI.
**************************************************************************/
double leibniz_pi(int iterations)
{
  double totalOutcome = 0;  /* The result of adding all the numbers. */
  
  /* 
   * Determine the sign of the last number based on whether
   * iteration is even or odd. Even is negative, odd is positive.
   */
  int sign = (iterations % 2) == 0 ? NEGATIVE : POSITIVE;
  
  /* Exits loop when iteration is 0. */
  while(iterations)
  {    
    /* 
     * Denominator is determined by pattern, 
     * (n * 2) - 1 where n is the current term number.
     */
    int denominator = (iterations * 2) - 1; 
    
    /* 
     * Calculate the inverse of denominator. 
     * Attach the sign to it. Add to totalOutcome. 
     */
    totalOutcome += (sign * (1.0 / denominator)); 
    
    /* Flip the sign when going to next iteration. */
    sign *= -1;
    
    /* Move to next number. */
    iterations--;
  }
  
  /* totalOutcome gives (pi / 4), so we times 4 to give pi. */
  return 4 * (totalOutcome);
}