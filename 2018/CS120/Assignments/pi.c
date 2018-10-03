#include <math.h> /*sqrt */

#define RADIUS 1.0
#define TWO 2.0
double circle_pi(int rectangles)
{
  int i; /*loop variable*/

  double halfwidth;
  double totalArea;
  
  totalArea = 0;
  halfwidth = (rectangles / RADIUS) / TWO;
  
  for(i = 0; i < rectangles; i++)
  { 
    double midpoint;
    double height;
    /* Calculate the midpoint of the current rectangle by
     * (width * previous iteration number) + halfwidth
     */
    midpoint = (halfwidth * TWO) * (i - 1) + halfwidth;
    
    /* Calc height by distance formula. r is 1, so r^2 is also one. */
    height = sqrt(midpoint * midpoint - RADIUS);
    
    /* Find new area and add to total, using base * height */
    totalArea += midpoint * height;
  }
  
  return totalArea;
}

double leibniz_pi(int iterations)
{
  iterations += 1;
  return 0;
}