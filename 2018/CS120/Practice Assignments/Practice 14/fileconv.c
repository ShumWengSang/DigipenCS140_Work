/******************************************************************************
filename              reversewords.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   14
due date              12/07/2018

Brief Description:
  Practice Assigment 14. Provides two functions that convert Windows-style text 
  file to a Unix-style text file and vice versa.
******************************************************************************/
#include <stdio.h>     /* fgetc, fputc, EOF */
#include "fileconv.h"  /* enum FILE_ERR     */

/*******************************************************************************
   Function: win2unix
 
Description: Given the input and output file name, opens the windows input file
             and copies the content to the output file, converting the file to
             UNIX format whenever appropriate. If an output file of the name
             does not exist, one would be created.

     Inputs: finput  - c-string name of the input windows file.
             foutput - c-string name of the output unix file.

    Outputs: enum FILE_ERR - Error codes. feNONE means no error. feINPUT means
             cannot open input file. feOUTPUT means cannot open output file.
*******************************************************************************/
enum FILE_ERR win2unix(const char *finput, const char *foutput)
{
  /* Read in the input and output file. */
  FILE *input = fopen(finput, "rb");
  FILE *output = fopen(foutput, "wb");
  
  /* Temporary variable to hold currently read char. */
  char temp;
  
  /* Error handling, cannot open files. */
  if(input == NULL)
  {
    /* Cannot open input file. */
    return feINPUT;
  }
  else if(output == NULL)
  {
    /* Cannot open output file.*/
    return feOUTPUT;
  }
  
  /* Set temp to current character. */
  while((temp = fgetc(input)))
  {
    /* End the loop if temp is EOF*/
    if(temp == EOF)
    {
      break;
    }
    /* Could be a carriage return line feed combo. */
    if(temp == CR)
    {
      /* Get next character to see if is indeed a windows return .*/
      char second_temp = fgetc(input);
      
      /* It is a carriage return from windows. */
      if(second_temp == LF)
      {
        /* Convert to LF for UNIX. */
        fputc(LF, output);
      }
      /* Nope, false alarm. */
      else
      {
        /* Proceed as normal.*/
        fputc(temp, output);
      }
    }
    else /* We normally don't do anything special. */
    {
      /* Proceed as normal, put them in output file. */
      fputc(temp, output);
    }
  }
  
  /* All done, close files. */
  fclose(input);
  fclose(output);
  
  /* Return no error. */
  return feNONE;
}

/*******************************************************************************
   Function: unix2win
 
Description: Given the input and output file name, opens the unix input file
             and copies the content to the output file, converting the file to
             windows format whenever appropriate. If an output file of the name
             does not exist, one would be created.

     Inputs: finput  - c-string name of the input unix file.
             foutput - c-string name of the output windows file.

    Outputs: enum FILE_ERR - Error codes. feNONE means no error. feINPUT means
             cannot open input file. feOUTPUT means cannot open output file.
*******************************************************************************/
enum FILE_ERR unix2win(const char *finput, const char *foutput)
{
  /* Read in the input and output file. */
  FILE *input = fopen(finput, "rb");
  FILE *output = fopen(foutput, "rb+");
  
  /* Temporary variable to hold currently read char. */
  char temp;
  
  /* Error handling, cannot open files. */
  if(input == NULL)
  {
    /* Cannot open input file. */
    return feINPUT;
  }
  else if(output == NULL)
  {
    /* Cannot open output file.*/
    return feOUTPUT;
  }
  
  /* Set temp to current character. */
  while((temp = fgetc(input)))
  {
    /* End the loop if temp is EOF*/
    if(temp == EOF)
    {
      break;
    }
    /* This is a line feed in UNIX, proceed to convert to windows. */
    if(temp == LF)
    {
      /* Put in 0D 0A for UNIX. */
      fputc(0x0D, output);
      fputc(temp,output);
    }
    else /* We normally don't do anything special. */
    {
      /* Proceed as normal, put them in output file. */
      fputc(temp, output);
    }
  }
  
  /* All done, close files. */
  fclose(input);
  fclose(output);
  
  /* Return no error. */
  return feNONE;
}