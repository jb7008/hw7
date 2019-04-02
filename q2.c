/*
 * Programmer : Josh Booth      Date : Apr 4 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Calculates and displays the resistance of a resistor based on the colors
 * of the 3 bands
 */

#include <stdio.h> /* Includes printf, scanf */
#include <string.h> /* Includes strcmp */
#include <math.h> /* Includes pow */

#define NUM_OF_BANDS 3 /* Number of bands on resistor */
#define MAX_STR_LEN 15 /* Max length of input strings */
#define NUM_OF_COLOR_CODES 10 /* Number of band colors */

/* Finds the index of the target in color_codes */
int search(char color_codes[NUM_OF_COLOR_CODES][MAX_STR_LEN],
  int color_code_len, char target[MAX_STR_LEN]);

int
main(void)
{
  /* Flags for keeping the program running if the user wants to input more
    values */
  int run_program_flag = 1,
    /* Length of color_coldes in a variable */
    color_code_len = NUM_OF_COLOR_CODES,
    resistance; /* Value of the resistance */

  char bands[NUM_OF_BANDS][MAX_STR_LEN], /* Input bands */
    /* Char variable to hold y or n for if user wants to run program again */
    continue_running,
    /* Static array of the possible color code combinations */
    color_codes[NUM_OF_COLOR_CODES][MAX_STR_LEN] = {"black", "brown", "red",
    "orange", "yellow", "green", "blue", "violet", "gray", "white"};

  while(run_program_flag) /* While the user wants to run the program */
  {
    /* Displays information about the program */
    printf("Enter the colors of the resistor's three bands, beginning with\n"
           "the band nearest the end. Type the colors in lowercase letters "
           "only, NO CAPS.\n");
    /* Gets the band colors */
    printf("Band 1 => ");
    scanf("%s", bands[0]);

    printf("Band 2 => ");
    scanf("%s", bands[1]);

    printf("Band 3 => ");
    scanf("%s", bands[2]);

    /* Checks if any of the searches returns with an error */
    if(search(color_codes, color_code_len, bands[0]) == -1)
    {
      printf("Invalid color: %s\n", bands[0]);
    }
    else if(search(color_codes, color_code_len, bands[1]) == -1)
    {
      printf("Invalid color: %s\n", bands[1]);
    }
    else if(search(color_codes, color_code_len, bands[2]) == -1)
    {
      printf("Invalid color: %s\n", bands[2]);
    }
    else{ /* If they do not proceeds with calculation */

      /* Gets first digit of resistance value */
      resistance = search(color_codes, color_code_len, bands[0]) * 10;
      resistance += search(color_codes, color_code_len, bands[1]);
      resistance *= pow(10, search(color_codes, color_code_len, bands[2]));

      /* Displays resistance values converted to kilo-ohms */
      printf("Resistance value: %.1f kilo-ohms\n", resistance / 1000.0);
    }
    
    /* Checks if the user wants to run the program again */
    printf("Do you want to decode another resistor?\n=>");
    getchar();
    scanf("%c", &continue_running);

    if(continue_running == 'n') /* If users doesn't want to continue */
    {
      run_program_flag = 0; /* Sets flags to 0 to exit while loop */
    }
  }
}

/* Finds the index of the target in color_codes */
int search(char color_codes[NUM_OF_COLOR_CODES][MAX_STR_LEN],
  int color_code_len, char target[MAX_STR_LEN])
{
  int target_index = 0; /* Start search from beginning */
  while(target_index < color_code_len) /* While the end hasn't been reached */
  {
    /* If the strings match */
    if(strcmp(target, color_codes[target_index]) == 0)
    {
      return target_index; /* Returns the index */
    }
    else
    {
      target_index++; /* Move onto the next index */
    }
  }
  return -1; /* If no matches have been found */
}

