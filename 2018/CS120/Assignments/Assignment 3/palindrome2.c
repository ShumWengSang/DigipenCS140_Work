/***************************************************************************
filename    palindrome2.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
Assignment  3
due date    10/24/2018

Brief Description:
  Assigment 3. Definition of isPalindrome2. We use pointers to move through
  memory to check if the given phrase is a palindrome.
***************************************************************************/

/**************************************************************************
   Function: is_palindrome2
 
Description: Determines if the given char pointer is a palindrome by checking
             its element values. We do this by checking if the left and 
             right end memory holds the same values, and moving through 
             contingious memory.

     Inputs: phrase -- The word to check if it is a palindrome
             length -- The length of the array passed in.

    Outputs: If the given phrase is a palindrome. 1 for TRUE. 0 for FALSE.
**************************************************************************/
int is_palindrome2(const char *phrase, int length) 
{
  int i; /* Loop varaible. */
  
  /* Loop over half the phrase. We compare the two ends of the phrase. */
  for(i = 0; i < (length / 2); i++)
  { 
    /* Dereference the left and right end, check if not match. */
    if(*(phrase + i) != *(phrase + (length - 1 - i)))
    {
      /* Not match. Return 0. */
      return 0;
    }
  }
  
  /* All the left side matches the right side. Is palindrome. */
  return 1;
}