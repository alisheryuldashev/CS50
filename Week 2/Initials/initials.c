#include <stdio.h>
#include <cs50.h>
#include <ctype.h> //add ctype header file to access the touppper, isspace, isalpha functions
#include <string.h>

int main (void)
{
    //printf("Type your full name\n");
    char * name = get_string();
    //loop counter
    int i;
    
    //iterate through each character of the string
    for (i = 0; i < strlen(name); i++)
    {
        //if a string starts with a letter, capitalize and print it
        if (name[i] == name[0] && isalpha(name[0]))
        {
            name[i] = toupper(name[i]);
            printf("%c", name[i]);
        }
        //if a string has a space and a letter right after it, capitalize and print that letter
        else if (isspace(name[i]) && isalpha(name[i + 1]))
        {
            name[i + 1] = toupper(name[i + 1]);
            printf("%c", name[i + 1]);
        }
        else
        {
            name[i]++; //skip the spaces
        }
    }
    printf("\n"); //print the initials
}
