#include <stdio.h>

int main(void)
{
  int userinput;
  int temp;
  int i;
  printf("Enter an integer (1 to 2,147,483,647 without commas):");
  scanf("%i", &userinput);
  temp = userinput;
  for(i = 0; temp > 0; i++)
  {
    temp/= 10;
  }
  printf("The number of digits in %i is %i", userinput, i);
  return 0;
}