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

/**************************************************************************
   Function: GetCounts
 
Description: Given a c-string array, this function fills the letters array
             with the amount of times a letter was used. This function will
             also count the amount of spaces and other characters used.

     Inputs: sentence - The c-style string to find the amount of counts for.
             letters  - An array that would be modified to give the amount
                        of times a certain letter is called. Ie letters[0] = 1
                        means the letter A is detected 1 time, letters[1] is B
                        etc.
             spaces   - Int to be filled by the amount of spaces in the
                        sentance.
             other    - Int to be filled by the amount of things other then
                        an alphabet or a space.

    Outputs: No returns. Modifies spaces, others, and letters. Read input.
**************************************************************************/
int GetCounts(const char *sentence, int letters[], int *spaces, int *other)
{
  /* Loop through the string. */
  
  /* Modifiy toupper. */
  
  /* If character is unchanged, checl if it is in range. */
  
  /* If it is in range, it is a letter. */
  /* Minues 65 from the ascii value to shift it so it matches with letters. */
  
  
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
}

/**************************************************************************
   Function: GetStatistics
 
Description: Given an array that contains the amount of letters for each 
             letter in the English alphabet, finds the average number of the
             English alphabet called. Also identifies the maximum amount of
             times a character is found, and what character it is.

     Inputs: letters    - Char array of 26, each element index representing the
                          alphabet, and each element value representing the
                          number of times. Ie. letters[0] = 10 means the letter
                          A is found 10 times, letters[1] = 4 means the letter 
                          B is found 4 times.
             average    - The variable to be filled with the added numbers of 
                          all the alphabets, divided by 26.
             max_letter - Var to be filled with the letter with the highest 
                          number.
             max_count  - Var to be filled with the highest number.

    Outputs: No returns. Average, max_letter, and max_count will be filled.
             See Inputs.
**************************************************************************/
void GetStatistics(const int letters[], double *average, char *max_letter, 
                   int *max_count)
{
}

