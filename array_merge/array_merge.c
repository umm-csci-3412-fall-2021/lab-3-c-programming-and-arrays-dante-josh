#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <cstdlib>

// function that calculates size of the arrays inside the array
int get_array_size(int* array,int arrays_size){
 int value = 0;
 int i;
 for(i = 0; i<arrays_size;i++){
        value = value + array[i];
        }
 return value;
}


// function that looks for the specified element and specified array and returns true if it is in there or false otherwise
int find_elem(int elem, int* array, int size){
 for( int i=0 ; i < size; i++){
        if(array[i] == elem){
                return true;
        }
    }
 return false;
}


int* array_merge(int num_arrays, int* sizes, int** values) {
  // creating variables to be used in the function
  int i, array_size, j, counter, unique, zeroes;
  // variables are set to zero
  counter = 0;
  unique = 0;
  zeroes = 0;
  // calls the get_array_size method on sizes and num_arrays
  array_size = get_array_size(sizes,num_arrays);
  // allocate memory for destination
  int *destination = (int *)calloc(array_size+1, sizeof(int));
  // for loop that iterates for the number of arrays given
  for(i = 0;i<num_arrays;i++){
	  // for loop that iterates through the size of the arrays inside the array 
	  for(j = 0; j < sizes[i];j++){ 
		// check if current value is zero  
		if(values[i][j] == 0) {
			zeroes++;
		}
		// check if current value is already inside destination array
		// if not, add it to destination, increment unique and counter
		else if(find_elem(values[i][j],destination,array_size+1) == false){ 
	  		destination[counter] = values[i][j];
			unique++;
			counter++;
		}
	  }
  }

  // check if zeroes is equal to zero
  // if it is not, then increment unique
  if(!(zeroes==0)){
	  unique++;
  }

  // allocate memory for a new array that is the size of unique
  int* secondArray = (int *)calloc(unique, sizeof(int));
  // copy values from destination into firstArray
  for(int i = 0; i < unique; i++){
	  secondArray[i] = destination[i];
  }

  free(destination);
  // sort the firstArray
  mergesort(unique,secondArray);
  // allocate memory for the final array that is the size of unique + 1
  // we are doing unique + 1 to accomodate for the value of unique in front
  int* theFinalArray = (int *)calloc(unique+1, sizeof(int));
  // set the first value in theFinalArray to the value of unique
  theFinalArray[0]=unique;
  // copy values from firstArray into theFinalArray
  for(int i = 1; i < unique+1; i++){
          theFinalArray[i] = secondArray[i-1];
  }
  free(secondArray);
  return theFinalArray;
}
