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

int join(int64_t* input, int64_t* temp, uint64_t size, uint64_t l, uint64_t m, uint64_t r){
	for (uint64_t i=l; i<=r; i++){
		temp[i] = input[i];
	}

	uint64_t hl=l;
	uint64_t hr=m+1;
	uint64_t cur=l;

	while (hl <= m && hr <= r) {
		if (temp[hl] <= temp[hr]){
			input[cur] = temp[hl];
			hl++;
		} else {
			input[cur] = temp[hr];
			hr++;
		}
		cur++;
	}

	// I always forget to do this last part :)
	// Copies the remaining left side of the temp array into the original
	int diff = m-hl;
	for (int i=0; i<=diff; i++){
		input[cur+i] = temp[hl+i];
	}
	return 0;
}

/*
Helper for msort
*/
int my_msort_helper(int64_t* input, int64_t* temp, uint64_t size, uint64_t l, uint64_t r){
    //I don't know how to sort so just return 0
	if (l<r){
		int64_t m = l + ((r-l) / 2);
		
		my_msort_helper(input, temp, size/2, l, m);
		my_msort_helper(input, temp, size/2, m+1, r);
		join(input, temp, size, l, m, r);
	}
	return 0;
}

/*
Sorts the input array and puts output back into the input array
*/
int my_msort(int64_t* input, uint64_t size){
    int64_t* temp = malloc(size * sizeof(int64_t)); //Only create 1 temporary array
		
	my_msort_helper(input, temp, size, 0, size-1); //Calls helper

    free(temp);
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

	//print size
	printf("Size of list: %llu\n", n);

	clock_gettime(CLOCK_MONOTONIC, &start); //Start the clock!
    my_msort(input, n);
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
