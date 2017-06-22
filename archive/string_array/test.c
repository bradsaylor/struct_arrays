#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 0

typedef struct
{
  int size;
  int capacity;
  char **data;
} dynamic_array;

int main()
{
  void da_add_string(dynamic_array *array, char *str);
  void da_free(dynamic_array *array);
  
  dynamic_array array;
  array.size = 0;
  array.capacity = INITIAL_SIZE;  
  array.data = malloc(INITIAL_SIZE * sizeof *array.data);
  
  int i;
  int flag = 0;
  int count = 0;
  char user_input[80];

  do
    {
      if(flag ==1)
	{
	  getchar();
	}
      printf("Enter a string: ");
      scanf("%s", user_input);
      da_add_string(&array, user_input);
      array.size++;
      flag = 1;
    }while(strcmp(user_input, "x"));

  
  for(i = 0; i < array.size; i++)
    {
      printf("index: %d\t value: %s\n", i, array.data[i]); 
    }
  printf("\nsize of array: %d", array.size);
  da_free(&array);
}
		
void da_add_string(dynamic_array *array, char *str)
{
      
  array->data[array->size] = malloc(sizeof **array->data);
  strcpy(array->data[array->size], str);
}


void da_free(dynamic_array *array)
{
  int i;
  for(i = 0; i < array->size; i++)
    {
      free(array->data[i]);
    }
}
