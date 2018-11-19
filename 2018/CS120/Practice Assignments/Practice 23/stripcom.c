/******************************************************************************
filename              stripcom.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   23
due date              12/07/2018

Brief Description:
  Practice Assigment 23. Definition of stripcom. 
*******************************************************************************/
#include <stdio.h>  /* fgetc, ungetc, fopen, fclose, printf, EOF */

/*******************************************************************************
   Function: stripcom
 
Description: Given a c-string filename, opens the file and writes its content
             to the console, while ignoring any characters within C-style
             comments.

     Inputs: filename - The name of the file to open for reading.

    Outputs: None
*******************************************************************************/
void stripcom(const char *filename)
{
  FILE *file = NULL;      /* Pointer to the file stream for io.          */
  char buffer = 0;        /* Buffer to hold the current char from fgetc. */
  int b_incomments = 0;   /* Variable to see if we are in comments.      */
  int b_instring = 0;     /* Variable to see if we are in a string.      */
  
  /* If we fail the opening and assigning of the file */
  if((file = fopen(filename, "rt")) == NULL)
  {
    /* Print prompt and end function. */
    printf("Can't open %s\n", filename);
    return;
  }
  
  /* Read the current char and store in buffer, until the end of file. */
  while((buffer = fgetc(file)) != EOF)
  {
    /* If we are reading comments, */
    if(b_incomments)
    {
      /* We detect if it is an end comment signature that starts with '*' */
      if(buffer == '*')
      {
        /* We see if it ends with '/'. */
        char buffer_two = fgetc(file);
        if(buffer_two == '/')
        {
          /* This combination is a comment ender. Set b_incommnets to 0. */
          b_incomments = 0;
        }
        else
        {
          /* Put the letter back into the stream so it doesn't screw the algo */
          ungetc(buffer_two, file);
        }
      }
    }
    else  /* If we are not reading comments. */
    {
      /* If we are reading a string. */
      if(b_instring)
      {
        /* We need to handle it if it is the end of the string. */
        if(buffer == '"')
        {
          /* End of string. Set to 0. */
          b_instring = 0;
        }
        
        /* Either case, we still need to print it out. */
        printf("%c", buffer);
      }
      else /* This is not a string, so comments apply. */
      {
        /* We read if it is a start comment signature. */
        if(buffer == '/')
        {
          /* We see if it ends with '*'. */
          char buffer_two = fgetc(file);
          if(buffer_two == '*')
          {
            /* This combination is a comment start. Set b_incommnets to 0. */
            b_incomments = 1;
          }
          else
          {
            /* Its just an ordinary word. Print it out. */
            printf("%c%c", buffer, buffer_two);
          }
        }
        else if(buffer == '"')  /* We are reading a string now. */
        {
          /* Set the variable for string to true. */
          b_instring = 1;
          
          /* We still need to print out the char. */
          printf("%c", buffer); 
        }
        else  /* Nothing special. Print out as normal. */
        {
          printf("%c", buffer);
        }
      }
    }
  }
  
  /* Close the file. */
  fclose(file);
}