#include <math.h> /*sqrt */
#include <stdio.h>
#define RADIUS 2.0
#define TWO 2.0
#define NUMERATOR 1.0
double circle_pi(int rectangles)
{
  int i; /*loop variable*/

  double halfwidth;
  double totalArea;
  
  totalArea = 0;
  halfwidth = (RADIUS / rectangles ) / TWO;
  
  for(i = 1; i <= rectangles; i++)
  { 
    double length;
    double height;
    /* 
     * Calculate the midpoint of the current rectangle by
     * (width * previous iteration number) + halfwidth
     */
    length = (halfwidth * TWO) * (i - 1) + halfwidth;

    /* Calc height by distance formula. */
    height = sqrt((RADIUS * RADIUS) - (length * length));
    /* Find new area and add to total, using base * height */
    totalArea =  totalArea + (halfwidth * TWO * height);
  }
  
  return totalArea;
}

double leibniz_pi(int iterations)
{
  double totalOutcome = 0;
  int sign;
  /* exits loop when iterations is 0. */
  while(--iterations)
  {
    int denominator = iterations + 2;
    if(iterations % 2 == 1)
    {
      /*take away*/
      sign = -1;
    }
    else
    {
      /*add to*/
      sign = 1;
    }
    totalOutcome = totalOutcome + (sign * (NUMERATOR / denominator));
  }
  return 4 * (1 + totalOutcome);
}