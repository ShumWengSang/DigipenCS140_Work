#include <stdio.h>

int main (void)
{
  int x = 5000;
  float i , k;
  int j;
  printf("Number is :%-8.1i\n", x);
  
  scanf("%f%i%f", &i, &j, &k);
  
  printf("Numbers inputted are %f %i %f", i,j,k);
}