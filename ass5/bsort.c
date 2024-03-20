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
    int i = 0;
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

int my_sort(int64_t* input, uint64_t size){
    // do a bubble sort
	// (a) Let i be 0, the index of the first element.
	// (b) Compare A[i] and A[i + 1], if the ordering is incorrect (that is, if A[i] > A[i + 1]) then swap
	// the position of the two elements. Let’s refer to this operation as a bubble operation.
	// (c) Now increment i by 1.
	// (d) Repeat steps (b) and (c) until we have completed one pass through the entire array, that is, until i == n.
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (input[j] > input[j + 1]) {
				int64_t temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}
    return 0;
}

/*
Suggested function to write, to check whether the array is sorted
Returns 0 if not sorted, returns 1 if sorted
*/
int is_sorted(int64_t* input, uint64_t size){
    for (int i=0;i<size-1;i++){
        if (input[i]>input[i+1]){
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

	clock_gettime(CLOCK_MONOTONIC, &start); //Start the clock!
    my_sort(input, n);
    clock_gettime(CLOCK_MONOTONIC, &end);   //Stops the clock!

	time_diff = (end.tv_sec - start.tv_sec); //Difference in seconds
    time_diff += (end.tv_nsec - start.tv_nsec) / 1e9; //Difference in nanoseconds

    //check if it's sorted.
    int sorted = is_sorted(input, n);
    printf("Are the numbers sorted? %s \n", sorted ? "true" : "false");
   
    printf("Time elapsed: %lf \n", 0.0);
    free(input);
}