all: mseq ppar pseq mpar

mseq: monte_seq.c
	gcc monte_seq.c -o mseq -Wall -lm

pseq: pi_seq.c
	gcc pi_seq.c -o pseq -Wall -lm

ppar: pi_par.c
	gcc pi_par.c -o ppar -Wall -lm -pthread

mpar: monte_par.c
	gcc monte_par.c -o mpar -Wall -lm -pthread

clean:
	rm mseq pseq ppar mpar