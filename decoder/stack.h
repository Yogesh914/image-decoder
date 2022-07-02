/**
 * @file
 * Header file that declares the functions for stack.c for stack implementation.
 * @author Yogesh Prabhu
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack_entry 
{
  char* data;
  struct stack_entry *next;
} stack_entry;

typedef struct stack_t 
{
      size_t size;
      stack_entry *top;
} Stack;

void init_stack(Stack *stack);
void push(Stack *stack,const char* data);
char *pop(Stack *stack);
int is_empty(const Stack stack);
void free_stack(Stack *stack);
void print_stack(Stack stack);
