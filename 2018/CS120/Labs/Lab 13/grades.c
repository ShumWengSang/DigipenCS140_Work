/******************************************************************************
filename      grades.c
author        Roland Shum
DP email      roland.shum@digipen.edu
course        CS120
section       A
Lab           13
due date      12/07/2018

Brief Description:
  Lab 13. Definition of parse_line and calculate_grade. Both functions together
  calculates a student's grade in any course.
******************************************************************************/
#include <stdio.h>  /* fopen, fgets, fclose   */
#include <stdlib.h> /* atoi                   */
#include <string.h> /* strstr, strchr, strcpy */

/* The weights define the percentages weightage of the rubrick. */
#define LAB_WEIGHT      .15
#define HOMEWORK_WEIGHT .20
#define MIDTERM_WEIGHT  .20
#define FINAL_WEIGHT    .45

/* Maximum amount of labs, and assignments. */
#define MAX_LABS        15
#define MAX_PHW         15

/* We expect each line to hold this amount of char including the 0 and '\n'. */
#define LINE_LENGTH     15

/* Simple way of keeping track of the scores. */
struct GRADE
{
  int score;
  int max;
};

/* 
 * Since all helper functions will need access to this data, I'm
 * going to make them available. You don't have to do it this way,
 * it's just a suggestion. If you'd rather pass all of the data
 * to all of the functions, you can. But, if you use these you
 * CANNOT remove the static keywords. If you don't use them, you
 * can just remove all of them from this file.
 */
static struct GRADE lab[MAX_LABS];    /* Handle up to MAX_LABS */
static struct GRADE homework[MAX_PHW]; /* Handle up to MAX_PHW  */
static struct GRADE midterm;
static struct GRADE final;

static int num_labs;
static int num_homeworks;

/*******************************************************************************
   Function: strcpynew
 
Description: Given a c-string source_start and source_end, copies all char 
             letters between and including source_start to the destination. No 
             checking will be done. Adds a null terminator at the end of ops.
             Source start and end must correspond to the same string. Very 
             unsafe function.

     Inputs: source_start - Pointer to a char array that describes where we 
                            start the copy process.
             source_end   - Pointer to a char array that describes where we end
                            the copy process.
             destination  - Pointer to an array that will be the destination
                            of the copied array. Size has to be bigger than 
                            source_start to source_end, or overflow will happen.

    Outputs: A char pointer to the destination array after ops is done.
*******************************************************************************/
char *strcpynew(const char *source_start, const char *source_end, 
                char * destination)
{
  int i; /* Loop variable. */
  
  /* Loop from start to end of source string. */
  for(i = 0; source_start + i != source_end; i++)
  {
    /* Copy over. */
    destination[i] = source_start[i];
  }
  /* Add a null terminator at the end of it. */
  destination[i] = 0;
  
  /* Return a pointer to the destination array. */
  return destination;
}

/*******************************************************************************
   Function: get_grade_average
 
Description: Given a pointer to an array of struct GRADE, and the count amount 
             of them, returns the average number of all the grades added.

     Inputs: grades - Pointer to the first element in an array of GRADE.
             count  - The amount of elements in the array.

    Outputs: The average amount of all the grades added together.
*******************************************************************************/
double get_grade_average(struct GRADE *grades, int count)
{
  int i;          /* Loop variable                 */
  int score = 0;  /* The total score               */
  int max = 0;    /* The total max score possible. */
  
  /* Loop through all elements in array. */
  for( i = 0; i < count; i++)
  {
    /* Add the score and max to the total score and max. */
    score += grades[i].score;
    max += grades[i].max;
  }
  /* Return the average amount. */
  return (double)score / max;
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
   Function: parse_line

Description: Given c-string line, parses the line into struct GRADE format and
             returns the struct GRADE.
             
     Inputs: line - c-string line of the read line in file. Newline is expected
                    to be removed.

    Outputs: The GRADE that the line represents.
*******************************************************************************/
struct GRADE parse_line(const char *line)
{
  struct GRADE grade;   /* A copy of the struct to return.                 */
  char *slash;          /* A pointer to the first slash that occurs.       */
  char *colon;          /* A pointer to the colon that appears.            */
  char buffer[4] = {0}; /* String to store 3 digits and a null terminator. */ 
   
  /* Get a pointer to the colon. */
  colon = strchr(line, ':');
  
  /* Move past the colon by 1 to start reading numbers. */
  colon++;
  
  /* Get a pointer to the slash seperating the two numbers. */
  slash = strchr(line, '/');
  
  /* We now have the start and end of the first number. Copy them to buffer. */
  strcpynew(colon, slash, buffer);
  
  /* Convert the char from buffer to an int and store in grade. */
  grade.score = atoi(buffer);
  
  /* Now we isolate the second number. First move to the start of it. */
  ++slash;
  
  /* Convert the number to an int and store in grade. */
  grade.max = atoi(slash);

  /* Done. Return grade here. */
  return grade;
}

/*******************************************************************************
   Function: my_parse_line
 
Description: Given a c-string that is within this program's line format, 
             identify which tag the line belongs to, and adds the GRADE found 
             to its tagged array accordingly. 

     Inputs: string - C-style string to cut the endline.

    Outputs: None.
*******************************************************************************/
static void my_parse_line(const char *string)
{
  /* Get the score and the max from the string. */
  struct GRADE grade = parse_line(string);
  
  /* Search for the substring accordingly. */
  if(strstr(string, "LAB") != NULL)
  {
    /* If this is a lab, place the grade inte the lab array. */
    lab[num_labs++] = grade;
  }
  else if(strstr(string, "PHW") != NULL)
  {
    /* If this is an assignment, place the grade into the assignment array. */
    homework[num_homeworks++] = grade;
  }
  else if(strstr(string, "MID") != NULL)
  {
    /* If this is a midterm, set the grade as the midterm grade. */
    midterm = grade;
  }
  else if(strstr(string, "FIN") != NULL)
  {
    /* If this is a final, set the grade as the final grade. */
    final = grade;
  }
}

/*******************************************************************************
   Function: calculate_grade

Description: Given a filename, read the file and calculates the grade. The file
             must be given in a certain format: 
             " LAB02:100/100
               LAB03:0/100
               LAB04:100/100
             "
             NAME : GRADE / MAX
             
     Inputs: filename - The name of the file to calculate its scores.

    Outputs: The percentage of the person whose grades have been passed in 
             through the file. Returns -1 if no file was found.
*******************************************************************************/
double calculate_grade(const char *filename)
{
  double total = 0.0;
  FILE *file = NULL;  /* Pointer to the file. */
  char buffer [LINE_LENGTH] = {0};
  
  /* Open file, if it returns a failure, */
  if((file = fopen(filename, "rt")) == NULL)
  {
    /* Print error and return. */
    printf("Error, %s file not found\n", filename);
    return -1;
  }
  
  /* Run until end of file is hit, while placing each line into buffer. */
  while(fgets(buffer, LINE_LENGTH, file) != NULL)
  {   
    /* Remove the endline in the string. */
    remove_endline(buffer);
    
    /* Parse the lines. */
    my_parse_line(buffer);
  }
  /* Get the score of all the labs and apply weightage. */
  total += get_grade_average(lab, num_labs) * LAB_WEIGHT;
  
  /* Get the score of all the homework and apply weightage.*/
  total += get_grade_average(homework, num_homeworks) * HOMEWORK_WEIGHT;
  
  /* Get the final and midterm and add their weightage too. */
  total += ((double)midterm.score / midterm.max) * MIDTERM_WEIGHT;
  total += ((double)final.score / final.max) * FINAL_WEIGHT;
  
  /* Close the file */
  fclose(file);

  /* Return the total, converted to percentage. */
  return total * 100;
}
