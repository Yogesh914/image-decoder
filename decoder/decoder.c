/**
 * Decoder program using stack implementation to decoder binary
 * using first line as key to decoder each line
 * @author Yogesh Prabhu
 */
#include <stdio.h>
#include "decoder.h"

/**
 * Decode the given line of the image.
 * @param encoded the line to decode
 * @param key the key to use
 * @param rol the rol to use
 * @return the decoded line
 */
char* decodeLine(char* encoded, char* key, size_t rol)
{
  int i, j;
  char* decoded = strdup(encoded);
  memset(decoded, '0', strlen(encoded));
  for(i = 0; i < strlen(encoded); i++)
  {
    if(encoded[i] != key[i])
      decoded[i] = '1';
  }

  for(i = 0; i < rol; i++)
  {
    char temp = decoded[0];
    for(j = 0; j < strlen(decoded) - 1; j++)
    {
      decoded[j] = decoded[j + 1];
    }
    decoded[strlen(decoded) - 1] = temp;
  }

  return decoded;
}

/**
 * Decode the file to image.
 * @param key the key to use
 * @param image the image to decode
 * @return the decoded image
 */
void decodeImage(Stack *stack, char *key)
{
  size_t rol = stack->size-1;
  while(!is_empty(*stack))
  {
    char *line = pop(stack);
    char *decoded = decodeLine(line, key, rol);
    printLine(decoded);
    free(decoded);
    free(line);
    rol--;
  }
}

/**
 * @brief print the bites to the console with 1 -> 'X' and 0 -> ' '
 * @param line the line to print
 */
void printLine(char *line)
{
  int i;
  for(i = 0; i < strlen(line); i++)
  {
    printf("%c", line[i] == '1' ? 'X' : ' ');
  }
  printf("\n");
}
