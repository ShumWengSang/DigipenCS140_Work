/******************************************************************************
filename      tablen.c
author        Roland Shum
DP email      roland.shum@digipen.edu
course        CS120
section       A
Lab           10
due date      11/14/2018

Brief Description:
  Lab 10. Definitions of tablen, count_tabs, and check_line_length.
******************************************************************************/
#include <string.h> /* strlen       */
#include <stdio.h>  /* fopen, fgets */

#define ASCII_TAB 9          /* ASCII representation of a horizontal tab. */
#define MAX_LINE_LENGTH 1000 /* Maximum buffer array size. */
/*******************************************************************************
   Function: count_tabs
 
Description: Given the file name, reads the files and determines if any lines 
             uses tabs, and how many are used. It would print the line out, and 
             also will print out a summary information containing how many tabs
             were used in total.

     Inputs: filename - c-string name of the file.

    Outputs: 0 for no file found. 1 for no errors.
*******************************************************************************/
int count_tabs(const char *filename)
{
  /* Buffer to store the information from file. */
  char buffer[MAX_LINE_LENGTH];
  
  int n_tabs = 0; /* A record of how many tabs found. */
  int n_line = 1; /* A record of current line number. */
  
  /* File stream declaration, and open the file in read mode. */
  FILE *the_file_stream = fopen(filename, "r");
  
    /* Check if nothing is read. */
  if(the_file_stream == NULL)
  {
    /* Get rid of the .txt at the end of the string. */
    
    
    /* Reading failed. Print out error. */
    printf("Can't open %s for read.\n", filename);
    
    /* Reading failed. Return error. */
    return 0;
  }
  
  /* Read till end of file, while putting current line in buffer. */
  while (fgets(buffer, MAX_LINE_LENGTH, the_file_stream))
  {
    int i;  /* loop variable. */
    
    /* Local tab number variable. */
    int tabs_in_line_found = 0;

    
    /* Analyse if the buffer contains any tabs. */
    for(i = 0; buffer[i] != 0; i++)
    {
      /* If we found a tab. */
      if(buffer[i] == ASCII_TAB)
      {
        /* Increment local tabs found. */
        tabs_in_line_found++; 
      }
    }
    /* If there are any tabs found in this line. */
    if(tabs_in_line_found != 0)
    {
      int str_length; /* Variable to hold string length. */
      
      /* Add the tabs number to the total found in file. */
      n_tabs += tabs_in_line_found;
      
      /* Find and override the last char in buffer, which should be '\n'. */
      str_length = strlen(buffer);
      
      /* Override the newline with 0, so that we can print it out. */
      buffer[str_length - 1] = 0;
      
      /* Print out the line and the */
      printf("#%3i: (tabs:%2i) |%s|\n", n_line, tabs_in_line_found, buffer);
    }
    
    /* Increment the line number. */
    n_line++;
  }
  
  /* Print summary information, if any tabs are found. */
  if(n_tabs > 0)
  {
    /* Print the amount of tabs found in the entire file. */
    printf("*****  TABS IN USE  *****: Number of tabs in the file is %i.\n",
           n_tabs);
  }
  
  /* Close file, end of operations. */
  fclose(the_file_stream);
  
  /* No errors, return 1.*/
  return 1;
}

/**************************************************************************
   Function: check_line_length
 
Description: Given the file name, reads the files and  determines if any lines 
             go beyond 80 characters. If it does, print the line out. Also will 
             print out a summary information.

     Inputs: filename - c-string name of the file.
                     
    Outputs: 0 for no file found. 1 for no errors.
**************************************************************************/
int check_line_length(const char *filename)
{
  /* Buffer to store the information from file. */
  char buffer[MAX_LINE_LENGTH];
  
  int n_line = 1;            /* Record of the current line number.       */
  int line_with_faults = 0;  /* Number of lines above 80.                */
  int max_num_of_chars = 0;  /* The number of chars in the entire file.  */
  int max_line_number;       /* The line number with the biggest chars.  */

  
  /* File stream declaration, and open the file in read mode. */
  FILE *the_file_stream = fopen(filename, "r");

  
  
  /* Check if nothing is read. */
  if(the_file_stream == NULL)
  {
    /* Reading failed. Print out error. */
    printf("Can't open %s for read.\n", filename);
    
    /* Reading failed. Return error. */
    return 0;
  }
  
  /* Read each line and put in buffer until EOF. */
  while(fgets(buffer, MAX_LINE_LENGTH, the_file_stream))
  {
    /* Check the string length. */
    int str_len = strlen(buffer);
    
    /* Check if string length - 1 (because of new line) is greater then 80. */
    if(--str_len > 80)
    {
      /* 
       * Replace last char of buffer, which is new line, 
       * with 0, for printing.
       */
      buffer[str_len] = 0;
      
      /* Line is above 80 counts. Print out the line. */
      printf("#%3i: (%3i) |%s|\n", n_line, str_len, buffer);
      
      line_with_faults++; /* Increment the number of lines with faults. */  
      
      /* If the current line has more char counts then the current max. */
      if(str_len > max_num_of_chars)
      {
        /* Record the line with the highest fault. */
        max_line_number = n_line;
        
        /* Set the record character count in the file. */
        max_num_of_chars = str_len;
      }
    }
    
    n_line++; /* Increment line number to keep track of current line. */
  }
  
    /* Print summary information, if any faults are found. */
  if(line_with_faults > 0)
  {
    /* Print the amount of lines with above 80 characters in file. */
    printf("***** LINE TOO LONG *****: %i lines longer than 80.",
           line_with_faults);
    printf(" Longest line is %i at %i chars.\n", max_line_number, 
           max_num_of_chars );
  }
  
  /* Close file, end of operations. */
  fclose(the_file_stream);
  
  /* No errors, return 0. */
  return 1;
}

/**************************************************************************
   Function: tablen
 
Description: Given a file name in c-string, opens the files and finds if
             there are any tabs in the file, and if any line exceeds 80 
             characters. If there are tabs or lines that exceeds 80 characters,
             it would print out the lines and how many violations of this two
             rules. If the file is not found, the function ends without doing
             anything.
             
     Inputs: filename - C-style string name of the file.

    Outputs: None.
**************************************************************************/
void tablen(const char *filename)
{
  /* Pass the file to count_tabs. If there are errors, return. */
  if(!count_tabs(filename))
  {
    return;
  }
  
  /* 
  * Pass the file to check_line_length. No errors assumed here as count_tabs
  * has run safely.
  */
  check_line_length(filename);
  
}
