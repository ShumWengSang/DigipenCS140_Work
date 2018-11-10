/******************************************************************************
filename              inttostr.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   16
due date              12/07/2018

Brief Description:
  Practice Assignment 16. Definition of inttostr, where we convert an int
  to a string.
******************************************************************************/
#include <string.h> /* strlen  */

/* max size of array. 10 ints, one sign, and one null terminator */
#define MAX_SIZE 12 
/**************************************************************************
   Function: copy
 
Description: Helper function that copies the c-string target to destination.
             Appends a null terminator at the end of operation.

     Inputs: target      - c-string that is the target to copy.
             destination - c-string destination array to copy to. No gurantees
                           about size is made.

    Outputs: None.
**************************************************************************/
void copy(const char *target, char *destination)
{
  int i;                     /* Loop variable.               */
  int destination_index = 0; /* Index of destination string. */
  
  /* Loop until target is over. */
  for(i = 0; target[i] != 0; i++)
  {
    destination[destination_index++] = target[i];
  }
  /* Add a final 0 at the end. */
  destination[destination_index] = 0;
}

/**************************************************************************
   Function: reverse
 
Description: Helper function that reverses the letters of an array around.

     Inputs: start  - The head of the char array to reverse.
             end    - The end of the char array to reverse.

    Outputs: None.
**************************************************************************/
void reverse(char *start, char *end)
{
  /* If the pointers move past each other, end operation. */
  while (start < end)
  {
      char temp; /* Temporary holder of the current char. */
      
      /* Set the temp to hold the start value. */
      temp = *start;
      
      /* Swap the values of the head and end.*/
      *start = *end;
      *end = temp;
      
      /* Move the pointers to the next letters to reverse. */
      start++;
      end--;
  }
}

/*******************************************************************************
   Function: inttostr
 
Description: Given a number and a char array, converts the number to string.
             Ie. int 5 will give '5'.

     Inputs: number - Number to convert to string.
             string - c-style string to be modifed with the string version of
                      the given number.

    Outputs: None
*******************************************************************************/
void inttostr(int number, char string[])
{
  int i; /* Loop variable. */
  
  /* Current Index of string. Make space for null terminator.*/
  int buffer_index = MAX_SIZE - 2; 
  int is_neg = 0;
  
  /* Sets the string array to 0. */
  for(i = 0; i < MAX_SIZE; i++)
  {
    /* Set each element to 0. */
    string[i] = 0;
  }

  /* If number is 0 */
  if(number == 0)
  {
    /* set string to 0 and return. */
    string[0] = '0';
    return;
  }
  
  /* Is the number negative? */
  if(number < 0)
  {
      /* Set the sign, and turn it positive for the algo to work. */
      number *= -1;
      is_neg = 1;
  }
  
  /* We continue until the number is less then 0. */
  while(number > 0)
  {
    /* Get the last digit. */
    int digit = number % 10;
    
    /* Convert to ASCII */
    digit += '0';
    
    /* Place digit at end of string. */
    string[buffer_index--] = digit;
    
    /* Move to the next digit. */
    number /= 10;
  }
  /* Was the number when it came in negative? */
  if(is_neg)
  {
    /* Add the negative sign. */
    string[buffer_index--] = '-';
  }
  /* Shift the string down to the first address */
  copy(&string[buffer_index + 1], &string[0]);  
}