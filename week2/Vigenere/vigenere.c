/*
This is a console program that encrypts messages using Vigenère’s cipher.

This code was thought through and written by Alisher Yuldashev
*/

#include <cs50.h> //include Harvard's CS50 own library
#include <ctype.h> //add ctype header file to access the touppper, isspace, isalpha functions
#include <stdio.h>
#include <string.h> //include string library to access strlen() function;
#include <stdlib.h> //include stdlib library to access atoi{} function;

int main(int argc, string argv[])
{
    if (argc != 2)  //throw error if the user provides more than one argument at the prompt;
    {
        printf("Usage: ./vigenere <keyword>\n");
        return 1;
    }
    
    string s = argv[1]; //remember argument keyword
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isalpha(s[i])) //throw error if not alphabetic char
        {
            printf("Usage: <keyword> should contain only letters.\n");
            return 1;
        }
    }    
        
    int n = strlen(s); //get length of the keyword
    string text = GetString(); //assign user input message to a string
            
    for (int j = 0, index = 0, l = strlen(text); j < l; j++) //iterate through each char of the message
    {
       
        if (isalpha(text[j]) && islower(text[j])) //add ciphertext for lower case chars
        {
            printf("%c", (text[j] - 97 + tolower(s[index % n]) - 97) % 26 + 97);
            index++;
        }
        else if (isalpha(text[j]) && isupper(text[j]))  //add ciphertext for upper case chars
        {
            printf("%c", (text[j] - 65 + tolower(s[index % n]) - 97) % 26 + 65);
            index++;
        }
        else
        {
            printf("%c", text[j]);
        }
    }
    printf("\n");
    return 0;
}
