/******************************************************************************
filename              randwalk.c
author                Roland Shum
DP email              roland.shum@digipen.edu
course                CS120
section               A
Practice Assignment   24
due date              12/07/2018

Brief Description:
  Practice Assigment 24. Definition of randwalk, which describes a path that 
  consists of a succession of random steps.
*******************************************************************************/
#include <stdio.h> /* Printf */
#include "PRNG.h"  /* RandomInt */

#define WIDTH 8   /* Width of the map, also the char array. */
#define HEIGHT 8  /* Height of the map, also the char array. */
#define TRUE 1    /* Magic number to emulate bool */
#define FALSE 0   /* Magic number to emulate bool */
#define START_X 0 /* Starting position in x axis. */
#define START_Y 0 /* Starting position in y axis. */

/* Enum to determine movement direction. */
typedef enum DIRECTION 
{
  dirUP,    /* Go up    = 0. */
  dirDOWN,  /* Go down  = 1. */
  dirRIGHT, /* Go right = 2. */
  dirLEFT  /* Go left  = 3. */
} DIRECTION;

/* Struct to hold position x and y values. */
typedef struct my_vector
{
  int pos_x;
  int pos_y;
} my_vector;

/*******************************************************************************
   Function: clamp
 
Description: Given a value, clamps between the given min and max. Returns the 
             value after clamp. Ex: clamp(6,0,4) returns 4.

     Inputs: value - The value to clamp.
             min   - The minumum the value is to be.
             max   - The maximum the value is to be.

    Outputs: The new value after clamping is applied.
*******************************************************************************/
int clamp(int value, int min, int max)
{
  if(value > max)
  {
    return max;
  }
  else if(value < min)
  {
    return min;
  }
  return value;
}

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
   Function: interpret_move
 
Description: Given a DIRECTION, returns the vector form of that DIRECTION.

     Inputs: direction - The direction to interpret to vector form.

    Outputs: A vector describing the move given by direction.
*******************************************************************************/
my_vector interpret_move(DIRECTION direction)
{
  my_vector vector_move;  /* The move in vector form .*/
  
  /* Interpret the DIRECTION in vector form. */
  switch(direction)
  {
    case dirUP: /* Move up. */
      init_vector(&vector_move, 0, 1);
      break;      
    case dirDOWN: /* Move down. */
      init_vector(&vector_move, 0, -1);
      break;  
    case dirRIGHT:  /* Move right. */
      init_vector(&vector_move, -1, 0);
      break;
    case dirLEFT:  /* Move left. */
      init_vector(&vector_move, 1, 0);
      break;
    default:
      /* Nothing here. */
      break;
  }
  /* Return the move in vector form. */
  return vector_move;
}

/*******************************************************************************
   Function: print_map
 
Description: Prints the given 2D char array neatly to console.

     Inputs: map - The 2D array to print out.

    Outputs: None.
*******************************************************************************/
void print_map(char map[][HEIGHT] )
{
  int i, j; /* Loop variable. */
  
  /* Print the array out. */
  for(i = 0; i < WIDTH; i++)
  {
    for(j = 0; j < HEIGHT; j++)
    {
      printf("%2c", map[i][j]);
    }
    /* Add a newline at the end of each x-line. */
    printf("\n");
  }
  /* Add a newline at the end of the printing function. */
  printf("\n");
}

/*******************************************************************************
   Function: isMoveValid
 
Description: Given a vector to the move and the 2D char map, returns TRUE (1)
             if the move is a valid move and FALSE (0) if it is not. Checks if 
             the move is in bound, and if the move will result in an empty 
             space.

     Inputs: nextMove - Pointer to the vector that, with the map, determines if
                        it is a valid placement.
             map      - 2D char array that contains '.' for moves not walked
                        before.

    Outputs: Returns TRUE (1) if the move is a valid move and FALSE (0) if it is
             not.
*******************************************************************************/
int isMoveValid(const my_vector *nextMove, char map[][HEIGHT] )
{
  /* X exceeds the bounds of map. */
  if( 0  > nextMove->pos_x || nextMove->pos_x > WIDTH)
  {
    /* Return false. */
    return FALSE;
  }
  /* Y exceeds the bounds of map. */
  else if( 0 > nextMove->pos_y || nextMove->pos_y > HEIGHT)
  {
    /* Return false. */
    return FALSE;
  }
  
  /* Checks if the move is going to result in a not empty spot. */
  if(map[nextMove->pos_x][nextMove->pos_y] != '.')
  {
    /* Return false */
    return FALSE;
  }
  
  /* All conditions met. This is an empty spot. */
  return TRUE;
}

/*******************************************************************************
   Function: isSurrounded
 
Description: Given a position and the 2D map, determines if the current position
             is surrounded. Empty spots on the map is denoted with a '.'. 
             Everything else is not an empty spot.

     Inputs: position - Pointer to the position to check if it is surrounded.
             map      - 2D char array that contains '.' for moves not walked
                        before.
    Outputs: Returns TRUE (1) if we are surrounded and FALSE (0) if we are not.
*******************************************************************************/
int isSurrounded(const my_vector *position, char map[][HEIGHT] )
{ 
  int i, j;
  
  /* Get min and max of the surrounding tiles. */
  int minIndex_x = position->pos_x - 1;
  int maxIndex_x = position->pos_x + 1;
  int minIndex_y = position->pos_y - 1;
  int maxIndex_y = position->pos_y + 1;
  
  /* Clamp the min and max values to the map so we don't exceed it. */
  minIndex_x = clamp(minIndex_x, 0, WIDTH);
  maxIndex_x = clamp(maxIndex_x, 0, WIDTH);
  minIndex_y = clamp(minIndex_y, 0, HEIGHT);
  maxIndex_y = clamp(maxIndex_y, 0, HEIGHT);
  
  /* Check every tile around it */
  for(i = minIndex_x; i <= maxIndex_x; i++)
  {
    for(j = minIndex_y; j <= maxIndex_y; j++)
    {
      /* If there is a tile that is a '.' */
      if(map[i][j] == '.')
      {
        /* There is an empty space. Return false. */
        return FALSE;
      }
    }
  }
  /* There is no empty space. Return true. */
  return TRUE;
}

/*******************************************************************************
   Function: random_walk
 
Description: Does a random walk over a 8x8 two-dimension array. Prints out the 
             path of the walker each iteration if showall is 1. If not, this 
             function will only print out the final board to the console.

     Inputs: showall - boolean (integer) that tells the function if it should 
                       show every board (each new character placement) or just 
                       show the final board 

    Outputs: None.
*******************************************************************************/
void random_walk(int showall)
{
  int i, j;
  char map[WIDTH][HEIGHT];
  char path_value = 'A';
  my_vector position;
  

  
  /* Set all elements of map to '.' */
  for(i = 0; i < WIDTH; i++)
  {
    for(j = 0; j < HEIGHT; j++)
    {
      map[i][j] = '.';
    }
  } 
  /* Set the current position to [0,0] */
  init_vector(&position, START_X, START_Y);
  
  /* Set where we currently is to A */
  map[position.pos_x][position.pos_y] = path_value;
  
  /* Move path_value up. */
  path_value ++;
  
  /* As long as there is a valid move available, keep looping. */
  while(!isSurrounded(&position, map))
  {
    /* We randomize a move. */
    int randomMove = RandomInt(0, 3);
    
    /* Interpret the move in a vector form. */
    my_vector direction = interpret_move(randomMove);
    
    /* Get the position if we do really move. */
    my_vector nextMove = add_vector(&direction, &position);
    
    /* Then we check if the move is valid */
    if(isMoveValid(&nextMove, map))
    {  
      /* Move our position to the move. */
      position = nextMove;
      
      /* Change the current tileset to path_value. */
      map[position.pos_x][position.pos_y] = path_value; 

	  /* path_value change to next letter. */
      path_value++;
      
      /* If showall is true */
      if(showall)
      {
        /* Print the array out. */
        print_map(map);
      }
        
      /* If we have walked 26 letters */
      if(path_value == 'Z')
      {
        /* Print prompt. */ 
        printf("All 26 steps were completed.\n");
        
        /* End loop. */
        break;
      }
    }
  }  
  /* If we were surrounded, we wouldn't have walked until Z */
  if (path_value != 'Z')
  {
	  /* This means we didn't walk all the way. Print that out. */
	  printf("Only completed %i steps.\n", path_value - 'A');
  }

  /* Print the array at the end. */
  print_map(map);
}