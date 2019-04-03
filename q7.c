/*
 * Programmer : Josh Booth      Date : Apr 4 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Switches input words
 */

#include <stdio.h> /* Includes printf, scanf */
#include <string.h> /* Includes strncpy and strcpy */

#define MAX_STR_LEN 80 /* Max length of a string */
#define MAX_NUM_OF_WORDS 16 /* Number of words that can be inputted */

void get_line(char line[MAX_STR_LEN]); /* Reads input line */
  /* Splits and line on spaces and prints reversed words */
void reverse_line(char line[MAX_STR_LEN],\
  char words[MAX_NUM_OF_WORDS][MAX_STR_LEN]);

int
main(void)
{
  char input_line[MAX_STR_LEN], /* Holds input string */
    words[MAX_NUM_OF_WORDS][MAX_STR_LEN]; /* Holds individual words */

  get_line(input_line); /* Gets input line */
  /* Splits and line on spaces and prints reversed words */
  reverse_line(input_line, words);



  return 0;
}

/* Reads input line */
void
get_line(char line[MAX_STR_LEN])
{
  printf("Input: ");
  gets(line);
}

/* Splits and line on spaces and prints reversed words */
void
reverse_line(char line[MAX_STR_LEN], char words[MAX_NUM_OF_WORDS][MAX_STR_LEN])
{
    int space_index = 0, /* Current word in words[][] */
    i = 0; /* Iterator through line */

  while(i < strlen(line)) /* While end hasn't been reached */
  {
    if(line[i++] == ' ') /* If there is a space */
    {
      /* Copy string up to that point into words
        ( - 1 removes space from copy) */
      strncpy(words[space_index++], line, i - 1);
      line = line + i; /* Moves line onto next chracter after space */
      i = 0; /* Reset i */
    }
  }
  /* Copy the last word, since no space will be found */
  strcpy(words[space_index], line);
  /* Formatting */
  printf("Output: ");
  /* Print the words in words[][] in reverse order */
  printf("%s\n", words[0]);
  printf("%s\n", words[1]);
  printf("%s\n", words[2]);
  while(space_index >= 0)
    printf("%s ", words[space_index--]);
  printf("\n");
}

