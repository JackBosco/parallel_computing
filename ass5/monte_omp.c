/* 
Jack Bosco
Do the monte carlo estimation sequentially
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#define N_SEQ 1000000000
int n_seq;
double* randoms_x;
double* randoms_y;

double find_pi(){
	srand(time(NULL)); // seed the random numbers
    // Do the sequence for monte carlo
	// 1. Randomly sample many points, (x, y) pairs, with each coordinate uniformly drawn between [−1, 1].
	long int count = 0;
	# pragma omp parallel for reduction(+:count)
	for (int i = 0; i<n_seq; i++){
		double random_x = rand() / (RAND_MAX/2.0) - 1.0; // I stole this :)
		double random_y = rand() / (RAND_MAX/2.0) - 1.0; // https://stackoverflow.com/questions/13408990/how-to-generate-random-float-number-in-c

		// 2. Count the number of points which lie within the circle
		double dist = (random_x*random_x) + (random_y*random_y);
		if (dist <= 1.0) {
			count++;
		}
	}
	// 3. Count the total number of points which lie within the square (all of them)
	// n_seq

	// 4. Divide the two, this should be proportional to the ratio of the areas, which is π
	double ratio = (double)count / (double)n_seq;

	// 5. Multiply by 4 to obtain π.
    return ratio * 4;
}



int main(int argc, char** argv){
    struct timespec start, end; //structs used for timing purposes, it has two memebers, a tv_sec which is the current second, and the tv_nsec which is the current nanosecond.
    double time_diff;

	//parse command line args
	if (argc > 1) {
		n_seq = atoi(argv[1]);
	} else {
		n_seq = N_SEQ;
	}
	randoms_x = malloc(n_seq * sizeof(double));
	randoms_y = malloc(n_seq * sizeof(double));
    clock_gettime(CLOCK_MONOTONIC, &start); //Start the clock!
    double pi = find_pi();
    clock_gettime(CLOCK_MONOTONIC, &end);   //Stops the clock!

    time_diff = (end.tv_sec - start.tv_sec); //Difference in seconds
    time_diff += (end.tv_nsec - start.tv_nsec) / 1e9; //Difference in nanoseconds

    printf("The time taken is %f \n", time_diff);
    printf("The number of terms is %d\n", n_seq);
    printf("Pi is %.20lf\n", pi);
}
