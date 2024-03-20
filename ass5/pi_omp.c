/* 
Jack Bosco
This is the first part of assignment 3, using sequential coding for the pi estimation
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#define N_SEQ 10000000000;

double find_pi(int n){
    double Pi = 0;
    //use the sequence to determine Pi from the amount of repitions passed in
	# pragma omp parallel for reduction(+:Pi)
    for (int i = 0; i<n; i++){
		Pi += pow(-1.0, (double)i) / (2*i + 1);
	}
    return 4 * Pi; 
}

int main(int argc, char** argv){
    struct timespec start, end; //structs used for timing purposes, it has two memebers, a tv_sec which is the current second, and the tv_nsec which is the current nanosecond.
    double time_diff;
	long int n;
	// get command line args
	if (argc > 1) {
		n = atoi(argv[1]);
	} else {
		n = N_SEQ;
	}
    
    clock_gettime(CLOCK_MONOTONIC, &start); //Start the clock!
    double pi = find_pi(n);
    clock_gettime(CLOCK_MONOTONIC, &end);   //Stops the clock!

    time_diff = (end.tv_sec - start.tv_sec); //Difference in seconds
    time_diff += (end.tv_nsec - start.tv_nsec) / 1e9; //Difference in nanoseconds

    printf("The time taken is %f \n", time_diff);
    printf("The number of terms in the sequence is %ld \n", n);
    printf("Pi is %.20lf\n", pi);
}
