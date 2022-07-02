/**
 *  Stack program to implement stack
 *  @author Yogesh Prabhu
 */

#include "stack.h"

//Intialize stack
void init_stack(Stack *stack)
{
  stack->top = NULL;
  stack->size = 0;
}

//add or push to the stack
void push(Stack *stack, const char *data)
{
  stack_entry *entry = (stack_entry *)malloc(sizeof(stack_entry));
  if(entry == NULL)
  {
    printf("malloc failed\n");
    return;
  }
  entry->data = strdup(data);
  entry->next = stack->top;
  stack->size++;
  stack->top = entry;
}

//pop out data from stack
char *pop(Stack *stack)
{
  if(is_empty(*stack))
  {
    return NULL;
  }
  
  stack_entry *entry = stack->top;
  stack->top = entry->next;
  stack->size--;
  char *data = strdup(entry->data);
  free(entry->data);
  free(entry);

  return data;
}

//check if stack is empty
int is_empty(const Stack stack)
{
  return stack.size == 0;
}

//free stack to avoid mem leaks
void free_stack(Stack *stack)
{
  while(!is_empty(*stack))
  {
    char *data = pop(stack);
    free(data);
  }
}

void print_stack(Stack stack)
{
  stack_entry *entry = stack.top;
  while(entry != NULL)
  {
    printf("%s\n", entry->data);
    entry = entry->next;
  }
}
