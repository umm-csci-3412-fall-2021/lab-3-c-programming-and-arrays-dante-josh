#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <cstdlib>

int get_array_size(int* array,int arrays_size){
 int value = 0;
 int i;
 for(i = 0; i<arrays_size;i++){
        value = value + array[i];
        }
 return value;
}
int find_elem(int elem, int* array, int size){
 for( int i=0 ; i < size; i++){
        if(array[i] == elem){
                return true;
        }
    }
 return false;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
  int i, old_value, new_value, array_size, j, counter, unique;
  counter = 0;
  unique = 0;
  array_size = get_array_size(sizes,num_arrays);
  int *destination = (int *)calloc(array_size+1, sizeof(int));
  for(i = 0;i<num_arrays;i++){
	  for(j = 0; j < sizes[i];j++){ 
		if(unique == 0){
		        destination[counter] = values[i][j];
                        unique++;
                        counter++;

		}
		else if(find_elem(values[i][j],destination,array_size+1) == false){ 
	  		destination[counter] = values[i][j];
			unique++;
			counter++;
		}
	  }
  }
  mergesort(unique,destination);
  destination[counter] = unique;
  return destination;
}
