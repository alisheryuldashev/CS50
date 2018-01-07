/*
This is a console program that encrypts messages using Caesar's cipher.

This code was thought through and written by Alisher Yuldashev
*/

//add header files of the C standard library and the Harvard's own library (cs50)
#include <stdio.h>
#include <cs50.h> //include Harvard's CS50 own library
#include <math.h> //include math library to get the round() function;
#include <string.h> //include string library to access strlen() function;
#include <stdlib.h> //include stdlib library to access atoi{} function;
#include <ctype.h> //add ctype header file to access the touppper, isspace, isalpha functions

int main(int argc, string argv[]) //the program needs to accept a command-line argument
{
    //check if the user provides more than one argument at the prompt;
    if (argc != 2) {
        printf("usage: ./caesar key\n");
        return 1;
    }
    
    //if a user types an integer at the prompt, we need to convert a string to an int
    int k = atoi(argv[1]); 
    //ask a user for some plaintext
    printf("Write down the message that you would like to encrypt:");
    string plain = get_string();//assign user  input to string
    int i, n; //declare variables for counter i and string n
    for (i = 0, n = strlen(plain); i < n; i++) {
        while(isalpha(plain[i])) { //iterate through each character in string
            if (isupper(plain[i])) //caesar code upper case characters 
                printf("%c",(((plain[i] - 65) + k) % 26) + 65);
                
            if  (islower(plain[i])) //caesar code lower case characters 
                printf("%c",(((plain[i] - 97) + k) % 26) + 97);
                
            else
                printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}



