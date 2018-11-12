/******************************************************************************
filename              dice1.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   10
due date              12/07/2018

Brief Description:
  Practice Assigment 10. Holds the definition of is_anagram, a function that
  checks if two words are anagrams.
  
******************************************************************************/
#include <stdlib.h> /* qsort */

#define MAXCHARS   30   /* The maximum of chars in a char array, by Mead. */
#define TRUE        1   /* True is 1.                                     */
#define FALSE       0   /* False is 0.                                    */
/**************************************************************************
   Function: compare
 
Description: A function that compares two integers by subtraction.

     Inputs: a - First pointer to integer to compare.
             b - Second pointer to integer to compare.

    Outputs: The output determines which integer goes first.
             If return value < 0, it means a goes before b.
             If return value == 0, it means no change.
             If return value > 0, it means b goes before a.
**************************************************************************/
int compare (const void * a, const void * b)
{
  /* Cast both numbers into int pointers, then dereference, then subtract. */
  return ( (*(char*)a) - (*(char*)b));
}

/**************************************************************************
   Function: copy
 
Description: Copies the contents of target into destination.

     Inputs: target      - The char array to copy from.
             destination - The char array to copy to.
             size        - The size of arrays.

    Outputs: Whether both words are anagrams. 1 for true, 0 for false.
**************************************************************************/
void copy (const char target[], char destination[], int size)
{
  int i; /* Loop variable */
  
  /* Loop over each element in target. */
  for(i = 0; i < size; i ++)
  {
    /* Copy the elements into destination. */
    destination[i] = target[i];
  }
}

/**************************************************************************
   Function: is_equal
 
Description: Determines whether two char arrays elements are equal
             in the same index ie a[2] == b[2]

     Inputs: arr1 - The first array to check.
             arr2 - The second array to check.
             size - The size of arrays.

    Outputs: Returns whether the two arrays are equal. 1 for success
             0 for failure.
**************************************************************************/
int is_equal(const char arr1[], const char arr2[], int size)
{
  int i;  /* Loop variable */
  
  /* Loop through array. */
  for(i = 0; i < size; i++)
  {
    /* If the elements are different. */
    if(arr1[i] != arr2[i])
    {
      /* Means the arrays are different. Return a 0 for failure. */
      return FALSE;
    }
  }
  /* All elements are equal. Return a 1 for success. */
  return TRUE;
}

/**************************************************************************
   Function: is_anagram
 
Description: Checks if two words are anagrams by using the <stdlib.h> qsort.

     Inputs: word1 - The first word, in C-string literals.
             word2 - The second word, in C-string literals.
             size  - The size of the array to sort.

    Outputs: Whether both words are anagrams. 1 for true, 0 for false.
**************************************************************************/
int is_anagram(const char word1[], const char word2[], int size)
{
  /* We declare two arrays that are copies that we can modify. */
  char word1_cpy [MAXCHARS] = {0};  /* First temp array, init all to 0.  */
  char word2_cpy [MAXCHARS] = {0};  /* Second temp array, init all to 0. */
  
  /* We put the contents of the words into the cpy arrays. */
  copy(word1, word1_cpy, size);
  copy(word2, word2_cpy, size);
  
  /* 
   * Sorts the two cpy arrays from smallest ASCII to highest. 
   * Thus all the same letters would be in the same elements.
   */
  qsort(word1_cpy, size, sizeof(char), compare);
  qsort(word2_cpy, size, sizeof(char), compare);

  /* Check if each element is the same in both copies. */
  if(is_equal(word1_cpy, word2_cpy, size))
  {
    /* They are the same, return 1. */
    return TRUE;
  }
  /* The two words are not equal. Return 0. */
  return FALSE;
}