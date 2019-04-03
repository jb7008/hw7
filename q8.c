/*
 * Programmer : Josh Booth      Date : Apr 4 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Finds the longest common suffix between two words
 */

#include <stdio.h> /* Includes printf, scanf */
#include <string.h> /* Includes strlen */

#define MAX_WORD_LEN 80 /* Max length of a string */

/* Gets index of the first word at the first difference between the two words */
int cmp_ends(char word1[MAX_WORD_LEN], char word2[MAX_WORD_LEN]);

int
main(void)
{
  int index_of_diff; /* Index of difference in first word */
  char word1[MAX_WORD_LEN], /* 1st word */
    word2[MAX_WORD_LEN]; /* 2nd word */

  /* Gets words */
  printf("Enter word1: ");
  scanf("%s", word1);

  printf("Enter word2: ");
  scanf("%s", word2);

  /* Gets index of the first word at the first difference
    between the two words */
  index_of_diff =  cmp_ends(word1, word2);

  /* Prints the last portion of word1 (part that is the same between the words)
    the additional operations add the offset of the difference index to word1,
    with the +1 being used to convert from index to memory amount */
  printf("%s\n", word1 + strlen(word1) - index_of_diff + 1);

  return 0;
}

/* Gets index of the first word at the first difference between the two words */
int
cmp_ends(char word1[MAX_WORD_LEN], char word2[MAX_WORD_LEN])
{
  int word1_len = strlen(word1), /* Length of first word */
    word2_len = strlen(word2); /* Length of second word */

  /* Reduce the word lengths until a difference in found */
  while(word1[word1_len] == word2[word2_len])
  {
    word1_len--;
    word2_len--;
  }

  return(strlen(word1) - word1_len); /* Returns index of first differing char */
}
