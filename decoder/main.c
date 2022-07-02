/**
 * Main file to take input file and use decoder.c and stack.c to calculate,
 * decoder and print the image.
 * 
 * @author Yogesh Prabhu
 */

#include "decoder.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage: decoder file\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    printf("Unable to open input file\n");
    return 1;
  }

  Stack stack;
  init_stack(&stack);

  //read the file line by line and push the characters onto the stack without
  //end of line characters
  char line[1000];
  //the key is the first line of the file
  char *key = NULL;
  int i;
  while (fgets(line, 1000, fp) != NULL)
  {
    if (key == NULL)
    {
      key = strdup(line);
      continue;
    }

    for (i = 0; i < strlen(line); i++)
    {
      if (line[i] == '\n')
      {
        line[i] = '\0';
        break;
      }
    }
    push(&stack, line);
  }
  decodeImage(&stack, key);
  //print_stack(stack);
  free_stack(&stack);
  free(key);
  fclose(fp);
  return 0;
}


