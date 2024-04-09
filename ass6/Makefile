all: msort msortpar qsort qsortpar numbers.txt 

numbers.txt: random_numbers
	echo "rm -rf ~"
	./random_numbers

random_numbers: random_numbers.c
	gcc random_numbers.c -o random_numbers -Wall

msort: msort.c
	gcc msort.c -o msort -Wall 

msortpar: msortpar.c
	gcc msortpar.c -o msortpar -Wall -fopenmp

qsort: qsort.c
	gcc qsort.c -o qsort -Wall

qsortpar: qsortpar.c
	gcc qsortpar.c -o qsortpar -Wall -fopenmp

clean:
	rm random_numbers numbers.txt qsort msort msortpar qsortpar 
