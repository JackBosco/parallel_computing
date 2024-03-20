all: pomp momp bsort

momp: monte_omp.c
	gcc monte_omp.c -o momp -Wall -fopenmp -lm

pomp: pi_omp.c
	gcc pi_omp.c -o pomp -Wall -lm -fopenmp

bsort: bsort.c
	gcc bsort.c -o bsort -Wall

clean:
	rm momp pomp bsort
