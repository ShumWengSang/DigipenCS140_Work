/***************************************************************************
filename    scantext.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
Assignment  5
due date    11/13/18

Brief Description:
  Assignment 5. Definitions for count_tabs, substitute char, calculate lengths,
  count_words, and mystrlen. Functions scan and manupilate strings.
***************************************************************************/
#define ASCII_TAB     9  /* ASCII representative of tab.     */
#define ASCII_NEWLINE 10 /* ASCII representative of newline. */
#define ASCII_SPACE   32 /* ASCII representative of space.   */

/**************************************************************************
   Function: mystrlen
 
Description: Given a c-style string, return the 'length' of the string, AKA
             the amount of elements, including the null-terminator.

     Inputs: string - The c-style string which length will be measured.

    Outputs: The total amount elements in the given c-style string.
**************************************************************************/
static int mystrlen(const char *string)
{
  int length = 0;  /* The number of characters in the string */
  
    /* Count the characters (not including the NUL) */
  while (*string++)
    length++;

  return length;
}

/**************************************************************************
   Function: count_tabs
 
Description: Given a c-style string, counts the amount of tabs that happen
             within the string.

     Inputs: string - The c-style string which would be analyzed.

    Outputs: The total amount tabs found in the given c-style string.
**************************************************************************/
int count_tabs(const char *string)
{
  int i;            /* Loop variable.        */
  int tabs_num = 0; /* Amount of tabs found. */
  
  /* Loop through c-string until null terminator. */
  for(i = 0; string[i] != 0; i++)
  {
    /* Check if the current element is a tab. */
    if(string[i] == ASCII_TAB)
    {
      /* If it is a tab, increment tabs_num. */
      tabs_num++;
    }
  }
  /* Return the number of tabs found. */
  return tabs_num;
}

/**************************************************************************
   Function: substitute_char
 
Description: Given a string, substitute old_char with new_char. Returns
             the number of substitutions.

     Inputs: string   - The c-style string which would modified by the
                        substitution.
             old_char - The char to find and substitute. 
             new_char - The char to change the substituted old char to.

    Outputs: The total amount of chars substituted.
**************************************************************************/
int substitute_char(char *string, char old_char, char new_char)
{
  int i;              /* Loop variable.           */
  int sub_amount = 0; /* Amount of substitutions. */
  
  /* Loop through c-style array until null terminator. */
  for(i = 0; string[i] != 0; i++)
  {
    /* If current element is old_char. */
    if(string[i] == old_char)
    {
      /* We substitute it. */
      string[i] = new_char;
      
      /* Increment substitution amount. */
      sub_amount++;
    }
  }
  /* Return the amount of substitution. */
  return sub_amount;
}

/**************************************************************************
   Function: calculate_lengths
 
Description: Given a string and a tabsize, calculate the length of the string
             and the print length of the string. The print length is the number
             of characters that will be required to display the string after the
             tabs are expanded into tabsize spaces. 

     Inputs: string         - The c-style string which would be analysed.
             tabsize        - The amount of spaces tabs will be expended into.
             string_length  - Value to fill to when finding the length of the
                              string.
             display_length - Value to fill to. Describes the length required
                              to display.

    Outputs: No returns. Prints to console the length of the string. Fills
             string_length and display_length. See input.
**************************************************************************/
void calculate_lengths(const char *string, int tabsize, int *string_length,
                       int *display_length)
{
  /* Find the number of tabs in the string. */
  int num_tabs = count_tabs(string);
  
  /* Find length of string from mystrlen function. Fill up output. */
  *string_length = mystrlen(string);
  
  /* Formula : display_length = strlen + (tabsize * tabnum) - tabnum; */
  *display_length = (*string_length) + (num_tabs * tabsize) - num_tabs;
}

/**************************************************************************
   Function: count_words
 
Description: Given a string, count the number of words and return the count.
             Words in a string are delimited by whitespace characters which
             are any of the following: space, newline, tab

     Inputs: string - The string where the amount of words would be counted.

    Outputs: The number of words in the given string.
**************************************************************************/
int count_words(const char *string)
{
  int i;                     /* Loop variable.         */
  int words_num = 0;         /* Print length of string.*/
  
  /* 
   * The last char accessed, set to delimiter to 
   * handle cases where first word is a delimiter. 
   */
  int last_char = ASCII_TAB; 
  
  /* If the first element is not any of the delmiters, it is a word. */
  
  /* Loop through c-string until null terminator. */
  for(i = 0; string[i] != 0; i++)
  {
    /* If we find any delimiter, */
    if(string[i] == ASCII_TAB || string[i] == ASCII_SPACE ||
       string[i] == ASCII_NEWLINE)
    {
      /* Make sure the last char is not a delimiter. */
      if(last_char != ASCII_TAB && last_char != ASCII_SPACE &&
         last_char != ASCII_NEWLINE)
      {
          /* We found a word! Increment word. */
        words_num++;
      }
    }
    /* Prepare last_char for next iteration. */
    last_char = string[i];
  }
  /* 
   * We still need to account for the last word if the string 
   * does not end with a delimiter. Check if last char is a
   * delimiter. If it isn't, add a word count.
   */
   if(last_char != ASCII_TAB && last_char != ASCII_SPACE &&
      last_char != ASCII_NEWLINE)
   {
     /* Last one is a word too! */
     words_num++;
   }
   
  /* Return the amount of words found. */
  return words_num;
}