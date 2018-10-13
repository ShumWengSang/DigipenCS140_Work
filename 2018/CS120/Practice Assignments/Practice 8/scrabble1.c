/******************************************************************************
filename    scrabble1.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
week        8
due date    12/07/2018

Brief Description:
  Practice Assigment 8. A program that prompts the user for an English word, 
  and then prints out the value of the word based on the game of Scrabble.
  
******************************************************************************/
#include <stdio.h> /* printf  */
#include <ctype.h> /* toupper */
/**************************************************************************
   Function: main
 
Description: Prompts the user for an English word, 
             and then prints out the value of the word based 
             on the game of Scrabble.

     Inputs: void

    Outputs: Exit status of program (always 0).
**************************************************************************/
int main(void)
{
  int sum = 0; /* The total value of the word */
  int letter;  /* Each character in the word  */

    /* Prompt the user for a word */
  printf("Enter a word: ");

    /* Read the first character */
  letter = getchar();

    /* While it's not the newline (end of the word) */
  while (letter != '\n')
  {
    /* Set the letter to its uppercase form. */
    letter = toupper(letter);
    
    /* Add the value of the letter to sum. */
    switch(letter)
    {
      /* A E I L N O R S T U is 1 point. */
      case 'A': /* FALLTHROUGH */
      case 'E': /* FALLTHROUGH */
      case 'I': /* FALLTHROUGH */
      case 'L': /* FALLTHROUGH */
      case 'N': /* FALLTHROUGH */
      case 'O': /* FALLTHROUGH */
      case 'R': /* FALLTHROUGH */
      case 'S': /* FALLTHROUGH */
      case 'T': /* FALLTHROUGH */
      case 'U':
        sum += 1;
        break;
      
      /* D G is 2 points. */
      case 'D': /* FALLTHROUGH */
      case 'G':
        sum+= 2;
        break;
      
      /* B C M P is worth 3 points. */
      case 'B': /* FALLTHROUGH */
      case 'C': /* FALLTHROUGH */
      case 'M': /* FALLTHROUGH */
      case 'P':
        sum += 3;
        break;
        
      /* F H V W Y is worth 4 points. */
      case 'F': /* FALLTHROUGH */
      case 'H': /* FALLTHROUGH */
      case 'V': /* FALLTHROUGH */
      case 'W': /* FALLTHROUGH */
      case 'Y':
        sum += 4;
        break;
       
      /* K is worth 5 points. */
      case 'K':
        sum += 5;
        break;
        
      /* J K is worth 8 points. */
      case 'J': /* FALLTHROUGH */
      case 'X':
        sum += 8;
        break;
        
      /* Q Z is worth 10 points. */
      case 'Q': /* FALLTHROUGH */
      case 'Z':
        sum+= 10;
        break;
      
      /* Unexpected cases go here. */
      default:
        break;
    }
     /* Read next character in the word */
    letter = getchar();
  }

  /* Print the sum of the scrabble. */
  printf("Scrabble value is : %i\n", sum);

  return 0;
}
