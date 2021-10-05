#include "mergesort.h"
#include <cstdlib>

void mergeRanges(int *values, int start_index, int midPoint, int end_index){
	int rangeSize, firstIndex, secondIndex, copyIndex, i;
	rangeSize = end_index - start_index;
	int *destination = (int *)calloc(rangeSize, sizeof(int));
	firstIndex = start_index;
	secondIndex = midPoint;
	copyIndex = 0;
	while(firstIndex < midPoint && secondIndex < end_index) {
		if(values[firstIndex] < values[secondIndex]){
			destination[copyIndex] = values[firstIndex];
			firstIndex++;
		}
		else{
			destination[copyIndex] = values[secondIndex];
			secondIndex++;
		}
		copyIndex++;
	}
	while(firstIndex < midPoint){
		destination[copyIndex] = values[firstIndex];
		copyIndex++;
		firstIndex++;
	}
	while(secondIndex < end_index) {
		destination[copyIndex] = values[secondIndex];
		copyIndex++;
		secondIndex++;
	}
	for(i=0; i < rangeSize; i++){
		values[i + start_index] = destination[i];
	}
	if(rangeSize != 0) {
		free(destination);
	}
}

void mergesortRange(int *values, int start_index, int end_index) {
	int rangeSize, midPoint;
	rangeSize = end_index - start_index;
	if(rangeSize >= 2) {
		midPoint = (start_index + end_index)/2;
		mergesortRange(values, start_index, midPoint);
		mergesortRange(values, midPoint, end_index);
		mergeRanges(values, start_index, midPoint, end_index);
	}
}

void mergesort(int size, int *values){
	mergesortRange(values,0,size);
}
