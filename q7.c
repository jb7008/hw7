/*
 * Programmer : Josh Booth      Date : Apr 4 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Switches input words
 */

#include <stdio.h> /* Includes printf, scanf */

#define MAX_STR_LEN 80

void get_line(char line[MAX_STR_LEN]);
void split_line(char line[MAX_STR_LEN], char word1[MAX_STR_LEN], char word2[MAX_STR_LEN]);
int
main(void)
{
  char input_line[MAX_STR_LEN],
    word1[MAX_STR_LEN],
    word2[MAX_STR_LEN];

  get_line(input_line);

  return 0;
}

void
get_line(char line[MAX_STR_LEN])
{
  printf("Input: ");
  scanf("%s", line);
}

void
split_line(char line[MAX_STR_LEN], char word1[MAX_STR_LEN], char word2[MAX_STR_LEN])
{
  int and_index;
  char combine_word[] = "and";

  and_index = find_match_index(line, char match_word);
}
