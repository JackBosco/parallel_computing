# CSCI 320: Homework 1

### C Programming Review
### Due: Jan 26th, 2024
### General Information

Your code should be submitted electronically to Canvas as in a ZIP. 

Though you may want to use version control, makefiles, etc for coding, I do not require it.

Please submit a ZIP file of your code:
* Include source files and the provided input files (if any)
* Include your name as a comment at the top of each file
* Include a README file which consists of your name and student ID, on two separate lines. (Include any additional information - see collaboration policy).

### Coding Guidelines:
* Your code must compile with gcc with little/no compiler warnings.
* Your code should utilize and free memory appropriately - avoid memory leaks!
* Since C can be system dependent, I encourage you to write your code on the advanced lab machines. If your code does not compile for whatever reason, I will notify you via email and give you some time to fix potential issues
* Note that this only applies to compile time errors. If your code compiles, but does not run correctly - crashing silently or causing a segmentation fault. You will lose points.
Collaboration
* I expect that you might discuss the programming problems with others in the course. This is allowed provided you follow the policies correctly.
* I expect that you should write your own code - do not copy and paste code from classmates or other sources.
* You may collaborate, look over code, hunt for bugs, etc, but you should be the one typing your own code.
* If you do collaborate with another student in some way, please write a quick note about it in the README file. (You will not be penalized for this).


________________


### Homework 1: C Programming Review
In this assignment, you will write several variants of one program in C.


The goal is to explore some of the key aspects of C.


In the provided homework1.zip there are some files to get you started. There are three input files: declaration.txt, declaration2.txt, and hello.txt. 
* The random_ints.c contains some code you will use for Part 0
* The word_count.c and strtok_demo.c contains some sample code for the later parts

---

### Part 0 - Debugging (5 pts)
Included in the random_ints.c is a program which is intended to generate 20 random integers and write them to a file. The integers generated should be between -20 and +20. The program is supposed to first write the number of integers (20) on the first line of the file, followed by a blank line, then followed by the random integers on separate lines.


You can compile the code (through a terminal) by using: gcc random_ints.c -o <prog>
Then you can run the executable created by using: ./<prog>


However, there are several reasons why it does not produce the correct results after being run.


Please fix this program so that it will indeed generate random integers in a correct manner. You may change the signatures for functions if you wish, though you should still keep the primary goal of each function the same.


Include a fixes.txt in your submission, in which you briefly describe the various issues and changes you made.

---

### Part 1 - Getting Started

Examine word_count.c to see what it does (It does not count any words…)


Here is a quick overview of the program, as a review:
* int main(int argc, char** argv) declares the main function, which takes in command line arguments. argc is the number of arguments, argv is an array of strings (a char** in C) which stores command line arguments
* buffer is declared to be an array in memory, used to hold a temporary string later the size of the buffer is 5 - defined as a preprocessor directive at the top of the file
* FILE file* is a pointer to the stream created by opening the file "declaration.txt"
* fgets(buffer, sizeof(buffer), file) reads and stores a line of text into the temporary string, up to the size of the buffer
* while loop This part just displays all the command line arguments passed in to the program
* printf("Text: %s\n", buffer) This displays the single line of text stored in the buffer
* return (intptr_t) &main; This line returns a nonzero integer
You may want to review fgets to better understand what this program is displaying.


Move on to the next part when you feel like you can comfortably understand what this program is doing. 
* Try changing the size of the buffer and see what happens?
* Try running the compiled program with: ./<prog> foo bar

---

### Part 2 - Command Line Arguments (5 pts)
Your first task is to give the program the ability to process other files aside from "declaration.txt"


This can be achieved from some basic command line argument parsing. Notice that argv is a char** that refers to the command line arguments.


Modify the program such that the first additional command line argument changes the file which the program reads from.


./<prog> hello.txt should cause the program to read from the "hello.txt" text file.


You don't have to do anything fancy here (don't use getopt or argp or any complex argument parsing tools, we don't need it here).

---

### Part 3 - Word Counting (10 pts)
Of course, the program, despite being named word_count.c, doesn't actually count any words.


The goal of the program is the following:
* It should take two command line arguments, therefore, the usage is the following:
   * ./<prog> <file_name> <word>
   * <file_name> is the file your program reads
   * <word> is the word your program is looking for
* The program should then read the correct file, and display the number of times that the special <word> occurs in the file.
   * The input <word> will be in lower case and has no punctuation
   * The count should ignore punctuation and capitalization
   * E.g. "Laws", "Laws!", ".laws" are all equivalent to the word "laws" and should be counted as such


For example, suppose you compile your program to "wc". Then the following is a sample run of the program:
        ./wc declaration.txt laws
        laws count: 9


Here are some sample answers you may want to compare your program against.


Word
	Count
	laws
	9
	destruction
	1
	justice
	3
	he
	19
	for
	29
	

You should read the hints before you begin, unless you have a good idea of how to accomplish this task already.
Hints and Suggestions
* You might want to see the other provided source file strtok_demo.c
   1. This file has some demonstration of the strtok function which you should use to accomplish this task.
   2. You should be careful with string literals see
https://en.cppreference.com/w/c/language/string_literal
   * fgets may behave poorly depending on the choice of the buffer size. You have several options to deal with this:
   1. Figure out what happens if the buffer size is insufficient, and the read ends at the middle of a word, and deal with that
   2. Or, use a different function such as fread after using some fseek to figure out how much you want to read
   3. (Avoid using gets as it often has some undesirable behaviors)
   * C is a language with a long history, be careful if you find documentation, especially on the internet. Think carefully about the code and make sure you know what it is doing.