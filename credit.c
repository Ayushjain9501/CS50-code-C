#include <stdio.h>
#include <cs50.h>

int numberOfDigits(long long int credit);
int checksum(long long int credit, int count);

int main(void)
{
    long long int credit;

    //getting desired value!
    do
    {
        credit = get_long_long("Number : ");
    }
    while (credit < 0);

    //counting the number of digits in credit card number
    int count = numberOfDigits(credit);

    //flag parameter
    int valid = 0;

    if (count == 13 || count == 15 || count == 16)
    {
        //checking if credit card number satisfies the algorithm
        valid = checksum(credit, count);

        if (valid == 1)
        {
            //finding out the leading two digits of credit card number
            for (int i = 0; i < count - 2; i++)
            {
                credit /= 10;
            }

            if (credit == 34 || credit == 37)
            {
                printf("AMEX\n");
            }

            else if (credit == 51 || credit == 52 || credit == 53 || credit == 54 || credit == 55)
            {
                printf("MASTERCARD\n");
            }

            else
            {
                //reducing variable credit to one digit for VISA card verification
                credit /= 10;

                if (credit == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    //if number does not satisy pattern of any company set the flag parameter to 0
                    valid = 0;
                }
            }
        }
    }
    else
    {
        //prints invalid if the total number of digits doesn't match 13,15,16
        printf("INVALID\n");
    }

    //prints invalid if valid is 0
    if (valid == 0)
    {
        printf("INVALID\n");
    }
    return 0;
}

int numberOfDigits(long long int credit)
{
    int count = 0 ;

    //counting the number of times the credit card number can be divided by 10, hence the number of digits in it!
    while (credit / 10 != 0)
    {
        credit = credit / 10 ;
        count++ ;

    }
    count++;

    return count ;
}

int checksum(long long int credit, int count)
{
    int sum = 0;

    for (int i = 0 ; i < count ; i++)
    {
        //setting the value of avariable to the last digit of credit card number
        int x = credit % 10 ;

        if (i % 2 == 0)
        {
            sum += x;
        }
        else
        {
            x = 2 * x;
            //If 2 * digit exceeds 9, we break it into two parts both of which are added to total sum!
            if (x > 9)
            {
                sum += x % 10;
                x = x / 10;
            }
            sum += x;
        }

        //altering the card number by dividing it by 10! so that the current last digit is removed!
        credit /= 10;
    }

    sum = sum % 10;

    //checking if the total sum is divisible by 10 or not!
    if (sum == 0)
    {
        //assign valid flag parameter to be true
        return 1;

    }
    else
    {
        //assign valid flag parameter to be false
        return 0;
    }
}