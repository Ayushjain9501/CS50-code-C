#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

//correctly taking value of height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

//loop to govern each row
    for (int i = 0; i < height; i++)
    {
        //loop to print spaces of block1
        for (int j = 0; j < height - i - 1 ; j++)
        {
            printf(" ");
        }

        //loop to print # of block1
        for (int k = 0 ; k < i + 1 ; k++)
        {
            printf("#");
        }

        //prints spaces separating two blocks
        printf("  ");

        //loop to print # of block 2
        for (int k = 0 ; k < i + 1 ; k++)
        {
            printf("#");
        }

        //ends single iteration of the main loop
        printf("\n");
    }
}