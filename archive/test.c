#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE  2

 typedef struct
  {
    int size;
    int capacity;
    char *data[];
  } dynamic_array; 
/*------------------------------------------------------------------*/

int main()
{

  dynamic_array array;
  char user_input[10];

  void da_append(dynamic_array *array, char *str);
  void da_free(dynamic_array *array);
  
  array.size = 0;
  array.capacity = INITIAL_SIZE;
  array.data = malloc(sizeof(char*) * array.capacity);

  /*
  char str1[] = "first string";
  char str2[] = "second string";
  char str3[] = "third string";
  char str4[] = "fourth string";
  char str5[] = "fifth string";

  da_append(&array, str1);
  da_append(&array, str2);
  da_append(&array, str3);
  da_append(&array, str4);
  da_append(&array, str5);
  */

  int flag = 0;
  
  while(strcmp(user_input, "x"))
    {
      if(flag ==1)
       {
         getchar();
       }
      printf("\nUser Input: \n");
      scanf("%s", user_input);
      flag = 1;
      da_append(&array, user_input);
    }

  int i;
  for(i = 0; i < array.size; i++)
    {
      printf("index: %d\t value: %s\n", i, array.data[i]);
    }
}


  
void da_append(dynamic_array *array, char *str)
{
  if(array->size >= array->capacity)
    {
      printf("\n::resized::\n");
      array->capacity +=2;
      array->data = realloc(array->data, sizeof(char*) * array->capacity);
    }

  array->data[array->size] = malloc(sizeof(char) * strlen(str));
  
  int i;
  for(i = 0; i < strlen(str); i ++)
    {
      array->data[i] = str;
      str++;
    }
  
  array->size++;  
}

void da_free(dynamic_array *array)
{

  free(array);
}
