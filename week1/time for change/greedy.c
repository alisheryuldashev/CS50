/*
This is a console program that program that first asks the user how much change is owed 
and then spits out the minimum number of coins with which said change can be made.

This code was thought through and written by Alisher Yuldashev
*/

//add header files of the C standard library and the Harvard's own library (cs50)
#include <stdio.h>
#include <cs50.h>
#include <math.h> //include math library to get the round() function;

int main (void)
{
    float change; //change in dollars
    
    //initialize counters for each coin type
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    
    //ask for a change owed
    do
    {
        printf("How much change do I owe you?\n");
        change = get_float();
    }
    while (change < 0); //exclude negative numbers
    
    //convert change in dollars to cents and round the floating number
    change = roundf(change * 100);
    
    //typecast rounded double to the int
    change = (int)change;
    
    //run loops starting from the largest coin possible (quarter)
    while (change / 25 >= 1)
    {
        quarters++; //increase coin count
        change = (change - 25); //decrease amount by a quarter
    }
    
    while (change / 10 >= 1)
    {
        dimes++;
        change = (change - 10);
    }
    
    while (change / 5 >= 1)
    {
        nickels++;
        change = (change - 5);
    }
    
    while (change / 1 >= 1)
    {
        pennies++;
        change = (change - 1);
    }
    //print the sum of all coins given
    printf("%d\n", quarters+dimes+nickels+pennies);
    
}
