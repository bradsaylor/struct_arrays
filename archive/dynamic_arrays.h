#define INITIAL_ARRAY_SIZE 10

typedef struct
{
  int size;
  int capacity;
  char **data;
} dynamic_array;


void da_init(dynamic_array *array);
void da_append(dynamic_array *array, char *str);
void da_allocate(dynamic_array *array);
void da_free(dynamic_array *array);
