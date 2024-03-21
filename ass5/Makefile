all: pomp momp bsort oesort

momp: monte_omp.c
	gcc monte_omp.c -o momp -Wall -fopenmp -lm

pomp: pi_omp.c
	gcc pi_omp.c -o pomp -Wall -lm -fopenmp

bsort: bsort.c
	gcc bsort.c -o bsort -Wall

oesort: oesort.c
	gcc oesort.c -o oesort -Wall -fopenmp

clean:
	rm momp pomp bsort oesort