#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string convertToCipher(string plainText, string key, int keySize);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //assign key for cipher to a variable named key
        string key = argv[1];

        //store size of key to be used in the for loop ahead
        int size = strlen(key);

        //converting key to lower case
        for (int i = 0; i < size; i++)
        {
            //rejecting anything other than alphabets in key and converting key to lowercase
            if (!((key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= 'a' && key[i] <= 'z')))
            {
                printf("Usage: ./vigenere k");
                return 1;
            }
            key[i] = tolower(key[i]);
        }

        //get plainText
        string plainText = get_string("plaintext: ");

        //convert the text to cipher by use of function
        string cipherText = convertToCipher(plainText, key, size);

        printf("ciphertext: %s\n", cipherText);
        return 0;
    }

    else
    {
        //rejecting if more than  or less than 2 arguments are passed
        printf("Usage: ./vigenere k");
        return 1;
    }
}

string convertToCipher(string plainText, string key, int keySize)
{
    //keyNumber keeps track of j in algorithm
    int size = strlen(plainText), keyNumber = 0;

    for (int i = 0; i < size; i++)
    {
        //altering caps part of the plainText
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            plainText[i] = plainText[i] + key[keyNumber] - 'a';
            if (plainText[i] > 'Z')
            {
                plainText[i] -= 26;
            }

            keyNumber++;
            //reset value of keyNumber after it reaches end
            keyNumber = keyNumber % keySize;
        }

        else if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            //since ascii ends at 127 plaintext takes garbage values if character exceeds 127... so taking care of it in int variable
            int value = plainText[i] + key[keyNumber] - 'a';
            if (value > 122)
            {
                value -= 26;
            }
            plainText[i] = value;

            keyNumber++;
            keyNumber = keyNumber % keySize;
        }
    }

    return plainText;
}