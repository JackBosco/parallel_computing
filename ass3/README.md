Jack Bosco

*I am a student*



# CSCI320: Homework 3

##### Due: Monday, Feb 12th

--

### Part 1 Two Pi. (24 pts)

##### In this assignment, you will write programs to estimate the value of the extremely popular number, π, in two different ways.
#### 1 Infinite Series. (12 pts)
It i s a well known fact that one can compute the value of π using the following formula:

4(1 - 1/3 + 1/5 - 1/7 + 1/9 ... + (-1)^n * 1/(2n - 1))

This is simply four multiplied by the sum of an infinite series. Of course, we cannot actually compute
all the terms of an infinite series in finite time, but we can get close by computing many terms.
In this part, you will write two programs in pi seq.c and pi par.c respectively. The first will be a
sequential version of the program, the second will be a parallel version. It is highly suggested that you
write the sequential version first!
There is some code provided in pi example.c, this code is meant as a demonstration of how to
obtain the wall clock time of your code.
1. Both programs should output 3 lines of text:
•The estimation of π
•The number of terms used
•The (wall clock) time of the computation
I encourage you to structure your programs like pi example.c to make sure the correct part is
timed.
2. In pi seq.c you should write a sequential program which calculates π using the equation above.
•Your program should accept 1 optional command-line argument.
•The optional argument is the number of terms to include in the infinite series. The default
number should be 1000000.
3. In pi par.c you should write a parallel program which calculates π using the equation above.
•Your program should accept 2 optional command-line arguments.
•The first optional argument is the number of terms to include in the infinite series. The
default number should be 1000000.
•The second optional argument is the number of threads to use in the computation. The
default value should be 10.
4. Advice and Remarks:
•Write the sequential program first!
•In the parallel program, think about how to distribute the terms of the sum.
•To avoid warnings, use uintptr t appropriately. This does require <stdint.h>
•Test on various different sizes of input and threads.
2

