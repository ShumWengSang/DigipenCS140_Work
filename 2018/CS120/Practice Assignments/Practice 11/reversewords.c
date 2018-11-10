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
             output - Output array that will be overriten by the reverse
                      of input. Size must be greater then or equal to input.

    Outputs: None. 
**************************************************************************/
void reverse_words1(const char input[], char output[])
{
  /* Length of the string */
  int str_length = strlen(input);
  
  int i;                   /* Loop variable.                  */
  const char *j;           /* Loop variable, pointer to char. */
  int output_iterator = 0; /* Current index of the output array. */
  
  /* Point to the last element of the word. */
  const char *tail = &input[str_length];
  
  /* Loop through output and set it all to null terminators. */
  for(i = 0; i < str_length; i++)
  {
    output[i] = 0;
  }
  
  /* Loop through the string backwards.*/
  for(i = str_length; i >= 0; i--)
  {
    /* Find the next space, or null terminator */
    if(input[i] == ASCII_SPACE)
    {
      /* 
       * The element behind us the start of the word. Loop from where we are
       * till the tail, while copying our content to the output string.
       * j points to first letter of word, tail to end of word.
       */

      for(j = &input[i + 1]; j != tail; j++, output_iterator++)
      {
        /* Copy current char to output buffer, based on output's iterator. */
        output[output_iterator] = *j;
      }
      
      /* Add a space */
      output[output_iterator++] = ' ';
      
      /* Set the tail in anticipation of next loop. */
      tail = &input[i];
    }
  }
  
  /* End of string, one more reverse to do for the first word. */
  for(j = &input[0]; j != tail; j++, output_iterator++)
  {
    /* Copy current char to output buffer, based on output's iterator. */
    output[output_iterator] = *j;
  }
  
  /* Add a char terminator at the end.*/
  output[output_iterator] = 0;
  
}

/**************************************************************************
   Function: reverse
 
Description: Helper function that reverses the letters of an array around.

     Inputs: start  - The head of the char array to reverse.
             end    - The end of the char array to reverse.

    Outputs: None.
**************************************************************************/
void reverse(char *start, char *end)
{
  /* If the pointers move past each other, end operation. */
  while (start < end)
  {
      char temp; /* Temporary holder of the current char. */
      
      /* Set the temp to hold the start value. */
      temp = *start;
      
      /* Swap the values of the head and end.*/
      *start = *end;
      *end = temp;
      
      /* Move the pointers to the next letters to reverse. */
      start++;
      end--;
  }
}

/**************************************************************************
   Function: reverse_words2
 
Description: Reverses word order of the given c-string and modifies input
             with it.

     Inputs: input - C-style string to reverse the word order. Result will
                     modify given string.

    Outputs: None.
**************************************************************************/
void reverse_words2(char input[])
{
  int i;                       /* Loop iterator.                       */
  int str_len = strlen(input); /* lengh of the string.                 */
  char * head = &input[0];     /*  Pointer to first letter to reverse. */
  
  /* Reverse the entire string first. */
  reverse(input, &input[str_len - 1] );
  
  /* Run through the entire string. */
  for( i = 0; input[i] != 0; i++)
  {
    /* Find the next space. */
    if(input[i] == ASCII_SPACE)
    {
      /*
       * We are at the end of the word. The char behind is the last letter,
       * so reverse the word given head and tail. 
       */
       reverse(head, &input[i - 1]);
       
       /* Now set the head to the start of the next word. */
       head = &input[i + 1];
    }
  }
  /* 
   * If the last char is a space, do nothing. If it is a char,
   * reverse the last word 
   */
  if(input[i - 1] != ASCII_SPACE)
  {
    /* Reverse the last word. */
    reverse(head, &input[i - 1]);
  }
}
