In this challenge I needed to implement a program that finds a number among numbers, per the below.

$ ./generate 1000 | ./find 42 
Didn't find needle in haystack. 

So the generate function used a pseudorandom-number generator (via a C function called drand48) to generate a whole bunch of random numbers. 
What I had to do was to create a searhing (binary) and sorting algorithms in the find function and pipe the generated numbers to my find function. 



