/******************************************************************************
filename      list.c
author        Roland Shum
DP email      roland.shum@digipen.edu
course        CS120
section       A
Lab           11
due date      11/21/2018

Brief Description:
  Lab 11. Definitions of add_front, add_back, free_list, print_list,
  remove_item, size_list, and sum_list. All these functions are functions for
  a linked list.
******************************************************************************/
#include <stdio.h>  /* printf, */
#include <stdlib.h> /* malloc, free, NULL, */
#include "list.h"   /* struct Node */
/*******************************************************************************
   Function: add_front
 
Description: Given a list, add a new node to the front of the list that contains
             value.

     Inputs: list  - The double pointer to the first node, aka the head.
             value - The number for the new node to hold.

    Outputs: None
*******************************************************************************/
void add_front(struct Node **list, int value)
{
  /* Create a new node with malloc */
  struct Node *newNode = malloc(sizeof(struct Node));
  
  /* Set value. */
  newNode->number = value;
  
  /* Set the new node -> next to be the address of the list. */
  newNode->next = *(list);
  
  /* Set the head to point at new node. */
  *list = newNode;
}

/*******************************************************************************
   Function: add_back
 
Description: Given a list, add a new node to the back of the list that contains 
             value. 

     Inputs: list  - The double pointer to the first node, aka the head.
             value - The number for the new node to hold.

    Outputs: None
*******************************************************************************/
void add_back(struct Node **list, int value)
{ 
  /* Get the first node in the list. */
  struct Node *currentNode = (*list);
  
  /* A pointer to the new node we might create. */
  struct Node *newNode;
  
  /* If there is nothing in the list in the first place, we call addfront. */
  if(*list == NULL)
  {
    /* End the function after adding to the front. */
    add_front(list, value);
    return;
  }
  /* Create a new node with malloc */
  newNode = malloc(sizeof(struct Node)); 
  
  /* Put in value. */
  newNode->number = value;
  
  /* Node is at end, point to nothing. */
  newNode->next = NULL;
  
  /* Loop all the way to the end of the list while doing forward checking. */
  while(currentNode->next != NULL)
  {
    currentNode = currentNode->next;
  }
  
  /* Set the last node to look at newnode. */
  currentNode->next = newNode;
}

/*******************************************************************************
   Function: free_list
 
Description: Given a list, free all of the nodes on the list. 

     Inputs: list - The pointer to the first node.

    Outputs: None
*******************************************************************************/
void free_list(struct Node *list)
{ 
 /* Get a pointer to the current node so we don't lose it. */
  struct Node *currentNode = list;
    
  /* Loop through till the end of the linked list*/
  while(currentNode)
  {
    /* Get a pointer to the next node so we don't lose it. */
    struct Node *nextNode = currentNode->next;
    
    /* Free the current node. */
    free(currentNode);
    
    /* Point current node to NULL. */
    currentNode = nextNode;
  }
}

/*******************************************************************************
   Function: print_list
 
Description: Given a list, print the value of each node. The format specifier 
             for the printf function is "%3i". 

     Inputs: list - The pointer to the first node, aka the head.

    Outputs: None
*******************************************************************************/
void print_list(const struct Node *list)
{
  /* Loop through till the end of the linked list*/
  while(list)
  {
    /* Print the number. */
    printf("%3i", list->number);
    
    /* Point to the next node and continue. */
    list = list->next;
  }
  printf("\n");
}

/*******************************************************************************
   Function: remove_item
 
Description: Given a list, remove the node that contains value. If there are 
             multiple nodes that contain the same value, only the first node 
             encountered with the value would be removed.

     Inputs: list  - The double pointer to the first node, aka the head.
             value - The number which the node must hold to be removed.

    Outputs: None
*******************************************************************************/
void remove_item(struct Node **list, int value)
{
    /* Create a pointer to the head, so we can modify safely. */
  struct Node *currentNode = *list;
  struct Node *nextNode;
  
  /* Check if first node is null. */
  if(currentNode == NULL)
  {
    /* End the function if there is no list at all. */
    return;
  }
  
  /* Point to the next node after current. */
  nextNode = currentNode->next;
  
  /* Our first node is the one to remove. */
  if(currentNode->number == value)
  {
    /* Point the head to the next node. */
    *list = nextNode;
    
    /* Free the current node. */
    free(currentNode);
    
    /* Remember to set the pointer to NULL. */
    currentNode = NULL;
    
    /* We have removed something. End function. */
    return;
  }
  
  /* Loop through till the end of the linked list*/
  while(nextNode)
  {
    /* Is the next node the one to remove? */
    if(nextNode->number == value)
    {
      /* Remove the next node and link current to it. */
      currentNode->next = nextNode->next;
      
      /* Free the next node and make sure it points to NULL. */
      free(nextNode);
      nextNode = NULL;
      
      /* End the function. */
      return;
    }
    /* Set the current pointer. */
    currentNode = nextNode;
    
    /* Point to the next node and continue. */
    nextNode = nextNode->next;
  }
}

/*******************************************************************************
   Function: size_list
 
Description: Given a list, count the number of nodes in the list and return 
             that value. 

     Inputs: list - The pointer to the first node.

    Outputs: The number of nodes in the list.
*******************************************************************************/
int size_list(const struct Node *list)
{ 
  int sizelist = 0;
  
  /* Loop through till the end of the linked list*/
  while(list)
  {
    /* Record the size as we go. */
    sizelist++;
    
    /* Point to the next node and continue. */
    list = list->next;
  }
  /* Return the size of the list. */
  return sizelist;
}

/*******************************************************************************
   Function: sum_list
 
Description: Given a list, add up all of the values in the nodes and return that
             value.

     Inputs: list - The pointer to the first node.

    Outputs: The sum of all the values in each node.
*******************************************************************************/
int sum_list(const struct Node *list)
{
  /* The sum of all the values in each node. */
  int sum = 0;
  
  /* Loop through till the end of the linked list*/
  while(list)
  {
    /* Add to sum as we move through each node. */
    sum += list->number;
    
    /* Point to the next node and continue. */
    list = list->next;
  }
  /* Returns the sum of all the numbers. */
  return sum;
}