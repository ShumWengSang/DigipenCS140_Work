/***************************************************************************
filename    palindrome2.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
Assignment  3
due date    10/25/2018

Brief Description:
  Assigment 3. Definition of isPalindrome. We check if the given phrase is a
  palindrome by use of pointers.
***************************************************************************/

/**************************************************************************
   Function: is_palindrome2
 
Description: Determines if the given char pointer is a palindrome by checking
             its element values. 

     Inputs: phrase -- Char pointer to the beginning of phrase.
             length -- The length of continguous chars. AKA length of phrase.

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