/*
 * Programmer : Josh Booth      Date : Apr 4 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Finds the longest common suffix between two words
 */

#include <stdio.h> /* Includes printf, scanf */

#define MAX_WORD_LEN 80

int cmp_ends(char word1[MAX_WORD_LEN], char word2[MAX_WORD_LEN]);

int
main(void)
{
  int index_from_end;
  char word1[MAX_WORD_LEN],
    word2[MAX_WORD_LEN];

  printf("Enter word1: ");
  scanf("%s", word1);

  printf("Enter word2: ");
  scanf("%s", word2);

  index_from_end =  cmp_ends(word1, word2);
  return 0;
}

int
cmp_ends(char word1[MAX_WORD_LEN], char word2[MAX_WORD_LEN])
{
  int word1_len = 0,
    word2_len = 0;
  while(word1[word1_len++]);
  word1_len--;
  while(word2[word2_len++]);
  word2_len--;
  while(word1[

}
