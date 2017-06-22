#include <stdio.h>
#include <stdlib.h>
#include "dynamic_arrays.h"

void da_init(dynamic_array *array)
{

  array->size = 0;
  array->capacity = INITIAL_ARRAY_SIZE;
  array->data = malloc(sizeof(char*) * array->capacity);
}

void da_append(dynamic_array *array, char *str)
{

  //check to see if allocated size is sufficient
  if(array->size >= array->capacity){
    //allocate more space if necessary
    da_allocate(array);
  }
  array->data[size] = str;
}

void da_allocate(dynamic_array *array)
{

  array->capacity += 10:
  array->data = realloc(array->data, sizeof(char*) * array->capacity);
}

void da_free(dynamic_array *array)
{

}
