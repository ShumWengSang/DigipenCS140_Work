#include <stdio.h>

int main(void)
{
  int userinput;
  int temp;
  int i;
  int sum = 0;
  int product = 1;
  
  printf("Enter an integer (1 to 2,147,483,647 without commas):");
  
  scanf("%i", &userinput);
  temp = userinput;
  
  for(i = 0; temp > 0; i++)
  {
    sum += temp % 10;
    product *= temp % 10;
    temp/= 10;
  }
  
  printf("The sum of the digits in %i is %i.\n",userinput, sum);
  printf("The product of the digits in %i is %i.\n", userinput, product);

  return 0;
}