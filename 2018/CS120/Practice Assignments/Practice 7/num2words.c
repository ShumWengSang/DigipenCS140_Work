/******************************************************************************
filename              num2words.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   7
due date              12/07/2018
Brief Description:
  Practice Assignment 7. Definition for number_to_words function. This function
  takes in a two digit number and changes it into its word form.
  
******************************************************************************/
#include <stdio.h> /* printf */

#define MAXCHARS 50 /* The maximum amount of char in the array. */
#define TRUE 1      /* TRUE is 1.                               */
#define FALSE 0     /* FALSE is 0.                              */
/*****************************************************************************
   Function: c_strcpr
 
Description: Takes in two c-string arrays and checks if each element are
             the same. Does size checking as well.

     Inputs: first_array  - Char array of first string to compare.
             second_array - Char array of second strong to compare.

    Outputs: Returns whether the two string's elements are equal.
             1 (TRUE) for true, 0 (FALSE) for false
******************************************************************************/
int c_strcpr(const char first_array[], const char second_array[])
{
  int i = 0, j = 0; /* Loop variable. */
  
  /* Get the size of the first array, store in i. */
  while(first_array[i] != '\0')
    i++;
  
  /* Get the size of the second array, store in j. */
  while(second_array[j] != '\0')
    j++;
  
  /* We compare size. If size is not the same, return false. */
  if(i != j)
  {
    return FALSE;
  }
  
  /* Loop backwords through the first c-string. */
  while(first_array[i] != '\0')
  {
    /* If the elements are not the same. */
    if(first_array[i] != second_array[i])
    {
      /* Not equal. Return false. */
      return FALSE;
    }
    /* Move to next letter, backwords */
    i--;
  }
  /* All elements are the same. Return true. */
  return TRUE;
  
}

/*****************************************************************************
   Function: custom_strcnt
 
Description: Takes two different c-style strings and concactenate them
             together in the destination array. Note: the dest array must
             be initialized and be greater size of both first_word and
             second_word. Only for C-style strings! No safety is performed 
             by this function!

     Inputs: first_word  - Char array of first word to add.
             second_word - Char array of second word to add.
             dest        - Char array that contains the two words together.

    Outputs: None. Dest will be modified to be both words concateted.
******************************************************************************/
void custom_strcnt(const char first_word[],
                   const char second_word[],
                   char dest[]
                  )
{
  int i, j ;  /* Loop variables. */
  
  /* 
   * We make use of the fact that c-style strings end with '\n'. 
   * Loop through the first word.
   */  
  for(i = 0 ; first_word[i] != '\0'; i++)
  {
    /* Copy over to dest array. */
    dest[i] = first_word[i];
  }
  
  /* If second array is empty, we return. */
  if(c_strcpr(second_word, ""))
  {
    return;
  }
  
  /* We need to add a desh between the two words. */
  dest[i] = '-';
  /* Move to next letter. */
  i++;
  
  /* Same thing here, except with second word.*/
  for(j = 0; second_word[j] != '\0'; j++)
  {
    /* Copy over to dest array. */
    dest[i + j] = second_word[j];
  }
}

/*****************************************************************************
   Function: number_to_words
 
Description: Takes a two-digit number and prints out its respective
             English word.

     Inputs: number - The number to parse.

    Outputs: None
******************************************************************************/
void number_to_words(int number)
{
  char * result; /* This pointer will hold our result. */
  
  /* This will hold our concactenate result . */
  char concactenate_result [MAXCHARS] = {0};
   
  /* The strings for the all places from 1 to 19. */
  char  * const ones[20] = { "", "one", "two", "three", "four", "five",
                             "six", "seven", "eight", "nine", "ten",
                             "eleven", "twelve", "thirteen", "fourteen",
                             "fifteen", "sixteen", "seventeen", "eighteen",
                             "nineteen"
                           };
                             
  /* The strings for the tenths place.*/
  char * const tens[10] = { "", "", "twenty", "thirty", "forty", "fifty",
                            "sixty", "seventy", "eighty", "ninety"
                          };
  
  /* If number is less then nineteen, handle it with just ones array. */
  if(number < 20)
  {
    result = ones[number];
  }
  else
  {
    int digit[2]; /* This will hold our digits. */
    
    /* Get the ones digit. */
    digit[0] = number % 10;
    /* Get the tens digit. */
    digit[1] = (number / 10) % 10;
    /* Find the right string word for it and add them together in result. */
    custom_strcnt(tens[digit[1]], ones[digit[0]], concactenate_result);
    /* Point result to the concactenate_result. */
    result = concactenate_result;
  }
  /* Prints, using the pointer with the assumption it is pointing correctly. */
  printf("%s\n", result);
  
}