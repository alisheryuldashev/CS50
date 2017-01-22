/*
This is a console program that reports a user’s water usage, converting 
minutes spent in the shower to bottles of drinking water.

This code was thought through and written by Alisher Yuldashev
*/

//add header files of the C standard library and the Harvard's own library
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt the user for the length of his or her shower in minutes (as a positive integer) 
    printf("How many minutes of shower would you need today: ");
    
    //remember the input from the user
    int m = GetInt();
    
    //calculate equivalent bottles (assume 1 min to equal 12 bottles of water) 
    int b = m * 12;
  
    //print the equivalent number of bottles of water (as an integer)
    printf("Your today's shower will use an equivalent of %d bottles of water!\n", b);    
}

