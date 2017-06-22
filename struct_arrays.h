#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct my_struct {
  char *name;
  int index;
  int array_size;
  char **string_array;
};


struct my_struct *make_struct(char *name, int index, char **string_array, int array_size)
{
  struct my_struct *who = malloc(sizeof(struct my_struct *));
  int i;
				 
  who->name = strdup(name);
  who->index = index;
  who->array_size = array_size;
  who->string_array = malloc(array_size * sizeof(char *));

  for (i = 0; i < array_size; i++) {
    who->string_array[i] = string_array[i];
  }
  
  return who;
}
