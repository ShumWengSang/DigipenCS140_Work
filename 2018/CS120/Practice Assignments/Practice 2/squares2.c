#include <stdio.h>

int main(void)
{
  int range;
  int stride;
  
  printf("Enter two integers greater then 0: ");
  scanf("%i %i", &range, &stride);

  printf(" Value     Value^2    Value^3\n");
  printf("-----------------------------\n");
  for(; stride <= range; stride++)
  {
    printf("%5i%12i%12i\n", stride, stride * stride, stride * stride * stride);
  }
  return 0;
}