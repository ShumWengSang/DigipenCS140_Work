#include <stdio.h>

int main(void)
{
  int range;
  int stride;
  

  do
  { 
    printf("Enter two integers greater then 0: ");
    scanf("%i %i", &range, &stride);
    if(range <= 0)
      continue;
    if(stride <= 0)
      continue;
  }while(range >= 1290 || range <= 0);

  printf(" Value     Value^2    Value^3\n");
  printf("-----------------------------\n");
  for(; stride <= range; stride++)
  {
    printf("%5i%12i%12i\n", stride, stride * stride, stride * stride * stride);
  }
  return 0;
}