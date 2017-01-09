/*
This is a console program that recreates Nintendo's Super Mario game's half-pyramid using hashes for blocks.
The resulting half-pyramid will be right aligned as per problem specifications.

This code was thought through and written by Alisher Yuldashev
*/

//add header files of the C standard library and the Harvard's own library
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //declare a new value for the height of your pyramid
    int height;
    //prompt and validate user input;
    do
    {
        printf("What is the height of your pyramid?\n");
        height = get_int();
    }
    //height of the half-pyramid should be between 1 and 23 as per specs for this problem;
    while (height <= 0 || height >= 23);
   
    printf("Here is your Mario's half-pyramid:\n");
   
    //define building blocks of your pyramid - hashes;
    char hash = '#';
        
    //start building the half-pyramid from row 0; 
    for (int i = 0; i < height; i++)
    {
        //calculate the amount of spaces for each row which will be the height less row number;
        int row_space = height - i;
        
        //add width specifier '*' to get the proper number of spaces per each row and then print 1 hash;
        printf("%*c", row_space, hash);
        
        //add another loop to print 1 extra hash starting from row 0 plus 1;
        for (int j = 0; j < i + 1; j++)
        {
            printf("%c", hash);
        }
        //start new row (go back to the first loop);
        printf("\n");
    }
return 0;   
}
