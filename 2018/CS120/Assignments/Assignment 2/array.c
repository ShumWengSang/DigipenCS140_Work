/******************************************************************************
filename    array.c
author      Roland Shum
DP email    roland.shum@digipen.edu
course      CS120
section     A
week        8
due date    10/18/2018

Brief Description:
  Assignment 2. Holds the definition of five functions, reverse_array, 
  add_arrays, scalar_multiply, dot_product, and cross_product. All of the 
  functions has a parameter for arrays.
  
******************************************************************************/

/**************************************************************************
   Function: reverse_array
 
Description: Reverses the order of elements in a given array. We do this
             by swapping the left and right elements, and keep
             doing this until the end. Odd sizes are naturally handled this
             way.

     Inputs: a    -- The given array to reverse
             size -- The size of the array to reverse.

    Outputs: void
**************************************************************************/
void reverse_array(int a[], int size)
{
  int i; /* Loop varaible.    */
  
  /* Loop over half array size. Since each swap would change two variables. */
  for(i = 0; i < (size / 2); i++)
  { 
    int temp_copy; /* A temporary copy. */
    
    /* Keep a temp variable of the value of left variable of array. */
    temp_copy = a[i]; 
    
    /* Set left variable to value of right variable. */
    a[i] = a[size - 1 - i];
    
    /* Set right variable to value of copy. */
    a[size - 1 - i] = temp_copy;
  }
} 

/**************************************************************************
   Function: add_arrays
 
Description: Given three arrays, add the elements of the first two
             arrays and put the sum in the third array. We loop over each 
             element of a and b, and add it into c.

     Inputs: a    -- First array to add.
             b    -- Second array to add.
             c    -- The array to put the sum of a and b.
             size -- The size of the arrays to reverse.

    Outputs: void
**************************************************************************/
void add_arrays(const int a[], const int b[], int c[], int size)
{
  int i; /* Loop varaible. */
  
  /* Loop through array a, b, and c. */
  for(i = 0; i < size; i++)
  {
    /* Set the respective element of c to the sum of a and b. */
    c[i] = a[i] + b[i];
  }
}

/**************************************************************************
   Function: scalar_multiply
 
Description: Given an array and a multiplier, multiply each
             element by the multiplier. We loop through the array and multiply
             each element by the multiplier.

     Inputs: a          -- First array to add.
             size       -- The size of the array to reverse.
             multiplier -- The scalar value to multiply the array with.

    Outputs: void
**************************************************************************/
void scalar_multiply(int a[], int size, int multiplier)
{
  int i; /* Loop variable. */
  
  /* Loop through array. */
  for(i = 0; i < size; i++)
  {
    /* Multiply the number by multiplier. */
    a[i] *= multiplier;
  }
}

/**************************************************************************
   Function: dot_product
 
Description: Given two arrays, determine and return the dot product 
             (multiply each corresponding element and sum the products). 

     Inputs: a    -- First array to dot product with.
             b    -- Second array to dot product with.
             size -- The size of the arrays to reverse.

    Outputs: The calculated dot product of the two given arrays.
**************************************************************************/
int dot_product(const int a[], const int b[], int size)
{
  int i;       /* Loop variable.    */
  int sum = 0; /* The return value. */
  
  /* Loop through both arrays. */
  for(i = 0; i < size; i++)
  {
    /* Multiply the element in a and b, then add it to sum. */
    sum += a[i] * b[i];
  }
  /* Return the calculated dot product. */
  return sum;
}

/**************************************************************************
   Function: cross_product
 
Description: Given three arrays, determine the cross product of the
             first two. The cross product is another array and will
             be placed into the third array. The size of all three
             arrays will always be 3

     Inputs: a -- First array to cross product with.
             b -- Second array to cross product with.
             c -- The third array that holds the cross product of a and b.

    Outputs: void
**************************************************************************/
void cross_product(const int a[], const int b[], int c[])
{
  /* c1 = a2*b3 - a3*b2 */
  c[0] = a[1] * b[2] - a[2] * b[1];
  
  /* c2 = -(b3·a1 - b1·a3) */
  c[1] = -(b[2] * a[0] - b[0] * a[2]);
  
  /* c3 = a1·b2 - a2·b1 */
  c[2] = a[0] * b[1] - a[1] * b[0];
}
