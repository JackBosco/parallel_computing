/* 
Jack Bosco
Do the monte carlo estimation sequentially
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#define N_SEQ 1000000;
#define N_THREADS 10;

int n_seq;
int n_threads;
double* results;

void* find_pi(void* thread_num){
    // Do the sequence for monte carlo
	// 1. Randomly sample many points, (x, y) pairs, with each coordinate uniformly drawn between [−1, 1].
	int count = 0;
	intptr_t tn = (intptr_t)thread_num;
	srand(time(NULL) + (time_t) 42 + tn); // 42 is the answer to everthing
	for (int i = tn * (n_seq/n_threads); i<(tn+1) * (n_seq/n_threads); i++){
		double random_x = (double)rand() / (double)(RAND_MAX/2.0) - 1.0; // I stole this :)
		double random_y = (double)rand() / (double)(RAND_MAX/2.0) - 1.0; // https://stackoverflow.com/questions/13408990/how-to-generate-random-float-number-in-c

		// 2. Count the number of points which lie within the circle
		double dist = sqrt(pow(random_x, 2.0) + pow(random_y, 2.0));
		if (random_x >= 0.0 
			&& random_y >= 0.0 
			&& dist <= 1.0) {
				count++;
			}
	}
	// 3. Count the total number of points which lie within the square (all of them)
	// n_seq

	// 4. Divide the two, this should be proportional to the ratio of the areas, which is π
	double ratio = (double)count / (double)n_seq;

	// 5. Multiply by 4 to obtain π.
    results[tn] = ratio;
	return 0;
}

int main(int argc, char** argv){
    struct timespec start, end; //structs used for timing purposes, it has two memebers, a tv_sec which is the current second, and the tv_nsec which is the current nanosecond.
    double time_diff;

	//parse command line args
		// get command line args
	if (argc > 2) {
		n_seq = atoi(argv[1]);
		n_threads = atoi(argv[2]);
	} else {
		n_seq = N_SEQ;
		n_threads = N_THREADS;
	}
	
	pthread_t* HANDLERS = malloc(n_threads * sizeof(pthread_t)); // malloc thread handlers
	results = malloc(n_threads * sizeof(double)); // malloc result handlers
    
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
		pi += results[i];
	}
	pi *= 4 * 4;
	free(HANDLERS);
	free(results);
    clock_gettime(CLOCK_MONOTONIC, &end);   //Stops the clock!

    time_diff = (end.tv_sec - start.tv_sec); //Difference in seconds
    time_diff += (end.tv_nsec - start.tv_nsec) / 1e9; //Difference in nanoseconds

    printf("The time taken is %f \n", time_diff);
    printf("The number of terms is %d\n", n_seq);
    printf("Pi is %.20lf\n", pi);
}