/******************************************************************************
filename              magic.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   25
due date              12/14/2018

Brief Description:
  Practice Assigment 25. Holds the definition of magic_square. Go to this link
  to learn more. https://en.wikipedia.org/wiki/Magic_square
*******************************************************************************/
#include <stdio.h> /* Printf */
#include <stdlib.h> /* calloc, free, malloc */

#define FALSE 0  /* Bool false. */
#define TRUE  1  /* Bool true.  */
/* Struct to hold position x and y values. */
typedef struct my_vector
{
  int pos_x;  /* x value. */
  int pos_y;  /* y value. */
} my_vector;

/*******************************************************************************
   Function: init_vector

Description: Given a pointer to a my_vector struct, sets its x and y components
             to the given x and y.

     Inputs: vec - A pointer to the vector to set.
             x   - The value of the x component of vec to be.
             y   - The value of the y component of vec to be.

    Outputs: None.
*******************************************************************************/
void init_vector(my_vector *vec, int x, int y)
{
  /* Sets the vector x and y components to the given x and y inputs. */
  vec->pos_x = x;
  vec->pos_y = y;
}

/*******************************************************************************
   Function: add_vector

Description: Given two vectors, adds the x and y components and returns a vector
             containing the sum in the x and y. [5,2] + [2,1] = [7,3]

     Inputs: vec_one - Pointer to the first vector to add.
             vec_two - Pointer to the second vector to add.

    Outputs: A copy that contains the sum of the x and y components of vec_one
             and vec_two.[4,2] + [2,1] = [6,3]
*******************************************************************************/
my_vector add_vector(const my_vector *vec_one, const my_vector *vec_two)
{
  my_vector vector_sum; /* Create a new object to hold the sum of two vector. */

  /* Add the x and y components of one and two and set to sum. */
  vector_sum.pos_x = vec_one->pos_x + vec_two->pos_x;
  vector_sum.pos_y = vec_one->pos_y + vec_two->pos_y;

  /* Return a copy of the sum since we don't want to deal with memory. */
  return vector_sum;
}

/*******************************************************************************
   Function: print_map

Description: Given a pointer to a 2D array, and the x and y size of the array,
             prints the array to the console.

     Inputs: map   - Double pointer to the 2D int array.
             sizex   - The size of the x-axis of the array.
             sizey   - The size of the y-axis of the array.
       newline - boolean, 1 to print new line after printing everthing. 0
             to not.

    Outputs: None.
*******************************************************************************/
void print_map(int **map , int sizex, int sizey, int newline)
{
  int i, j; /* Loop variables. */

  /* Double loop for each variable in 2D map. */
  for(i = 0; i < sizey; i++)
  {
    for(j = 0; j < sizex; j++)
    {
      int number = map[j][i];

      /* If the position on the map is occupied by a number. */
      if(number != 0)
      {
        /* Print it out. */
        printf("%5i", number);
      }
      else  /* Else the number is 0, meaning its empty. */
      {
        /* Print the '.' */
        printf("%5c",'.');
      }
    }
    /* Newline at end of printing of width. */
    printf("\n");
  }

  if (newline)
  {
    printf("\n");
  }
}

/*******************************************************************************
   Function: Wrap

Description: Given an int and the upperbounds and its lowerbounds, applies
             wrapping to it and returns the value after wrapping.

     Inputs: value       - The value to evaluate
             lowerBound  - The lower bounds of the wrap.
             higherBound - The upper bounds of the wrap.

    Outputs: The value after wrapping is applied. Guranteed to be between lower
             bounds and upper bounds.
*******************************************************************************/
int Wrap(int value, int lowerBound, int higherBound)
{
  /* Get the size of the range. */
  int range_size = higherBound - lowerBound;

  /* If the value is below the lower bound. */
  if(value < lowerBound)
  {
    /* Handle the underflow  */
    value += range_size * ((lowerBound - value) / range_size + 1);
  }
  /* Handle overflow. */
  return lowerBound + (value - lowerBound) % range_size;
}

/*******************************************************************************
   Function: applyWrapVector

Description: Given a x-y point, wraps the point to be inside sizex and sizey if
             necessary.

     Inputs: move  - A pointer to the move to apply wrapping. Will be modifed.
             sizex - The size of the x-axis of the array.
             sizey - The size of the y-axis of the array.

    Outputs: None.
*******************************************************************************/
void applyWrapVector(my_vector *move, int sizex, int sizey)
{
  move->pos_x = Wrap(move->pos_x, 0, sizex);
  move->pos_y = Wrap(move->pos_y, 0, sizey);
}

/*******************************************************************************
   Function: isMoveValid

Description: Given a pointer to a 2D array, and the x and y size of the array,
             and a move, returns if the spot on the map will be an empty spot
             (aka a 0). Will do wrapping as necessary.

     Inputs: map   - Double pointer to the 2D int array.
             move  - A pointer to the move to check if it is valid.
             sizex - The size of the x-axis of the array.
             sizey - The size of the y-axis of the array.

    Outputs: Returns TRUE (1) if the move is valid. Returns FALSE (0) if not.
*******************************************************************************/
int isMoveValid(int **map , my_vector *move, int sizex, int sizey)
{
  /* Apply wrapping to the move. */
  applyWrapVector(move, sizex, sizey);

  /* If the current position is occupied, aka not 0, */
  if(map[move->pos_x][move->pos_y] != 0)
  {
    /* Not a valid move. Return false. */
    return FALSE;
  }
  /* Else the position is empty, return true. */
  return TRUE;
}

/*******************************************************************************
   Function: magic_square

Description: Given a size, creates a size * size square that and populate it
             with values that will add up to the same number such that each cell
             contains a different integer and the sum of the integers in each
             row, column and diagonal is equal, as shown below. The sum of the
             number is known as the magic sum, and it is 15 for below.

           15 15  15 15
             -----------
         15  | 8, 1, 6 |
         15  | 3, 5, 7 |
         15  | 1, 9, 2 |
             -----------

     Inputs: size    - The size of the sqaure. If this is not an odd number, the
                       function will end.
             showall - Boolean to show every step. 1 to show. 0 to hide.

    Outputs: The magic sum of the sqaure. Will return 0 if the input is an even
             size.
*******************************************************************************/
int magic_square(int size, int showall)
{
  int i;                    /* Loop variable                                 s*/
  int *real_map = NULL;     /* Double pointer to instantiate 2D array later. */
  int **map = NULL;         /* This one will allow us to use [][] operators. */
  my_vector current_pos;    /* Variable to hold the starting position.       */
  int current_number = 1;   /* The number to place at the map/grid.          */
  int magic_number = 0;     /* The magic number.                             */

  /* Size given is even. End function. */
  if(size % 2 == 0)
  {
    /* Return 0 to signify nothing. */
    return 0;
  }

  /* Instantiate 2D array and set them to 0 */
  real_map = calloc(size * size, sizeof(int));

  /* Instantiate these pointers so we can point into the real_map and use [] */
  map = malloc(size * sizeof(int));
  for (i = 0; i < size; i++)
  {
    map[i] = real_map + (size * i);
  }

  /* Set the starting position to be in the middle of row 0. */
  init_vector(&current_pos, size / 2, 0);

  /* Place our number there and increment to next number. */
  map[current_pos.pos_x][current_pos.pos_y] = current_number++;

  /* Print this step is showall */
  if(showall)
  {
    print_map(map , size, size, 1);
  }
  /* While our entire grid is not filled up. Total size of sqaure is size^2 */
  while(current_number <= (size * size))
  {
    /* We calculate if the next move is valid. First create the direction. */
    my_vector direction;

    /* We want to have the next position stored here. */
    my_vector nextMove;

    /* Initialize it */
    init_vector(&direction, 1, -1);

    /* Get the nextMove */
    nextMove = add_vector(&current_pos, &direction);

    /* If move is valid */
    if(isMoveValid(map, &nextMove, size, size))
    {
      /* Set our position to the new position. */
      current_pos = nextMove;

      /* Place our number and increment to next number. */
      map[current_pos.pos_x][current_pos.pos_y] = current_number++;
    }
    else  /* Else the move is not valid. */
    {
      /* Set our position to the one below us. */
      current_pos.pos_y += 1;

      /* Apply wrapping. */
      applyWrapVector(&current_pos, size, size);

      /* Place our number and increment to next number. */
      map[current_pos.pos_x][current_pos.pos_y] = current_number++;
    }
    if(showall)  /* If we are showing every step */
    {
      /* Print each step out. */
      print_map(map , size, size, 1);
    }
  }

  /* We only print this part out if showall was not enabled. */
  if (!showall)
  {
    /* Print the final answer out. */
    print_map(map, size, size, 0);
  }

  /* Calculate magic number. */
  for(i = 0; i < size; i++)
  {
    /* Add all the numbers in the first row. */
    magic_number += map[0][i];
  }
  /* Free the memory. */
  free(real_map);
  free(map);

  /* Return the magic sum. */
  return magic_number;
}