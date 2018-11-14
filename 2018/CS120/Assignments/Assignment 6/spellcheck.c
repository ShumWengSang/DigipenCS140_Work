/******************************************************************************
filename    spellcheck.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
Assignment  6
due date    11/29/2018

Brief Description:
  Assigment 6. Defines functions that create a rudimentary spell-checker. 
  Holds the definitions of mystrup, word_starting_with, word_length, info, and
  spell_check.
*******************************************************************************/
#include <string.h> /* strlen, strcmp, strcpy */
#include <stdio.h>  /* fgets, fclose, fopen, EOF */

/* FILE_OK, FILE_ERR_OPEN, WORD_OK, WORD_BAD, LONGEST_WORD */
#include "spellcheck.h"

#define TO_UPPERCASE 32
/*******************************************************************************
   Function: mytoupper
 
Description: Given a char, converts lowercase letter to uppercase if possible.
             Returns the char unchanged if its not a lowercase character.

     Inputs: string - C-style string to cut the endline. Will be modified.

    Outputs: A char pointer to the first character of the c-string passed in.
*******************************************************************************/
char mytoupper(char c)
{
  /* Check if the char is within a lowercase character. */
  if('a' <= c && c <= 'z')
  {
    /* Returns after converting to uppercase by minus 32 */
    return c - TO_UPPERCASE;
  }
  /* Else return the character unchanged. */
  return c;
}

/*******************************************************************************
   Function: remove_endline
 
Description: Given a c-string that ends with endline, removes that endline and 
             returns a pointer to the start of the string. If no endline is 
             found at the end of the string, nothing is done.

     Inputs: string - C-style string to cut the endline. Will be modified.

    Outputs: A char pointer to the first character of the c-string passed in.
*******************************************************************************/
char *remove_endline(char *string)
{
  int i; /* Loop variable. */
  
  /* Loop till end of string */
  for(i = 0; string[i] != 0; i++)
  {
    ;  /* Empty */
  }
  
  /* Is the element before the nul terminator an endline? */
  if(string[--i] == '\n')
  {
    /* Remove it and replace with 0. */
    string[i] = 0;
  }
  /* Return the start of the string. */
  return string;
}

/*******************************************************************************
   Function: mystrupr
 
Description: Given a string, convert all lowercase letters to uppercase.
             Returns a pointer to the first character of the string that was
             passed in.

     Inputs: string - C-style string to convert all lowercase letters to 
                      uppercase. Will be modified by function.

    Outputs: A char pointer to the first character of the c-string passed in.
*******************************************************************************/
char *mystrupr(char *string)
{
  int i; /* Loop variable. */
  
  /* Loop through to end of string. */
  for(i = 0; string[i] != 0; i++)
  {
    /* Converts each char with toupper(), it turns letter to if possible. */
    string[i] = mytoupper(string[i]);
  }
  /* Return the start of the string. */
  return string;
}

/*******************************************************************************
   Function: words_starting_with
 
Description: Given the filename of a dictionary, count the number of
             words that start with letter. If the file can't be opened,
             return FILE_ERR_OPEN, otherwise return the number of
             words that start with letter. 

     Inputs: dictionary - C-style string of the dictionary directory. Used to 
                          open the file.
             letter     - ASCII representation of the letter to find the amount
                          of words with.

    Outputs: Returns the number of words that start with letter. If the file 
             cannot be opened, returns FILE_ERR_OPEN.
*******************************************************************************/
int words_starting_with(const char *dictionary, char letter)
{
  char buffer[LONGEST_WORD] = {0}; /* Buffer to hold current line.            */
  FILE *dictionary_file = NULL;    /* File pointer to hold open filed.        */
  int words_count = 0;             /* Amount of words that start with letter. */
  
  /* bool to record if we read the letter before. */
  int b_in_letter_word = 0;        
  
  /* Open dictionary file. */
  dictionary_file = fopen(dictionary, "rt");
  
  /* Handle file open failure. */
  if(dictionary_file == NULL)
  {
    /* Return Error if dictionary did not open. */
    return FILE_ERR_OPEN;
  }
  
  /* Turns the letter to uppercase so we can compare correctly later. */
  letter = mytoupper(letter);
  
  /* Read each line until end of file, and place string in buffer. */
  while(fgets(buffer, LONGEST_WORD, dictionary_file) != NULL)
  {
    /* Convert the string to all uppercase. */
    mystrupr(buffer);
    
    /* Is the current first word our letter ? */
    if(buffer[0] == letter)
    { 
      /* If it is, add to the counting. */
      words_count++; 
      
      /* If have not read our letter before, */
      if(!b_in_letter_word)
      {
        /* We are counting letters with the word now! */
        b_in_letter_word = 1;        
      } 
    }
    /* If not, have we read words that start with that letter before? */
    else if(b_in_letter_word)
    {
      /* We have read it before, so lets end the loop. */
      break;
    }
  }
  /* Close dictionary file. */
  fclose(dictionary_file);
  
  /* Return the count. */
  return words_count;
}

/*******************************************************************************
   Function: word_lengths
 
Description: Given the filename of a dictionary, count the number of
             words that have length one to count and store them in the
             array lengths at the appropriate index. Ie word 'love' would
             be stored at lengths[4].

     Inputs: dictionary - C-style string of the dictionary directory. Used to 
                          open the file.
             lengths    - Array to be filled with the amount of words with the
                          count as the index. Ie 'hit' would be stored as 
                          lengths[3].
             count      - The maximum length of the words to count.

    Outputs: Returns FILE_OK on unsuccessful file open. Otherwise returns
             FILE_OK.
*******************************************************************************/
int word_lengths(const char *dictionary, int lengths[], int count)
{ 
  int i;                        /* Loop iterator.                 */ 
  FILE *dictionary_file = NULL; /* File stream to the dictionary. */
  
  /* Buffer to hold the dictionary word read in. */
  char buffer[LONGEST_WORD] = {0};

  
  /* Open dictionary file. */
  dictionary_file = fopen(dictionary, "rt");
  
  /* Handle file open failure. */
  if(dictionary_file == NULL)
  {
    /* Return Error if dictionary did not open. */
    return FILE_ERR_OPEN;
  }
  /* Run through lengths and set it to 0. Count + 1 is maximum length. */
  for(i = 0; i <= count; i++)
  {
    lengths[i] = 0;
  }
  
  /* Read each line until end of file, and place string in buffer. */
  while(fgets(buffer, LONGEST_WORD, dictionary_file) != NULL)
  {
    int line_length;  /* Length of the buffer. */
    
    /* Get rid of the newline in the buffer. */
    remove_endline(buffer);
    
    /* Get the length of the line. */
    line_length = strlen(buffer);
    
    /* If the length of the line is below or equal to count. */
    if(line_length <= count)
    {
      /* Add one to the appropriate index in length. */
      lengths[line_length]++;
    } 
  }
  /* Close dictionary file. */
  fclose(dictionary_file);
  
  /* Successful */
  return FILE_OK;
}

/*******************************************************************************
   Function: info
 
Description: Given the filename of a dictionary, return information in the 
             DICTIONARY_INFO struct. If the file can't be opened, return 
             FILE_ERR_OPEN, otherwise return FILE_OK.

     Inputs: dictionary - C-style string of the dictionary directory. Used to 
                          open the file.
             dinfo      - Struct to fill with information. The information
                          filled are: The length of the shortest word, the 
                          length of the longest word, and the number of words
                          in the dictionary.

    Outputs: Returns FILE_ERR_OPEN on unsuccessful file open. Otherwise returns
             FILE_OK.
*******************************************************************************/
int info(const char *dictionary, struct DICTIONARY_INFO *dinfo)
{
  FILE *dictionary_file = NULL;  /* File stream to the dictionary. */
  
  /* Buffer to hold the dictionary word read in. */
  char buffer[LONGEST_WORD] = {0}; 
  
  /* Open dictionary file. */
  dictionary_file = fopen(dictionary, "rt");
  
  /* Handle file open failure. */
  if(dictionary_file == NULL)
  {
    /* Return Error if dictionary did not open. */
    return FILE_ERR_OPEN;
  }
  
  /* Init the struct. Set the shortest and longest word for comparison. */
  dinfo->longest = 0;
  dinfo->shortest = LONGEST_WORD;
  dinfo->count = 0;
  
  /* Read each line until end of file, and place string in buffer. */
  while(fgets(buffer, LONGEST_WORD, dictionary_file) != NULL)
  {
    int line_length;  /* Length of the buffer. */
    
    /* Get rid of the newline in the buffer. */
    remove_endline(buffer);
    
    /* Get the length of the line. */
    line_length = strlen(buffer);
    
    /* If the string length is less then 0, we ignore it. */
    if(line_length == 0)
    {
      continue;
    }
    
    /* Is this shorter then the shortest word? */
    if(line_length < dinfo->shortest)
    {
      /* We have a new shortest word. */
      dinfo->shortest = line_length;
    }
    /* Else is this the longer than longest word? */
    else if(line_length > dinfo->longest)
    {
      /* We have a new longest word. */
      dinfo->longest = line_length;
    }
    /* Each line is a word, so increment count with each loop iteration. */
    dinfo->count++;
  }
  /* Close dictionary file. */
  fclose(dictionary_file);
    
  /* Successful */
  return FILE_OK;
}

/*******************************************************************************
   Function: spell_check
 
Description: Given the filename of a dictionary and a word, lookup the word in 
             the dictionary. If the word was found, return WORD_OK. If the word
             was not found, return WORD_BAD. If the dictionary file can't be 
             opened, return FILE_ERR_OPEN.

     Inputs: dictionary - C-style string of the dictionary directory. Used to 
                          open the file.
             dinfo      - Struct to fill with information. The information
                          filled are: The length of the shortest word, the 
                          length of the longest word, and the number of words
                          in the dictionary.

    Outputs: Returns WORD_OK if word was found in dictionary. If not found, 
             returns WORD_BAD. If the dictionary file could not be opened,
             returns FILE_ERR_OPEN.
*******************************************************************************/
int spell_check(const char *dictionary, const char *word)
{
  FILE *dictionary_file = NULL;     /* File stream to the dictionary. */
  
  /* Buffer to hold the dictionary lines read in. */
  char buffer[LONGEST_WORD] = {0}; 
  
  /* Buffer to hold an all uppercase of 'word' */
  char m_word[LONGEST_WORD] = {0}; 
  
  /* Open dictionary file. */
  dictionary_file = fopen(dictionary, "rt");
  
  /* Handle file open failure. */
  if(dictionary_file == NULL)
  {
    /* Return Error if dictionary did not open. */
    return FILE_ERR_OPEN;
  }
  /* Copies word to our own word buffer so we can modify it. */
  strcpy(m_word, word);
  /* Conver the given word to uppercase so we can compare properly. */
  mystrupr(m_word);
  
  /* Read each line until end of file, and place string in buffer. */
  while(fgets(buffer, LONGEST_WORD, dictionary_file) != NULL)
  {  
    /* Get rid of the newline in the buffer. */
    remove_endline(buffer);
    
    /* Convert the line to uppercase for effective comparison. */
    mystrupr(buffer);
    
    /*strcmp returns 0 if both c-strings are the same. */
    if(!strcmp(buffer, m_word))
    {
      /* This is a valid word. No need to search anymore. Close and return. */
      fclose(dictionary_file);
      return WORD_OK;
    }
  }
  /* Close dictionary file. */
  fclose(dictionary_file);
    
  /* Word not found. Return WORD_BAD. */
  return WORD_BAD;
}
