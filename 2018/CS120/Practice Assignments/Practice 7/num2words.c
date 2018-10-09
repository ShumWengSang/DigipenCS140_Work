#include <stdio.h>

void number_to_words(int number)
{
  /* We assume all numbers passed are two digits. */
  int digits[2];
  
  /* Get the 10th and 1st place digit numbers. */
  digits[1] = number % 10;
  digits /= 10;
  digits[0] = number % 10;
  
  switch(digits[1])
  {
    case 2:
    break;
    case 3:
    break;
    case 4:
    break;
    case 5:
    break;
    case 6:
    break;
    case 7:
    break:
    case 8:
    break;
    case 9:
    break;
    default:
    break;
  }
}