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
  char last_char = 0; /* The last read char.*/
  char second_last_char = 0; /* The second last read char. */
  char trailing_char = 0; /* The third last read char. */
  
  /* Open file, if opening failed, ends function. */
  if((file = fopen(filename, "rt")) == NULL)
  {
    printf("Can't open %s.\n", filename);
    return;
  }
  
  /* Read the first character and print it normally. */
  buffer = fgetc(file);
  printf("%c",buffer);
  
  /* Since we read a char, we should update our last_char. */
  last_char = buffer;
  
  /* Read to end of file and store each read char into buffer.*/
  while((buffer = fgetc(file)) != EOF)
  {
    /* If trialing is a punc, and last char is a space */
    if(my_ispunctuation(second_last_char) && isspace(last_char))
    {
      /* Then we leave the char is uppercase form and print. */
      printf("%c", buffer);
    }
    /* Handle new paragraph. */
    else if(second_last_char == '\n' && last_char == '\n')
    {
      /* This is actually some magic english thing I don't understand. */
      if(trailing_char == ':')
      {
        /* But just make it lowercase. */
        printf("%c", tolower(buffer));
      }
      else /* This is a legit new paragraph, so leave it be. */
      {
        /* Then we leave the char is uppercase form and print. */
        printf("%c", buffer);
      }
    }
    else /* Else it should be lowercase. */
    {
      printf("%c", tolower(buffer));
    }
    
    /* We set the last_char and second_last_char to be ready for next loop. */
    trailing_char = second_last_char;
    second_last_char = last_char;
    last_char = buffer;
  }
  
  /* We have finished the file. Time to close it. */
  fclose(file);
}

