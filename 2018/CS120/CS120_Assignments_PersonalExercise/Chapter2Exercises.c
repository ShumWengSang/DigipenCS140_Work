#include <stdio.h>
#define NUM 10000000000000000
int main (void)
{
  int i;
  for( i = 0; i < NUM; i ++)
  {
    int array[NUM];
    array[i] = i;
    
  }
  return 0;
}

