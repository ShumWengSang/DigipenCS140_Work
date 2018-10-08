#include <stdio.h> /* printf, scanf       */
#include "PRNG.h"  /* ut_srand, RandomInt */
#define AMOUNT_OF_DIES 5
int main(void)
{
    /* Define your variables here. */
  int userinput;
  int i, j;
  double probablity;
  int five_of_a_kind = 0;

    /* Seed the pseudo-random number generator.                   */
    /* DON'T CHANGE THIS WHEN UPLOADING TO THE SUBMISSION SERVER! */
    /* If you change this, your output won't match when you diff. */
  ut_srand(0, 0);

  do
  {
    /* You may also define variables here, if you need to. */
    printf("How many times do you want to roll the dice? (0=quit) ");
    scanf("%i", &userinput);
    if(userinput == 0)
    {
      break;
    }
    
    for(i = 0; i < userinput; i++)
    {
      int dice[AMOUNT_OF_DIES];
      for(j = 0; j < AMOUNT_OF_DIES; j++)
      {
        dice[j] = RandomInt(1, 6);
      }
      for(j = 0, five_of_a_kind++; j < AMOUNT_OF_DIES - 1; j++)
      {
        if(dice[j] != dice[j+1])
        {
          five_of_a_kind--;
          break;
        }
      }
    }
    
    probablity = (double)five_of_a_kind / (double)userinput;
    printf("After %i rolls, you had 5 of a kind %i times.\n", userinput, five_of_a_kind);
    printf("This is a percentage of %f.\n",probablity);


  } while (1);

  return 0;
}
