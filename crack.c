#define _XOPEN_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    // To exit if less or more than 2 arguements
    if (!(argc == 2))
    {
        printf("Invalid Input");
        return 1;
    }
    char salt[3];
    string hash = argv[1];
    // To get salt
    for (int i = 0; i < 2; i++)
    {
        salt[i] = hash[i];
    }
    //assign end to salt
    salt[2] = '\0';

    //checking for 1 letter passwords
    //creating a 2 letter long array , one space is used for terminator \0!
    char arr1[2];
    arr1[1] = '\0';
    arr1[0] = 'A';

    //myHash will store crypt output
    string myHash;

    for (int i = 0; i < 26; i++)
    {
        myHash = crypt(arr1, salt);
        //compare myHash and hash provided, if they match print it on the screen and return 0
        if (!strcmp(myHash, hash))
        {
            printf("%s\n", arr1);
            return 0;
        }

        // for this condition to be true the loop must have iterated 26 times and current value should be 'Z'.
        //now this resets value of i to 0 and arr1[0] to 'a' so that small alphabets can also be tested
        if (arr1[0] == 'Z')
        {
            i = -1;
            arr1[0] = arr1[0] + 'a' - 'Z' - 1;
        }
        arr1[0]++;

    }




    //for two letter long password
    char arr2[3];
    arr2[2] = '\0';
    arr2[0] = 'A';
    arr2[1] = 'A';


    //outer loop for first letter
    for (int i = 0; i < 26; i++)
    {
        //inner loop for second letter
        for (int j = 0; j < 26; j++)
        {
            myHash = crypt(arr2, salt);
            //comparing the hash
            if (!strcmp(myHash, hash))
            {
                printf("%s\n", arr2);
                return 0;
            }
            //special increment from 'Z' to 'a'
            if (arr2[1] == 'Z')
            {
                j = -1;
                arr2[1] = arr2[1] + 'a' - 'Z' - 1;
            }
            arr2[1]++;
        }

        //if first letter reaches 'Z'
        if (arr2[0] == 'Z')
        {
            i = -1;
            arr2[0] = arr2[0] + 'a' - 'Z' - 1;
        }

        //incrementing the outer letter and setting the inner letter to 'A' for algorithm to work again
        arr2[0]++;
        arr2[1] = 'A';
    }











    //three letter passwords
    char arr3[4];
    arr3[3] = '\0';
    arr3[0] = 'A';
    arr3[1] = 'A';
    arr3[2] = 'A';

    //for first letter
    for (int m = 0; m < 26; m++)
    {
        //for second letter
        for (int i = 0; i < 26; i++)
        {
            //for third letter
            for (int j = 0; j < 26; j++)
            {
                myHash = crypt(arr3, salt);
                //comparing the hash
                if (!strcmp(myHash, hash))
                {
                    printf("%s\n", arr3);
                    return 0;
                }
                //special increment
                if (arr3[2] == 'Z')
                {
                    j = -1;
                    arr3[2] = arr3[2] + 'a' - 'Z' - 1;
                }
                arr3[2]++;
            }
            if (arr3[1] == 'Z')
            {
                i = -1;
                arr3[1] = arr3[1] + 'a' - 'Z' - 1;
            }
            arr3[1]++;
            arr3[2] = 'A';
        }
        if (arr3[0] == 'Z')
        {
            m = -1;
            arr3[0] = arr3[0] + 'a' - 'Z' - 1;
        }
        arr3[0]++;
        arr3[1] = 'A';
        arr3[2] = 'A';
    }



    //four letter passwords
    char arr4[5];
    arr4[4] = '\0';
    arr4[0] = 'A';
    arr4[1] = 'A';
    arr4[2] = 'A';
    arr4[3] = 'A';

    //for first letter
    for (int u = 0; u < 26; u++)
    {
        //for second letter
        for (int m = 0; m < 26; m++)
        {
            //for third letter
            for (int i = 0 ; i < 26 ; i++)
            {
                //for fourth letter
                for (int j = 0; j < 26; j++)
                {
                    myHash = crypt(arr4, salt);
                    //comparing the hash
                    if (!strcmp(myHash, hash))
                    {
                        printf("%s\n", arr4);
                        return 0;
                    }
                    //special increment from 'Z' to 'a'
                    if (arr4[3] == 'Z')
                    {
                        j = -1;
                        arr4[3] = arr4[3] + 'a' - 'Z' - 1;
                    }
                    arr4[3]++;
                }
                if (arr4[2] == 'Z')
                {
                    i = -1;
                    arr4[2] = arr4[2] + 'a' - 'Z' - 1;
                }
                arr4[2]++;
                arr4[3] = 'A';
            }
            if (arr4[1] == 'Z')
            {
                m = -1;
                arr4[1] = arr4[1] + 'a' - 'Z' - 1;
            }
            arr4[1]++;
            arr4[2] = 'A';
            arr4[3] = 'A';
        }
        if (arr4[0] == 'Z')
        {
            u = -1;
            arr4[0] = arr4[0] + 'a' - 'Z' - 1;
        }
        arr4[0]++;
        arr4[1] = 'A';
        arr4[2] = 'A';
        arr4[3] = 'A';

    }





    //five letter passwords
    char arr5[6];
    arr5[5] = '\0';
    arr5[0] = 'A';
    arr5[1] = 'A';
    arr5[2] = 'A';
    arr5[3] = 'A';
    arr5[4] = 'A';

    //for first letter
    for (int v = 0; v < 26; v++)
    {
        //for second letter
        for (int u = 0; u < 26; u++)
        {
            //for third letter
            for (int m = 0; m < 26; m++)
            {
                //for fourth letter
                for (int i = 0; i < 26; i++)
                {
                    //for fifth letter
                    for (int j = 0; j < 26; j++)
                    {
                        myHash = crypt(arr5, salt);
                        //comparing the hash
                        if (!strcmp(myHash, hash))
                        {
                            printf("%s\n", arr5);
                            return 0;
                        }
                        //special increment from 'Z' to 'a'
                        if (arr5[4] == 'Z')
                        {
                            j = -1;
                            arr5[4] = arr5[4] + 'a' - 'Z' - 1;
                        }
                        arr5[4]++;
                    }
                    if (arr5[4] == 'Z')
                    {
                        i = -1;
                        arr5[3] = arr5[3] + 'a' - 'Z' - 1;
                    }
                    arr5[3]++;
                    arr5[4] = 'A';
                }
                if (arr5[2] == 'Z')
                {
                    m = -1;
                    arr5[2] = arr5[2] + 'a' - 'Z' - 1;
                }
                arr5[2]++;
                arr5[3] = 'A';
                arr5[4] = 'A';
            }
            if (arr5[1] == 'Z')
            {
                u = -1;
                arr5[1] = arr5[1] + 'a' - 'Z' - 1;
            }
            arr5[1]++;
            arr5[2] = 'A';
            arr5[3] = 'A';
            arr5[4] = 'A';

        }
        if (arr5[0] == 'Z')
        {
            v = -1;
            arr5[0] = arr5[0] + 'a' - 'Z' - 1;
        }
        arr5[0]++;
        arr5[1] = 'A';
        arr5[2] = 'A';
        arr5[3] = 'A';
        arr5[4] = 'A';
    }


}