/***************************************************************************
filename    palindrome2.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
Assignment  3
due date    10/24/2018

Brief Description:
  Assigment 3. Definition of isPalindrome. We use the array to check whether
  the array is a palindrom
***************************************************************************/

/**************************************************************************
   Function: is_palindrome2
 
Description: Determines if the given char pointer is a palindrome by checking
             its element values. We do this by checking if the left and 
             right end memory holds the same values.

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
    /* If left end and right end do not match. */
    if(*(phrase + i) != *(phrase + (length - 1 - i)))
    {
      return 0;
    }
  }
  
  /* The left side matches the right side. Is palindrome. */
  return 1;
}