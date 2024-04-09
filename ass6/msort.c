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
Helper for msort
*/
int my_msort_helper(int64_t* input, int64_t* temp, uint64_t size){
    //I don't know how to sort so just return 0
    return 0;
}

/*
Sorts the input array and puts output back into the input array
*/
int my_msort(int64_t* input, uint64_t size){
    int64_t* temp = malloc(size * sizeof(int64_t)); //Only create 1 temporary array
    my_msort_helper(input, temp, size); //Calls helper

    free(temp);
    return 0;
}

/*
Suggested function to write, to check whether the array is sorted
Returns 0 if not sorted, returns 1 if sorted
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

    my_msort(input, n);
    
    //check if it's sorted.
    int sorted = is_sorted(input, n);
    printf("Are the numbers sorted? %s \n", sorted ? "true" : "false");
   
    printf("Time elapsed: %lf \n", 0.0);
    free(input);
}