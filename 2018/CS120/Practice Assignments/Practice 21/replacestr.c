/******************************************************************************
filename              replacestr.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   21
due date              12/07/2018

Brief Description:
  Practice Assigment 21. Definition of print_replace and replcestr. 
*******************************************************************************/
#include <stdio.h>      /* fopen, fclose, fgets, NULL */
#include <string.h>     /* strstr, strlen             */
#include "replacestr.h" /* feNONE, feINPUT            */

/*******************************************************************************
   Function: replacestr
 
Description: Given a c-string, prints the string onto the console while 
             substituting each substring of oldstr with newstr.

     Inputs: string - C-string to be printed on the console.
             oldstr - C-string substring of word to substitute.
             newstr - C-string substring of word to substitute with.

    Outputs: Returns feINPUT on file open failure, otherwise returns feNONE.
*******************************************************************************/
static void print_replace(const char *string, 
                          const char *oldstr, 
                          const char *newstr)
{
  char *head = NULL;  /* Pointer to find the start of the substring, oldstr. */
  int index = 0;      /* The current index of the string as we move it.      */
  
  /* Find the substring and point head to it. */
  while((head = strstr(string + index, oldstr)) != NULL)
  {
    /* Print everything up until we hit the substring. */
    for( /* Empty */ ; (string + index) != head; index++)
    {
      /* Print char by char the deferenced value. */
      printf("%c", *(string + index));
    }
    /* Print out the newstr in place of the oldstr. */
    printf("%s", newstr);

  /* Advance the index by the length of oldstr. */
  index += strlen(oldstr);
  }
  
  /* Print the rest of the string. */
  printf("%s", string + index);
  
}

/*******************************************************************************
   Function: replacestr
 
Description: Given a c-string filename, prints the file's text lines onto the
             console, while substituting the oldstr substrings with newstr.

     Inputs: filename  - C-string filename of the file to be printed to console.
             oldstr    - C-string substring of word to substitute.
             newstr    - C-string substring of word to substitute with.

    Outputs: Returns feINPUT on file open failure, otherwise returns feNONE.
*******************************************************************************/
enum FILE_ERR replacestr(const char *filename, 
                         const char *oldstr, 
                         const char *newstr)
{
  FILE *filestream = NULL;  /* Pointer to the file stream. */
  
  /* Opens the file and check if there was a problems opening it. */
  if((filestream = fopen(filename, "r")) == NULL)
  {
    /* Return file error. */
    return feINPUT ;
  }
  
  /* 
   * We only break in the breakpoint below because we want buffer 
   * to deallocate. */
  while(1)
  {
    char buffer[LINE_MAX] = {0}; /* Buffer to hold the current read line. */
    
    /* Copies the current line into buffer, while checking if EOF. */
    if(fgets(buffer, LINE_MAX, filestream) == NULL)
    {
      /* Get out of the loop if the end of file is reached. */
      break;
    }
    /* Print the string while replacing oldstr with newstr. */
    print_replace(buffer, oldstr, newstr);
  }
  
  /* Close file. */
  fclose(filestream);
  
  /* Return no error. */
  return feNONE;
}