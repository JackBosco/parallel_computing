/* 
Jack Bosco
This is the second part of assignment 3,
 using parallel coding for the pi estimation
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#define N_SEQ 1000000;
#define N_THREADS 10;

double * RESULTS;
int n_seq, n_threads;

void* find_pi(void* threadnum){
    //use the sequene to determine Pi from the amount of repitions passed in
	intptr_t tn = (intptr_t)threadnum;
	double Pi = 0;
	for (int i = tn*(n_seq/n_threads); i<(tn+1)*(n_seq/n_threads); i++){
		Pi += pow(-1.0, (double)i) / (2*i + 1);
	}
    RESULTS[tn] = Pi;
	return 0;
}

int main(int argc, char** argv){
    struct timespec start, end; //structs used for timing purposes, it has two memebers, a tv_sec which is the current second, and the tv_nsec which is the current nanosecond.
    double time_diff;
	// get command line args
	if (argc > 2) {
		n_seq = atoi(argv[1]);
		n_threads = atoi(argv[2]);
	} else {
		n_seq = N_SEQ;
		n_threads = N_THREADS;
	}
	
	pthread_t* HANDLERS = malloc(n_threads * sizeof(pthread_t)); // malloc thread handlers
	RESULTS = malloc(n_threads * sizeof(double)); // malloc result handlers
    
    clock_gettime(CLOCK_MONOTONIC, &start); //Start the clock!
	for (int i = 0; i<n_threads; i++){
		intptr_t e = i;
		pthread_create(&HANDLERS[i], NULL, find_pi, (void*)e);
	}
	//Waiting!
	for (int64_t i = 0; i<n_threads; i++){
		pthread_join(HANDLERS[i], NULL);
	}	
	double pi = 0.0;
	for (int64_t i = 0; i<n_threads; i++){
		pi += RESULTS[i];
	}
	pi *= 4;
	free(HANDLERS);
	free(RESULTS);
    clock_gettime(CLOCK_MONOTONIC, &end);   //Stops the clock!

    time_diff = (end.tv_sec - start.tv_sec); //Difference in seconds
    time_diff += (end.tv_nsec - start.tv_nsec) / 1e9; //Difference in nanoseconds

    printf("The time taken is %f \n", time_diff);
    printf("The number of terms in the sequence is %d \n", n_seq);
    printf("Pi is %.20lf\n", pi);
}
