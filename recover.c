#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //validating only one command-line argument is passed
    if (!(argc == 2))
    {
        fprintf(stderr, "Error! Invalid Argument Passed");
        //returns 1 as specified
        return 1;
    }
    //open the file
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");

    //check if fill is opened correctly
    if (inptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.", infile);
        //return 2 as specified
        return 2;
    }

    //count keeps track of filename
    //readonce is a flag variable if atleast one file has been opened!
    int count = -1, readOnce = 0;
    unsigned char readFile[512];
    FILE *outptr;

    do
    {

        //checks for condition
        if (readFile[0] == 0xff && readFile[1] == 0xd8 && readFile[2] == 0xff && (readFile[3] & 0xf0) == 0xe0)
        {
            //checking if atleast one file is made!
            if (readOnce == 0)
            {
                readOnce = 1;
                count++;
                char fileName[7];
                sprintf(fileName, "%03i.jpg", count);
                outptr = fopen(fileName, "w");
            }
            else
            {
                count++;
                char fileName[7];
                sprintf(fileName, "%03i.jpg", count);
                //close previous output file
                fclose(outptr);
                //open the output file
                outptr = fopen(fileName, "w");
            }
        }
        if (readOnce == 1)
        {
            //write only if atleast one file has been opened
            fwrite(&readFile, 1, 512, outptr);
        }

    }
    while (fread(readFile, 1, 512, inptr) == 512);

    //close all files!
    fclose(inptr);
    fclose(outptr);
    return 0;

}