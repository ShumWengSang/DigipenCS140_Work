/******************************************************************************
filename              encoder.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   19
due date              12/07/2018

Brief Description:
  Practice Assigment 19. Definition of encode and decode. Uses Run-length
  encoding to encode or decode a given file.
*******************************************************************************/
#include <stdio.h> /* fputc, fgetc, EOF, ungetc */
/*******************************************************************************
   Function: encode
 
Description: Given a pointer to an input file stream and a pointer to an output
             file stream, encodes the input file and puts the encoded content
             to output.

     Inputs: infile  - Pointer to a file stream, by stdio, that is the file to
                       be encoded.
             outfile - Pointer to a file stream, by stdio, that will hold the
                       encoded content.

    Outputs: None.
*******************************************************************************/
void encode(FILE *infile, FILE *outfile)
{
  int cur_char; /* Holds the current charaacter. */
  
  /* Loop through entire file, while getting the current character. */
  while((cur_char = fgetc(infile)) != EOF)
  {
    int next_char;           /* The next char in the stream.            */
    int i;                    /* Loop variable.                          */
    int curr_char_amount = 1; /* The consecutive amount of current char. */
    int curr_char_chunk = 0;  /* The number of 255 chunks.               */
    
    /* Check if next characters are the same, break when different. */
    while((next_char = fgetc(infile)) == cur_char)
    {
      /* Count how many of the same character there are. */
      curr_char_amount++;
    }
    /* We have read a character that isn't cur_char, put it back. */
    ungetc(next_char, infile);
    
    /* Cut down the number into 255 chunks */
    while(curr_char_amount > 255)
    {
      /* Cut down on chunks and record chunk amount. */
      curr_char_amount -= 255;
      curr_char_chunk++;
    }
    
    /* Do as many 255 chunks as necessary */
    for(i = 0; i < curr_char_chunk; i++)
    {
      /* Put in the chunk with the char */
      fputc(cur_char, outfile);
      fputc(255, outfile);
    }
    
    /* Now put the remainder chunk in as well. */
    fputc(cur_char, outfile);
    fputc(curr_char_amount, outfile);
  }
}

/*******************************************************************************
   Function: decode
 
Description: Given a pointer to an input file stream and a pointer to an output
             file stream, encodes the input file and puts the decode content
             to output.

     Inputs: infile  - Pointer to a file stream, by stdio, that is the file to
                       be decode.
             outfile - Pointer to a file stream, by stdio, that will hold the
                       decode content.

    Outputs: None.
*******************************************************************************/
void decode(FILE *infile, FILE *outfile)
{
  int curr_char; /* Hold the char from fgets */
  
  /* Read the entire file and get the current char. */
  while((curr_char = fgetc(infile)) != EOF)
  {
    int i; /* Loop variable */
    
    /* Read the next char to see how many times we have to repeat it. */
    int num_of_char = fgetc(infile);
    
    /* Put into outfile the char as many times as specified. */
    for(i = 0; i < num_of_char; i++)
    {
      /* Place into outstream. */
      fputc(curr_char, outfile);
    }
  }
}