/***************************************************************************
filename    jumble.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
Assignment  4
due date    11/01/2018

Brief Description:
  Assigment 4. Definition of Jumble. Jumble is used to encrypt/decode the
  c-style string passed in. Mystrlen gives the string length.
***************************************************************************/
#include "jumble.h" /* CODE_METHOD, mystrlen, jumble */

/**************************************************************************
   Function: mystrlen
 
Description: Returns the length of the C-string.

     Inputs: string - C-style string that wants its length checked.

    Outputs: The length of the given c-style string.
**************************************************************************/
int mystrlen(const unsigned char *string)
{
  int len = 0;  /* Output variable, string length. */

  while (*string++) /* Run until string points to a null terminated value. */
    len++; /* Increment for every loop. */
  return len; /* Returns result. */
}

/**************************************************************************
   Function: jumble
 
Description: Modifies the given array to an encrypted form, based on the 
             password and how many passes done. This method can be used
             to encode or decode an encrypted c-style string.

     Inputs: string      - C-style string that contains the phrase that needs
                           to be encoded. Will be modified by function.
             password    - C-style string key to change the phrase by. 
                           Providing the same key used for encrytion will give 
                           the original phrase.
             CODE_METHOD - Choose to ENCODE or DECODE the given string.
             passes      - The number of times to run the encryption by. 
                           Running the same number of passes used for encoding 
                           is required for decoding.
    Outputs: None
**************************************************************************/
void jumble(unsigned char *string, const unsigned char *password, 
            enum CODE_METHOD method, int passes)
 {
   int i, k;             /* Loop variable.                                   */
   int code_method_sign; /* Determines whether we decode or encode.          */
   int strlength;        /* Varaible to hold the length of the given string. */
   
   /* If we are encoding. */
   if(method == ENCODE)
   {
     /* We want it to add. So set to positive. */
     code_method_sign = 1;
   }
   else /* Else */
   {
     /* We want to decode. So substract. So set to negative. */
     code_method_sign = -1;
   }
   
   /* Find the length of the given string. Use for looping later. */
   strlength = mystrlen(string);
   
   /* We want to run as many passes there are. */
   for(i = 0; i < passes; i++)
   {
     int key_index = 0;    /* Current index of the key. */
     int passlength;       /* The length of the password. */
     
     /* Get the length of password, so later can set to 0 when maxed. */
     passlength = mystrlen(password);
     
     /* Loop through each element in the string. */
     for(k = 0; k < strlength; k++)
     {
       /* 
        * We add or subtract depending on whether we are encoding or decoding.
        * FinalChar = string_element_ascii_num + (sign * key)
        */
        string[k] = string[k] + password[key_index] * code_method_sign;
        
        /* We move the index of the password. */
        key_index++;
        /* And route it back to 0 when it maxes. */
        key_index %= passlength;
     }
   }
 }