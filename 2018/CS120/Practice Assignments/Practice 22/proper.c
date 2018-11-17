/******************************************************************************
filename              reversewords.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   21
due date              12/07/2018

Brief Description:
  Practice Assigment 21. Definition of proper, a function that converts a file
  that is in all uppercase and coverts it to Proper Case. Ie "I LOVE TO EAT."
  to "I love to eat." 
*******************************************************************************/
#include <stdio.h> /* fgetc, fopen, fclose, ungetc, EOF, NULL */
#include <ctype.h> /* isspace , tolower                       */

#define LONGEST_CHAR_COUNT 200 /* We can assume the longest line is 200 long. */
#define TRUE 1                 /* Magic number for true.                      */
#define FALSE 0                /* Magic number for false.                     */
/*******************************************************************************
   Function: my_ispunctuation
 
Description: Given a char, returns true (1) if it is an '!', '.',or '?'.
             Else returns false.

     Inputs: c - The char to determine the punctuation.

    Outputs: Returns true (1) if it is an '!', '.', or '?'. Else returns false.
*******************************************************************************/
int my_ispunctuation(char c)
{
  return (c == '!' || c == '.' || c == '?' );
}

/*******************************************************************************
   Function: proper
 
Description: Given a filename, opens the file if possible, and prints out the 
             content, which should be in all uppercase, in proper form by 
             calling print_proper. Ie "I LOVE CODING IN C." becomes "I love 
             coding in c."

     Inputs: filename - The c-string name of the file to open.

    Outputs: None.
*******************************************************************************/
void proper(const char *filename)
{
  FILE *file = NULL;
  char buffer = 0; /* Buffer to hold lines from file. */
  
  /* bool to hold whether we have passed a '.', '?', or '!' .*/
  int b_punc_reached = 1; 
  
  /* Open file, if opening failed, ends function. */
  if((file = fopen(filename, "rt")) == NULL)
  {
    printf("Can't open %s.\n", filename);
    return;
  }
  
  /* Read to end of file and store each read char into buffer.*/
  while((buffer = fgetc(file)) != EOF)
  {
    /* If this is the first word after a punctuation and if it is not a space */
    if(b_punc_reached && !isspace(buffer))
    {
      /* We leave it uppercase. */
      printf("%c", buffer);
      
      /* We have printed one uppercase, we can now set the rest to lower. */
      b_punc_reached = 0;
    }
    else /* Else we print as normal. */
    {
      printf("%c", tolower(buffer));
      
      /* If the current character is a '.', we check if the next is a space. */
      if(my_ispunctuation(buffer))
      {
        /* Take the next char to check if it is a space. */
        char nextChar = fgetc(file);
        
        /* Check if it is space... */
        if(isspace(nextChar))
        {
          /* Print it out. */
          printf("%c", nextChar);
          
          /* Set b_punc_reached to true to make next letter upper. */
          b_punc_reached = 1;
        }
        else
        {
          /* Nothing of importance. Put it back into the stream. */
          ungetc(nextChar, file);
        }
      }
    }
  }
  
  /* We have finished the file. Time to close it. */
  fclose(file);
}

