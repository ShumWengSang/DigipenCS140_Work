/***************************************************************************
filename    histogram.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
Lab         9
due date    11/07/18

Brief Description:
  Definitions for GetCount, PrintHistogram, and GetStatistics. GetCount gets
  the amount of letters, spaces, and others in a sentance. PrintHistogram
  prints a histogram of the times the words in the English alphabet was used.
  GetStatistics gives the average value of the word used, and the maximum
  times the maximum letter was used.
***************************************************************************/
#include <stdio.h>     /* printf      */
#include <ctype.h>     /* toupper     */
#include <string.h>    /* strlen      */
#include "histogram.h" /* lab defines */

#define ASCII_SPACE 32 /* Ascii value of the space character. */

/**************************************************************************
   Function: GetCounts
 
Description: Given a c-string array, this function fills the letters array
             with the amount of times a letter was used. This function will
             also count the amount of spaces and other characters used. Also
             returns the total amount of chars in the string.

     Inputs: sentence - The c-style string to find the amount of counts for.
             letters  - An array that would be modified to give the amount
                        of times a certain letter is called. Ie letters[0] = 1
                        means the letter A is detected 1 time, letters[1] is B
                        etc.
             spaces   - Int to be filled by the amount of spaces in the
                        sentance.
             other    - Int to be filled by the amount of things other then
                        an alphabet or a space.

    Outputs: The total amount of letters in the char.
**************************************************************************/
int GetCounts(const char *sentence, int letters[], int *spaces, int *other)
{
  int i;                 /* Loop varaible.                          */
  int letter_amount = 0; /* Hold the amount of letters in sentence. */
  
  *spaces = 0; /* Set to 0 just in case. */
  *other = 0;  /* Set to 0 just in case. */
  
  /* Loop through letters and set to 0 just in case. */
  for(i = 0; i < NUM_LETTERS; i++)
  {
    letters[i] = 0;
  }
  
  /* Loop through the string until null terminator. */
  for(i = 0; sentence[i] != 0; i++)
  {
    int current_char; /* Temp variable to hold ascii of current char. */
    
    /* Modifiy toupper. */
    current_char = toupper(sentence[i]);
    
    /* Unchanged means either it is an Uppercase already, or something else. */
    if(current_char == sentence[i])
    {
      /* Check if it is an Uppercase. 'A' starts at 65.
       * There are 26 alphabets in the English language.
       */
      if('A' <= current_char  && current_char <= 'Z')
      {           
        /* Shift number by 65 to match it with letters array. */
        current_char -= 'A';
        
        /* Add into the value of the letter/index. */
        letters[current_char]++;
        
        /* Increment the letters found. */
        letter_amount++;
      }
      else /* Else if not in range */
      {
        /* Check if it is a space. */
        if(current_char == ASCII_SPACE)
        {
          /* Increment spaces */
          (*spaces)++;
        }
        else /* Not a space or an upper character. Something else.*/
        {
          /* Increment other. */
          (*other)++;
        }
      }
    }
    else  /* current_char has been changed. It is now an uppercase char. */
    {
      /* Shift number by 65 to match it with letters array. */
      current_char -= 'A';
      
      /* Add into the value of the letter/index. */
      letters[current_char]++;
      
      /* Increment the letters found. */
      letter_amount++;
    }
  }
  /* i - 1 holds the string length, aka the amount of chars. */
  return letter_amount;
}

/**************************************************************************
   Function: PrintHistogram
 
Description: Given an array that contains the amount of letters for each 
             letter in the English alphabet, print a histogram containing
             with the array data to the console.

     Inputs: letters - Char array of 26, each element index representing the
                       alphabet, and each element value representing the
                       number of times. Ie. letters[0] = 10 means the letter
                       A is found 10 times, letters[1] = 4 means the letter 
                       B is found 4 times.

    Outputs: None.
**************************************************************************/
void PrintHistogram(const int letters[])
{
  int i, j; /* Loop Variable. */
  
  /* Loop through all elements of english alphabet, so 26. */
  for(i = 0; i < NUM_LETTERS; i++)
  {
    /* Print the histogram letter. */
    printf("%c:", i + 'A');
    
    /* Loop through the value of the letter[i]. */
    for(j = 0; j < letters[i]; j++)
    {
      /* And print a '*' to represent the value. */
      printf("*");
    }
    /* And end it with a new line. */
    printf("\n");
  }
}

/**************************************************************************
   Function: GetStatistics
 
Description: Given an array that contains the amount of letters for each 
             letter in the English alphabet, finds the average number of the
             English alphabet called. So if the letter B has 4, and letter C
             has a 3 it will take 2 * 4 + 3 * 3 and divide it by the number of
             alphabets (26), and that is the average. Also identifies the 
             maximum amount of times a character is found, and what character
             it is.

     Inputs: letters    - Char array of 26, each element index representing the
                          alphabet, and each element value representing the
                          number of times. Ie. letters[0] = 10 means the letter
                          A is found 10 times, letters[1] = 4 means the letter 
                          B is found 4 times.
             average    - The variable to be filled with the added numbers of 
                          all the alphabets, divided by 26. The "average" of 
                          the letters 
             max_letter - Var to be filled with the letter with the highest 
                          count in the letters array. AKA the letter that 
                          appeared the most in the string.
             max_count  - Var to be filled with the highest number count of
                          all the letters in the array. AKA the count of 
                          max_letter.

    Outputs: No returns. Average, max_letter, and max_count will be filled.
             See Inputs.
**************************************************************************/
void GetStatistics(const int letters[], double *average, char *max_letter, 
                   int *max_count)
{
  int i;               /* Loop variable.          */
  int letters_sum = 0; /* Sum of all the letters. */
  
  /* the value of the letter that appeared the most in the string. */
  int max_char_index = 0;    
  
  /* Loop until end of c-string. */
  for(i = 0; i < NUM_LETTERS; i++)
  {
    /* Add into letters_sum to find the average later. */
    letters_sum += (i + 1) * letters[i];
    
    /* Determine if this is the largest value in element across the array. */
    if(letters[max_char_index] < letters[i])
    {
      /* max_char is smaller, so lets make this max_char_index. */
      max_char_index = i;
    }
  }
  /* We now divde the letters_sum by 26 to get the "average". */
  *average = (double)letters_sum / NUM_LETTERS;
  
  /* Recrod the highest amount of time a letter has appeared in max_count. */
  *max_count = letters[max_char_index];
  
  /* And get that ASCII of that char by offsetting by 'A' (65). */
  *max_letter = (char)(max_char_index + 'A');
}

