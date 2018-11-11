/******************************************************************************
filename              wordlen.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   18
due date              12/07/2018

Brief Description:
  Practice Assigment 18. Definition of wordlen, a function that finds the 
  average word length in a given c-string array.
*******************************************************************************/
#include <ctype.h> /* isspace */
/*******************************************************************************
   Function: average_word_length
 
Description: Given a c-string text, finds the average word length of the text.

     Inputs: text  - c-string array that the caller is trying to find the 
                     average word length.

    Outputs: Returns the average word length of the given text.
*******************************************************************************/
double average_word_length(const char *text)
{
  int i;               /* Loop variable.                       */
  int letters = 0;     /* Amount of letters found.             */
  int word_count = 0;  /* The amount of word recorded.         */
  int b_in_word = 0;   /* boolean to see if we are see a word. */
  
  /* Loop through the string forward. */
  for(i = 0; text[i] != 0; i++)
  {
    /* If we are not a white space */
    if(!isspace(text[i]))
    {
      /* Are we transitioning from whitespace to word? */
      if(!b_in_word)
      {
        /* We have just transitioned to a new word. Add to word_count. */
        word_count++;
        
        /* We are counting words now! */
        b_in_word = 1;
      } 
      /* Make sure we record we have read a non_white char. */
      letters++;
    }
    else
    {
      /* We are not transitinonig, we are white space. */
      b_in_word = 0;
    }
  }

  
  /* If words is 0 or less, AKA not a real result. */
  if(word_count <= 0)
  {
    /* return 0 */
    return 0;
  }
  else /* Else a legitimate result, */
  {
    /* return the average letters per word after calculating it. */ 
    return (double)letters / (double)word_count;
  }
}