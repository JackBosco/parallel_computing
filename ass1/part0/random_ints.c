

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <inttypes.h>
#define ARRAY_SIZE 20

int64_t* make_ints(){
    int64_t array[ARRAY_SIZE];
    int64_t* res = array;

    for (int i = 0; i < ARRAY_SIZE; i++){
        *(res+i) = 20 - rand()%(40);
    }
    return res;
}

int main(int argc, char** argv){
    srand(time(NULL)); 

    FILE* fptr = fopen("./numbers.txt", "w+");
    //Write the number of numbers as the first line
    fprintf(fptr, "%d\n\n", ARRAY_SIZE);

    //Compute an array of the numbers to write
    int64_t* array = make_ints();

    //Write all the other numbers, each on a seperate line
    for (int i = 0; i < ARRAY_SIZE; i++){
        fprintf(fptr, "%ld" "\n", *(array+i));
    }
    fclose(fptr);

    return 0;
}
