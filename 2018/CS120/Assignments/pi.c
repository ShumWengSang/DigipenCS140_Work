#include <math.h> /*sqrt */

#define RADIUS 2.0
#define TWO_FACTOR 2.0
#define NUMERATOR 1.0
#define POSITIVE 1
#define NEGATIVE -1
double circle_pi(int rectangles)
{
  int i; /*loop variable*/

  double halfwidth;  /* Half of the width a rectangle.   */
  double totalArea;  /* Holds the total area for return. */
  
  /*Set to zero. */
  totalArea = 0;
  
  /* Width = (radius / number of rectangles). Divide by two to get half of it. */
  halfwidth = (RADIUS / rectangles ) / TWO_FACTOR;  
  
  for(i = 1; i <= rectangles; i++)
  { 
    double length; /* The calculated length, used to find height.       */
    double height; /* The height, used to find the area of the new rec. */
    
    /* 
     * Calculate the midpoint of the current rectangle by
     * (width * previous iteration number) + halfwidth
     */
    length = (halfwidth * TWO_FACTOR) * (i - 1) + halfwidth;

    /* Calc height by distance formula. */
    height = sqrt((RADIUS * RADIUS) - (length * length));
    
    /* Find new area and add to total, using base * height. */
    totalArea =  totalArea + (halfwidth * TWO_FACTOR * height);
  }
  
  return totalArea;
}

double leibniz_pi(int iterations)
{
  double totalOutcome = 0;  /* The result of adding all the numbers. */
  
  /* Exits loop when iteration is 0. */
  while(iterations)
  {
    int sign; /* The sign of the number. */
    
    /* Denominator is determined by pattern, (n * 2) - 1 where n is the current term number. */
    int denominator = (iterations * 2) - 1; 
    
    /* Determine the sign of the number based on whether iteration is even or odd. */
    sign = (iterations % 2) == 0 ? NEGATIVE : POSITIVE;
    
    /*Calculate the inverse of denominator. Attach the sign to it. Add to totalOutcome. */
    totalOutcome += (sign * (NUMERATOR / denominator));
    
    /*Move to next number. */
    iterations--;
  }
  
  /* totalOutcome gives (pi / 4), so we times 4 to give pi. */
  return 4 * (totalOutcome);
}