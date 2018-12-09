// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }
    //take conversion factor and convert it into float
    float f = atof(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 1;
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
        return 1;
    }


    //padding on input file
    float padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    int fseekback = padding + (bi.biWidth * sizeof(RGBTRIPLE));

    //increasing the width and height of the bitmap file to desired dimensions
    bi.biWidth = f * bi.biWidth;
    bi.biHeight = f * bi.biHeight;


    // determine padding for output file
    float padding2 = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //calculating new size of BMP file
    float sizeimage = (abs(bi.biHeight) * ((bi.biWidth * sizeof(RGBTRIPLE)) + padding2));
    float size = sizeimage + 54;

    //assigning the size to bfSize variable
    bf.bfSize = size;
    bi.biSizeImage = sizeimage;



    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // temporary storage
    RGBTRIPLE triple;




    // iterate over infile's scanlines
    if (f >= 1)
    {
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < (bi.biWidth / f); j++)
            {
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int m = 0 ; m < f ; m++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding2; k++)
            {
                fputc(0x00, outptr);
            }

            if (!(i % (int)f == f - 1))
            {
                fseek(inptr, -fseekback, SEEK_CUR);

            }
        }
    }
    else
    {
        float inversef = 1 / f;
        float skip = (inversef - 1) * ((bi.biWidth / f) * sizeof(RGBTRIPLE) + padding);

        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                fseek(inptr, (inversef - 1)*sizeof(RGBTRIPLE), SEEK_CUR);

                // write RGB triple to outfile

                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding2; k++)
            {
                fputc(0x00, outptr);
            }
            fseek(inptr, skip, SEEK_CUR);



        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
