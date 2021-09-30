#include "mergesort.h"
#include <cstdlib>

void mergeRanges(int* value, int start_index, int midSize, int end_index){
int rangeSize, firstIndex, secondIndex, copyIndex,i;
rangeSize = end_index - start_index;
int* destination = (int*)calloc(rangeSize, sizeof(int));
firstIndex = start_index;
secondIndex = midSize;
copyIndex = 0;
while(firstIndex < midSize && secondIndex < end_index){
if(value[firstIndex] < value[secondIndex]){
destination[copyIndex] = value[firstIndex];
firstIndex++;
}
else{
destination[copyIndex] = value[secondIndex];
secondIndex++;
}
copyIndex++;
}
while(firstIndex<midSize){
destination[copyIndex] = value[firstIndex];
copyIndex++;
firstIndex++;
}
while(secondIndex<end_index){
destination[copyIndex] = value[secondIndex];
copyIndex++;
secondIndex++;
}
for(i=0; i<rangeSize;i++){
value[i + start_index] = destination[i];
}
if(rangeSize != 0){
        free(destination);
    }
}

void mergesortRange(int* value, int start_index, int end_index){
 int rangeSize, midSize;
 rangeSize = end_index - start_index;
 if(rangeSize >= 2){
         midSize = (start_index + end_index)/2;
         mergesortRange(value,start_index,midSize);
         mergesortRange(value,midSize,end_index);
         mergeRanges(value,start_index,midSize,end_index);
}}


void mergesort(int size, int* values) {
 mergesortRange(values,0,size);
}
