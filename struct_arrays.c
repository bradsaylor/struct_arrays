#include <stdio.h>
#include <stdlib.h>
#include "struct_arrays.h"


int main(int argc, char *argv[])
{
  int i = 0;
  int j = 0;
  int count = 0;
  char temp_string[30];
  
  char name[20];
  char s_index[3];
  int index;
  char **string_array = malloc(0 * sizeof(char *));
  int array_size = 0;
  

  struct my_struct **db = malloc(count * sizeof(struct my_struct *));

  while(count < 3){
    count++;
    //db = realloc(db, count * sizeof(struct my_struct *));
    array_size = 0;
    
    printf("name: ");
    scanf("%s", name);
    
    printf("id: ");
    scanf("%s", s_index);
    index = atoi(s_index);
    
    while(1){
      printf("string_array[%d]: ", array_size);
      scanf("%s", temp_string);
      
      if(strcmp(temp_string, "done")) {
        array_size++;
	//  string_array = realloc(string_array, array_size * sizeof(char *));
        string_array[array_size - 1] = strdup(temp_string);
      } else {
	  break;
      }
    }
    
    db[count] = make_struct(name, index, string_array, array_size);
    printf("\n\n");
  }

  
  //-----------------------------------------------------------------------//

  
  printf("\n\n");

  for (i = 1; i < (count + 1); i++) {
    printf("name: %s\n", db[i]->name);
    printf("id: %d\n", db[i]->index);
    
    for (j = 0; j < db[i]->array_size; j++) {
      printf("array[%d]: %s \n", j + 1, db[i]->string_array[j]);
    }


    free(db[i]->string_array);
    free(db[i]->name);
    //    free(db[i]);
    //    free(db);        
    printf("\n\n");
  }
      
  return 0;
}
