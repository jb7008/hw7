/*
 * Programmer : Josh Booth      Date : Apr 4 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Displays database of past hurricanes using different formats
 */

#include <stdio.h> /* Includes printf, scanf */
#include <string.h> /* Includes strcpy, strcmp */

#define MAX_HURRICANES 30 /* Maximum number of hurricanes in database */
#define MAX_CHAR_LENGTH 100 /* Max length for string arrays */
#define INPUT_DATA "data.dat" /* Input data */

/* Gets data from input file and separates each element into respective array */
void get_data(FILE *inp, int years[MAX_HURRICANES],
  char names[MAX_HURRICANES][MAX_CHAR_LENGTH],
  char states[MAX_HURRICANES][MAX_CHAR_LENGTH]);

/* Prints data */
void print_data(int years[MAX_HURRICANES],
  char names[MAX_HURRICANES][MAX_CHAR_LENGTH],
  char states[MAX_HURRICANES][MAX_CHAR_LENGTH]);

/* Sorts data by name */
void sort_by_name(int years[MAX_HURRICANES],
  char names[MAX_HURRICANES][MAX_CHAR_LENGTH],
  char states[MAX_HURRICANES][MAX_CHAR_LENGTH]);

/* Sorts data by date */
void sort_by_date(int years[MAX_HURRICANES],
  char names[MAX_HURRICANES][MAX_CHAR_LENGTH],
  char states[MAX_HURRICANES][MAX_CHAR_LENGTH]);

/* Swaps values in a 1D array */
void swap_int(int a[], int i1, int i2);

/* Swaps rows in a 2d array */
void swap_char(char a[][MAX_CHAR_LENGTH], int i1, int i2);

/* Gets min value from an integer array */
int get_min_index_int(int a[], int start, int end); 

/* Gets first alphabetical index from char array */
int get_min_index_char(char a[][MAX_CHAR_LENGTH], int start, int end); 


int
main(void)
{
  FILE *inp; /* Input file */

  inp = fopen(INPUT_DATA, "r"); /* Opens input file for reading */

  int choice, /* User's choice of how to print the data */
    years[MAX_HURRICANES]; /* Holds the year each hurricane occured */
  /* Holds the names of the hurricanes */
  char names[MAX_HURRICANES][MAX_CHAR_LENGTH]; 
  /* Holds the states the hurricanes affected */
  char states[MAX_HURRICANES][MAX_CHAR_LENGTH];

  /* Gets data from input files and assigns to arrays */
  get_data(inp, years, names, states);

  fclose(inp); /* Closes input file */

  /* Gets user's choice */
  printf("****** Hurriance Report ********\n");
  printf("Sort by: 1=Name, 2=year\n");
  printf("Enter choice: ");
  scanf("%d", &choice);
  if(choice == 1)
  {
    sort_by_name(years, names, states); /* Sorts data by name */
  }
  else
  {
    sort_by_date(years, names, states); /* Sorts data by date */
  }
  print_data(years, names, states); /* Prints out data */
  
  return 0;
}

/* Gets data from input file and separates each element into respective array */
void
get_data(FILE *inp, int years[MAX_HURRICANES],
  char names[MAX_HURRICANES][MAX_CHAR_LENGTH],
  char states[MAX_HURRICANES][MAX_CHAR_LENGTH])
{
  /* Temporary string that holds unseperated line  after reading */
  char temp_string[MAX_CHAR_LENGTH];

  /* While there are lines left, read the line and split into respective
    arrays */
  for( int i = 0; fgets(temp_string, MAX_CHAR_LENGTH, inp); i++)
  {
    sscanf(temp_string, "%d %s %s", &years[i], names[i], states[i]);
  }
}

void
sort_by_name(int years[MAX_HURRICANES],
  char names[MAX_HURRICANES][MAX_CHAR_LENGTH],
  char states[MAX_HURRICANES][MAX_CHAR_LENGTH])
{
  int array_length = 0, /* Array length taken up of MAX_HURRICANES */
    min_index; /* Index of current minimum value */

  while(years[array_length++]); /* Gets the length of the arrays */

  /* Removes the extra 1 added by postfix operator */
  array_length = array_length - 1;

  for(int i = 0; i < array_length; i++)
  {
    /* Gets minimum value */
    min_index = get_min_index_char(names, i, array_length);

    /* Swaps all arrays */
    swap_int(years, i, min_index);
    swap_char(names, i, min_index);
    swap_char(states, i, min_index);
  }
}

/* Sorts data by date */
void
sort_by_date(int years[MAX_HURRICANES],
  char names[MAX_HURRICANES][MAX_CHAR_LENGTH],
  char states[MAX_HURRICANES][MAX_CHAR_LENGTH])
{
  int array_length = 0, /* Array length taken up of MAX_HURRICANES */
    min_index; /* Index of current minimum value */

  while(years[array_length++]); /* Gets the length of the arrays */
  
  /* Removes the extra 1 added by postfix operator */
  array_length = array_length - 1;

  for(int i = 0; i < array_length; i++)
  {
    /* Gets minimum value */
    min_index = get_min_index_int(years, i, array_length);
    /* Swaps all arrays */
    swap_int(years, i, min_index);
    swap_char(names, i, min_index);
    swap_char(states, i, min_index);
  }
}

/* Swaps values in a 1D array */
void
swap_int(int a[], int i1, int i2)
{
  /* Performs swap */
  int temp = a[i1];
  a[i1] = a[i2];
  a[i2] = temp;
}

/* Swaps rows in a 2d array */
void
swap_char(char a[][MAX_CHAR_LENGTH], int i1, int i2)
{
  /* Temporary array to hold swapping array */
  char temp[MAX_CHAR_LENGTH];

  /* Performs swap */
  strcpy(temp, a[i1]);
  strcpy(a[i1], a[i2]);
  strcpy(a[i2], temp);
}

/* Gets min value from an integer array */
int
get_min_index_int(int a[], int start, int end)
{
  int min = start;
  for(int i = start + 1; i < end; i++)
  {
    if(a[i] < a[min]) /* Assigns smaller value's index to min */
    {
      min = i;
    }
  }
  return min;
}

/* Gets first alphabetical index from char array */
int
get_min_index_char(char a[][MAX_CHAR_LENGTH], int start, int end)
{
  int min = start;
  for(int i = start + 1; i < end; i++)
  {
    if(strcmp(a[i], a[min]) < 0) /* strcmp return < 0 if a[i] < a[min] */
    {
      min = i; /* Assigns smaller index to min */
    }
  }
  return min;
}


/* Prints data */
void print_data(int years[MAX_HURRICANES],
  char names[MAX_HURRICANES][MAX_CHAR_LENGTH],
  char states[MAX_HURRICANES][MAX_CHAR_LENGTH])
{
  /* Prints data for number of years since each array has the same
    number of entries */
  for(int i = 0; years[i]; i++)
  {
    printf("%d\t%s\t%s\t\n", years[i], names[i], states[i]);
  }
}
