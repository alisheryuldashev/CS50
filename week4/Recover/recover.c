/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE; //declare unsigned char

int main(void)
{
    //define file pointers to source and output files
    FILE* inptr = fopen("card.raw", "r");
    
    //this file pointer is initialized to NULL and does not point to any file at the moment
    FILE* outptr = NULL;
    
    //return an error if you can't open a file
    if (inptr == NULL)
    {
        fclose (outptr);
        printf("Could not open a file %s.\n", "card.raw");
        return 1;
    }
   
    //temp storage to evaluate every single block of 512 bytes each for matching jpeg signatures
    BYTE buffer[512];
   
    //recovered jpeg file names will contain 7 characters each (ex.000.jpg) and an end of string marker (\0)
    char filename[8];
   
    //counter for jpeg file names sequence (ex.000, 001, 002)
    int filenumber = 0;
    
    //cycle until you reach end of file
    while(fread(buffer, sizeof(buffer), 1, inptr) == 1)
    {
        //if no match found and no jpg opened, its the beginning of the source file so skip it
        if (buffer[0] != 0xff && buffer[1] != 0xd8 && buffer[2] != 0xff && (buffer[3] < 0xe0) && outptr == NULL)
        {
            //move on
        }
        // if a match found and no jpg opened, it's the beginning of jpg stream so create your very first jpg file 000.jpg
        else if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef) && outptr == NULL)
        {
            sprintf(filename, "%03d.jpg", filenumber);
            outptr = fopen(filename, "w");
            fwrite(buffer, sizeof(buffer), 1, outptr);
            filenumber++;
        }
        // if a match found and previous jpg opened, close previous jpg (000.jpg) and create a new jpg file (001.jpg)
        else if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef) && outptr != NULL)
        {
            fclose(outptr);
            sprintf(filename, "%03d.jpg", filenumber);
            outptr = fopen(filename, "w");
            fwrite(buffer, sizeof(buffer), 1, outptr);
            filenumber++;
        }
        //if output jpg file is already opened then keep writing into it
        else if (outptr != NULL)
            fwrite(buffer, sizeof(buffer), 1, outptr);
        
    }
    
    //close source and output files
    fclose(outptr);
    fclose(inptr);
}

