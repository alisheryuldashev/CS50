/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    //factor of n
    int n = atoi(argv[1]);
    if (n < 1 || n > 100)
    {
        printf("n should be a number between 1 and 100\n");
        return 2;
    }
    //remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    //declare and assign file and info headers for the resized (outfile) file
    BITMAPFILEHEADER bf_outfile;
    bf_outfile = bf;
    BITMAPINFOHEADER bi_outfile;
    bi_outfile = bi;
    
    //resize outfile's width and height of image by the factor of n
    bi_outfile.biWidth = bi.biWidth * n;
    bi_outfile.biHeight = bi.biHeight * n;
    
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //add padding to outfile's scanlines if required
    int padding_outfile =  (4 - (bi_outfile.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //calculate the new total size of image in the outfile (including pixels and padding)
    bi_outfile.biSizeImage = ((sizeof(RGBTRIPLE) * bi_outfile.biWidth) + padding_outfile) * abs(bi_outfile.biHeight);
    //calculate the new total size of file which includes image size and headers
    bf_outfile.bfSize = bi_outfile.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_outfile, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_outfile, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //repeat line n times
        for (int vert = 0; vert < n; vert++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
                // write RGB triple to outfile
                for (int horz = 0; horz < n; horz++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        
            // then add padding to outfile
            for (int k = 0; k < padding_outfile; k++)
                fputc(0x00, outptr);
        
            //go back to the beginning of the current line in infile
            fseek(inptr, -(long int)(bi.biWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
        }
    
        //then position pointer to the end the same line
        fseek(inptr, bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
        // skip over padding in infile, if any
        fseek(inptr, padding, SEEK_CUR);
    }
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
