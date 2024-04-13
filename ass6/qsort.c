#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 2048

/*
This function returns a pointer to an array with all the numbers in the file as int64_t
Sets *size to be the number of numbers
*/
int64_t* Populate(char* fname, uint64_t* size){
    //Just allocate a bunch of memory to use up some memory for now...
    
    FILE* file = fopen(fname, "r");
	int64_t tok;
    char buffer[BUFFER_SIZE];

    fgets(buffer, sizeof(buffer), file);

    *size = strtol(buffer, NULL, 10);

    int64_t* nums=(int64_t*) malloc(*size * sizeof(int64_t));
    uint64_t i = 0;
	while(fgets(buffer, sizeof(buffer), file)){
        if ((char)buffer[0]!='\n'){
            tok=strtol(buffer, NULL, 10);
            if (tok>-1){
                nums[i]=tok;
                i++;
            }
        }
	}
    return nums;
}

void swap(int64_t* i, int64_t* j){
	int temp = *i;
	*i = *j;
	*j = temp;
}

/*
TODO: Partitions the array and returns the index of the pivot (after partition)
	Chooses a random partition
*/
uint64_t partition(int64_t* input, int64_t low, int64_t high, uint64_t size){
	// Choose a random pivot
	int64_t pivot_index = rand() % (high-low+1) + low;
	int64_t pivot = input[pivot_index];

    swap(&input[pivot_index], &input[high]);

    int64_t i = low - 1;

    for (int64_t j = low; j <= high - 1; j++) {
        if (input[j] < pivot) {
            i++;
            swap(&input[i], &input[j]);
        }
    }

    // Place the pivot element at its correct position
    swap(&input[i + 1], &input[high]);

    return (i + 1);
}

void recurse(int64_t* input, int64_t low, int64_t high, int64_t size){
	if (low >= high) return;
	int64_t pivot_index = partition(input, low, high, size);
	recurse(input, low, pivot_index-1, size);
	recurse(input, pivot_index+1, high, size);
	return;
}

/*
Sorts the input array and puts output back into the input array
*/
int my_qsort(int64_t* input, uint64_t size){
	recurse(input, 0, size-1, size);
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
    double time_diff;
	struct timespec start, end; //structs used for timing purposes, it has two memebers, a tv_sec which is the current second, and the tv_nsec which is the current nanosecond.

	//print size
	printf("Size of list: %llu\n", n);

	clock_gettime(CLOCK_MONOTONIC, &start); //Start the clock!
    my_qsort(input, n);
    clock_gettime(CLOCK_MONOTONIC, &end);   //Stops the clock!

	time_diff = (end.tv_sec - start.tv_sec); //Difference in seconds
    time_diff += (end.tv_nsec - start.tv_nsec) / 1e9; //Difference in nanoseconds

    //check if it's sorted.
    int sorted = is_sorted(input, n);
    printf("Are the numbers sorted? %s \n", sorted ? "true" : "false");
   
	//print the time
	printf("Time elapsed: %f\n", time_diff);
    free(input);
}