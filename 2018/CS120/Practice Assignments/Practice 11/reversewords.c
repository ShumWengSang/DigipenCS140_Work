/******************************************************************************
filename              reversewords.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   11
due date              12/07/2018

Brief Description:
  Practice Assigment 11. Provides two functions that reverses the c-style 
  string given. Reverses means to reverse the order in which the words appear.
  
******************************************************************************/
#include <string.h> /* strlen */

#define ASCII_SPACE 32  /* ASCII representation of a space */
/**************************************************************************
   Function: reverse_words1
 
Description: Reverses word order of the given c-string and modifies output
             with it.

     Inputs: input  - C-style string to reverse the word order.
             output - Second pointer to integer to compare. Size must be 
                      greater or equal to input.

    Outputs: None. Output is the modified to fit the reversed word order 
             string.
**************************************************************************/
void reverse_words1(const char input[], char output[])
{
  /* -1 to get rid of null terminator. */
  int str_length = strlen(input) - 1;
  int i;
  char * j;
  int output_iterator = 0;
  
  /* Loop through output and set it all to null terminators. */
  for(i = 0; i < str_length; i++)
  {
    input[i] = 0;
  }
  
  /* Point to the last element of the word. */
  char * last_letter_of_word = input[str_length];
  
  for(i = str_length; i >= 0; i--)
  {
    /* Find the next space. */
    if(input[i] == ASCII_SPACE)
    {
      /* The element behind to LAST_LETTER is the word. */
      /* Put the word in output. */
      for(j = &input[i]; j != last_letter_of_word; j++)
      {
        output[output_iterator++] = *j;
      }
      /* Add a space */
      output[output_iterator++] = ' ';
    }
  }
}
