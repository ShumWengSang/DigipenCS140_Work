/******************************************************************************
filename      dumpit.c
author        Roland Shum
DP email      roland.shum@digipen.edu
course        CS120
section       A
Lab           12
due date      12/02/2018

Brief Description:
  Lab 12. Definition of format and dump. Together, both functions recreate the
  dumpit program. The dumpit program translates a file into hex formate and 
  prints it out in a formatted manner.
******************************************************************************/
#include <stdio.h>  /* printf, fopen, fclose, fread, sprintf */
#include <string.h> /* strcat */

/* Longest formatted line is 75 characters */
#define MAXLEN 75

/* The min range of printable number */
#define MIN_PRINT_ASCII 31  

/* The max range of printable number */
#define MAX_PRINT_ASCII 127

/* Example: (This example has Unix end-of-line character: 0x0A)
 *
 *  If inbuf contains the first 16 characters from the poem.txt file and outbuf
 *  is an empty array large enough to hold the formatted string, this is how 
 *  you would call the format function:
 *   
 *     format(inbuf, outbuf, 16, 0);
 *  
 *  and this is what outbuf would contain when it returned:
 *  
 * 000000 52 6F 73 65 73 20 61 72  65 20 72 65 64 2E 0A 56   Roses are red..V
 *
 *
 *  The second 16 bytes would be formatted like this:
 *
 *     format(inbuf, outbuf, 16, 16);
 *
 *  and outbuf would look like this:
 *
 * 000010 69 6F 6C 65 74 73 20 61  72 65 20 62 6C 75 65 2E   iolets are blue.
 *
 */
 
/*******************************************************************************
   Function: format

Description: Given an array of characters, format the characters as a line of
             hexadecimal numbers, including file offset and ASCII letters. Only
             the printable ASCII characters are displayed. Non-printable 
             characters are displayed as a period. The file offset is shown
             as a hexadecimal number.

     Inputs:  inbuf - The array of characters to format.
             outbuf - The formatted array, including offset and ASCII letters. 
              count - The number of characters in the input array.
             offset - The value of the 6-digit offset.

    Outputs: None. However, the outbuf parameter has been modified for the
             client.
*******************************************************************************/
void format(const char* inbuf, char *outbuf, int count, int offset)
{
  int i;  /* loop variable */

  /* Line number. e.g. 000010 */
  sprintf(outbuf, "%06X ", offset);

  /* e.g. 52 6F 73 65 73 20 61 72  65 20 72 65 64 2E 0A 56 */
  for (i = 0; i < count; i++)
  { 
    char buffer [MAXLEN] = {0};
    /* Format each byte as a hex number, use AND to get last two digits. */
    sprintf(buffer, "%02X ", inbuf[i] & 0xff);
    
    /* Add the hex number to the end of buffer using strcat        */  
    strcat(outbuf, buffer);

    /* Don't forget the extra space between the 8th and 9th number */  
    if(i == 7)
    {
      strcat(outbuf, " ");
    }
  }
  
  /* If we never printed the extra space between 8 and 9, */
  if(i < 8)
  {
    /* print it.*/
    strcat(outbuf," ");
  }

  /* If you didn't get 16 characters, you have to add extra spaces */  
  for(i = count; i < 16; i++)
  {
    strcat(outbuf, "   ");
  }
  
  /* Add another space to seperate the ASCII and the Hex. */
  strcat(outbuf, "  ");
  
  /* Using another loop, append the ASCII representation of the characters */  
  for( i = 0 ; i < count; i++)
  {
    char buffer[2] = {0};  /* Buffer string, used to hold char to output.*/
    
    /* If the character is within the printable character ranges. */
    if( MIN_PRINT_ASCII < inbuf[i] && inbuf[i] < MAX_PRINT_ASCII)
    {
      /* We will print it accordingly. */
      buffer[0] = inbuf[i];
    }
    else
    {
      /* Else we put a '.' to it. */
      buffer[0] = '.';
    }
    
    /* Connect buffer at the end of outbuf */
    strcat(outbuf, buffer);
  }
}

/*******************************************************************************
   Function: dump

Description: Given a filename, read in the bytes and print their hexadecimal
             values to the screen. If the character is printable, print the
             character as well.
             
     Inputs: filename - The name of the file to dump in hex.

    Outputs: None
*******************************************************************************/
void dump(const char *filename)
{
  /* Variable declarations */
  FILE *file = NULL;           /* Pointer to file. */
  char buffer [MAXLEN] = {0};  /* Arr to hold the file input. */
  int size_result;             /* Int to determine size of bytes read. */
  int offset = 0;              /* */

  /* Open the file for read/binary, "rb"  (Text mode will not work) */
  file = fopen(filename, "rb");
  
  /* If the file couldn't be opened, print error message and return */
  if(file == NULL)
  {
    printf("Can't open %s for binary read.\n", filename);
    return;
  }

  /* Print the filename to the screen followed by a colon */
  printf("\n%s:\n",filename);
  
  /* Print the first header line (offsets in hexadecimal) */
  printf("       00 01 02 03 04 05 06 07  08 09 0A 0B 0C 0D 0E 0F\n");
  
  /* Print the second header line (dashes)                */
  printf("-----------------------------------------------------------------");
  printf("---------\n");

  /* 
   * For all bytes in the file, read 16 at a time and place into buffer.
   * End when we cannot take 16 at a time.
   */
  while ((size_result = fread(buffer, sizeof(char), 16, file)) == 16)
  {
    char out_buffer [MAXLEN] = {0};  /* Buffer to hold output from format. */
    
    /* Format bytes using the format function above */
    format(buffer, out_buffer, 16, offset);
    
    /* Print formatted string using printf or puts  */
    printf("%s\n", out_buffer);
    
    /* Add the amount of bytes we have been through. */
    offset += 16;
  }
  
  /* Find out how many leftovers if any. */
  size_result /= sizeof(char);
  
  /* If there were any leftovers, */
  if(size_result != 0)
  {
    char out_buffer [MAXLEN] = {0}; /* Buffer to hold output from format. */
       
    /* Format bytes using the format function above */
    format(buffer, out_buffer, size_result, offset);
    
    /* Print formatted string using printf or puts  */
    printf("%s\n", out_buffer);
  }
  
  /* Close the file */
  fclose(file);
}
