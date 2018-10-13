/******************************************************************************
filename    bsort.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
week        9
due date    12/07/2018

Brief Description:
  Practice Assigment 9. Holds the definition of bsort, where given an integer
  array it will sort using the bubble sort method.
  
******************************************************************************/

/**************************************************************************
   Function: bsort
 
Description: Takes in an array and its size and sorts it from smallest to
             greatest using bubble sort.

     Inputs: array -- The array to sort.
             size  -- The size of the array to sort.

    Outputs: Void
**************************************************************************/
void bsort(int array[], int size)
{
  /* Keep track of how many swaps. It is 1 to go into while loop. */
  int amount_of_swaps = 1;
  
  /* 
   * If there is a swap, that means not all elements 
   * are in proper position. If no swap, exit the loop.
   */
  while(amount_of_swaps)
  { 
    int i;  /* Loop variable. */
    
    /* We reset this every loop. */
    amount_of_swaps = 0;  
    
    /* We loop to the second last variable. */
    for(i = 0; i < size - 1; i++)
    {
      /* If left element is greater then right variable. */
      if(array[i] > array[i + 1])
      {
        /* We swap their places. Creates a copy of left var. */
        int copy = array[i];
      
        /* Sets the left var to the right element. */
        array[i] = array[i + 1];
        /* Now use the copy to set the right element to the left. */
        array[i + 1] = copy;
        
        /* We record that we did a swap. */
        amount_of_swaps++;
      }
    }
  }
}