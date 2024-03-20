#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

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
    //I don't know how to sort so just return 0
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

    my_sort(input, n);
    
    //check if it's sorted.
    int sorted = is_sorted(input, n);
    printf("Are the numbers sorted? %s \n", sorted ? "true" : "false");
   
    printf("Time elapsed: %lf \n", 0.0);
    free(input);
}