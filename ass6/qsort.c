#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

/*
This function returns a pointer to an array with all the numbers in the file as int64_t
Sets *size to be the number of numbers
*/
int64_t* Populate(char* fname, uint64_t* size){
    //Just allocate a bunch of memory to use up some memory for now...
    *size = 1234;
    return (int64_t*) malloc(1234 * 8);
}

/*
TODO: Partitions the array and returns the index of the pivot (after partition)
*/
uint64_t partition(int64_t* input, uint64_t size){
    uint64_t pivot_index = size-1;
    return pivot_index;
}

/*
Sorts the input array and puts output back into the input array
*/
int my_qsort(int64_t* input, uint64_t size){
    //I don't know how to sort so just return 0
    return 0;
}

/*
Returns 0 if not sorted, returns 1 if sorted
TODO: Modify if necessary
*/
int is_sorted(int64_t* input, uint64_t size){
	for (uint64_t i = 1; i < size; i++){
		if (input[i-1] > input[i]){
			return 0;
		}	
	}
    return 1;
}

int main(int argc, char** argv){
    uint64_t n; //The input size
    int64_t* input = Populate("./numbers.txt", &n); //gets the array

    my_qsort(input, n);
    
    //check if it's sorted.
    int sorted = is_sorted(input, n);
    printf("Are the numbers sorted? %s \n", sorted ? "true" : "false");
   
    printf("Time elapsed: %lf \n", 0.0);
    free(input);
}