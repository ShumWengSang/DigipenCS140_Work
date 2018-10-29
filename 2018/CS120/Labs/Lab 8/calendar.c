/***************************************************************************
filename    calender.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
Lab         8
due date    10/31/2018

Brief Description:
  Definitions for Calander functions, is_leapyear, day_of_the_week, and
  print_calander.
***************************************************************************/
#include <stdio.h>  /* printf */

#define TRUE  1
#define FALSE 0
/**************************************************************************
   Function: is_leapyear
 
Description: Determines if the given year is a leap year.

     Inputs: year - The year to check if it is a leap year.

    Outputs: 1 (TRUE) for yes, 0 (FALSE) for no.
**************************************************************************/
int is_leapyear(int year)
{
  /* If the year is exactly divisible by 400. */
  if(year % 400 == 0)
  {
    return TRUE;
  }
  /* If the year is exactly divisble by 100 but not 400. */
  else if(year % 100 == 0)
  {
    return FALSE;
  }
  /* If the year is exactly divisble by 4, but not 100 or 400. */
  else if(year % 4 == 0)
  {
    return TRUE;
  }
  
  /* Anything else is not a leap year. */
  return FALSE;
}

/**************************************************************************
   Function: day_of_the_week
 
Description: Given a date (day, month, year, in that order), determine which 
             day of the week the date falls on. The function returns 1 for 
             Sunday, 2 for Monday, 3 for Tuesday, etc. Only works for years
             from 1700 onwords.

     Inputs: day   - The date to determine which day of the week it is. Not
                     Monday, Tuesday, but the literal date.
             month - The month, 1 for Jan, 1 for Feb ... 12 for December.
             year  - The year to determine which day of the week it is.

    Outputs: 1 for Sunday, 2 for Monday, 3 for Tuesday, ... 7 for Saturday. 
             Gives a -1 if a year below 1700 is given.
**************************************************************************/
int day_of_the_week(int day, int month, int year)
{
  /* 
   * Using Zeller's Rule. However, we are going to use a different, simpler 
   * key/value method that is very different from Zeller's algorithm.
   */
   
  /* Preset keys for the months for algothrim. */
  int month_keys[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
  
  /* Preset keys for the years for algothrim. */
  int year_keys[] = {4, 2, 0, 6};
  
  int last_digits; /* Last two digits of the year.   */
  int result;      /* The result of which day it is. */
  
  /* Set the month - 1 to match it to month_keys. */
  month--;
  
  /* Check if year is below 1700. We do not handle that. */
  if(year < 1700)
  {
    /* Give a -1. */
    return -1;
  }
  
  /* Extract the last two digits from the year. */
  last_digits = year % 100;
  
  /* Divide it by 4, store in another variable. */
  result = last_digits / 4;
  
  /* Add the day of the month to the number. */
  result += day;
  
  /* Add the month's key value. */
  result += month_keys[month];
  
  /* If the date is in January or February AND the year is a leap year, 
   * subtract 1 from the total so far.
   */
  if((is_leapyear(year) && month == 0) ||
  (is_leapyear(year) && month == 1))
  {
    result -= 1;
  }
  
  /* Make sure that the century value is within the range of 1700 to 2099. */
  while(year > 2099)
  {
    /* Gregorian calendar repeats every 400 years. */
    year -= 400;;
  }
  
  /* Add the century key value depending on which year it is. */
  if(year > 2000 && year < 2099 ) /* Between 2000 and 2099 */
  {
    result += year_keys[3];
  }
  else if(year > 1900 && year < 1999)/* Between 1900 and 1999 */
  {
    result += year_keys[2];
  }
  else if(year > 1800 && year < 1899)/* Between 1800 and 1899 */
  {
    result += year_keys[1];
  }
  else /* Between 1700 and 1799. 1700 and below are handled above. */
  {
    result += year_keys[0];
  }
  
  /* Add the last two digits extracted to the main value. */
  result += last_digits;
  
  /* And give the remainder of 7. Limit it to 0 - 6. */
  result %= 7;
  
  /* Saturday gives 7, we return a 7 for that.*/
  if(result == 0)
  {
    return 7;
  }
  
  /* Result should be within 1 to 7. */
  return result;
}

/**************************************************************************
   Function: print_calendar
 
Description: Prints out the calander for the given month and year.

     Inputs: month - The month of print out.
             year  - The year the month is in.

    Outputs: None. Prints to screen.
**************************************************************************/
void print_calendar(int month, int year)
{
  /* The days in each month. */
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  /* C-string representation of months. */
  char *months[] = {"January",   "February", "March",    "April", 
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};
  int date_of_month_start; /* Holds the first day of the week of the month. */
  int i;                   /* Loop variables.                               */

  /* Get the first day of the month. */
  date_of_month_start = day_of_the_week(1, month, year);
  
  /* Print calendar header format. */
  printf("%s, %i\n", months[month - 1], year);
  printf("Su Mo Tu We Th Fr Sa\n");
  printf("---------------------\n");
  
  /* Create as many blank spaces as need to get to first day. */
  for(i = 0; i < date_of_month_start - 1; i++)
  {
    /* 3 spaces per day. */
    printf("   ");
  }
  
  /* Start printing out the days of the month in a formatted way. */
  for( i = 0; i < days_in_month[month - 1]; i++)
  {
    printf("%2i ", i + 1);
    
    /* Add a new line for every 7 days, AKA end of week. */
    if((i + date_of_month_start) % 7 == 0)
    {
      /* Add a new line. */
      printf("\n");
    }
  }
  
  /*
   * Last day of month could be a Saturday, causing a new line to be drawn.
   * We check if there was a new line drawn. If not, draw one. If yes, ignore. 
   */
  if((--i + date_of_month_start) % 7 != 0)
  {
    /* One more new line to end it.*/
    printf("\n");
  }
}

