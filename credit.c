#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User input for credit card number
    long ccnum = get_long("Number: ");

    // Check length is valid
    if ((ccnum < 5099999999999999 || ccnum > 5599999999999999) &&
        (ccnum < 4000000000000000 || ccnum > 4999999999999999) &&
        (ccnum < 4000000000000 || ccnum > 4999999999999) &&
        (ccnum < 339999999999999 || ccnum > 350000000000000) &&
        (ccnum < 369999999999999 || ccnum > 380000000000000))
    {
        printf("INVALID\n");
    }
    else
    {
        // Get every other digit starting with second to last and multiply by 2
        int d_15 = 2 * ((ccnum % 100) / 10);
        int d_13 = 2 * ((ccnum % 10000) / 1000);
        int d_11 = 2 * ((ccnum % 1000000) / 100000);
        int d_9 = 2 * ((ccnum % 100000000) / 10000000);
        int d_7 = 2 * ((ccnum % 10000000000) / 1000000000);
        int d_5 = 2 * ((ccnum % 1000000000000) / 100000000000);
        int d_3 = 2 * ((ccnum % 100000000000000) / 10000000000000);
        int d_1 = 2 * ((ccnum % 10000000000000000) / 1000000000000000);

        // Sum digits together
        int odds_sum = d_15 % 10 + d_15 / 10 + d_13 % 10 + d_13 / 10 + d_11 % 10 + d_11 / 10 +
                        d_9 % 10 + d_9 / 10 + d_7 % 10 + d_7 / 10 + d_5 % 10 + d_5 / 10 + d_3 % 10 + d_3 / 10 + d_1 % 10 + d_1 / 10;

        // Get every other digit starting with last digit
        int d_16 = (ccnum % 10) / 1;
        int d_14 = (ccnum % 1000) / 100;
        int d_12 = (ccnum % 100000) / 10000;
        int d_10 = (ccnum % 10000000) / 1000000;
        int d_8 = (ccnum % 1000000000) / 100000000;
        int d_6 = (ccnum % 100000000000) / 10000000000;
        int d_4 = (ccnum % 10000000000000) / 1000000000000;
        int d_2 = (ccnum % 1000000000000000) / 100000000000000;

        // Sum digits together
        int evens_sum = d_16 % 10 + d_16 / 10 + d_14 % 10 + d_14 / 10 + d_12 % 10 + d_12 / 10 +
                        d_10 % 10 + d_10 / 10 + d_8 % 10 + d_8 / 10 + d_6 % 10 + d_6 / 10 + d_4 % 10 + d_4 / 10 + d_2 % 10 + d_2 / 10;

        // Sum even and odd digits totals
        int total_sum = evens_sum + odds_sum;

        // Check is divisible by 10
        int result = total_sum % 10;

        // If valid determine credit card issuer
        if (result == 0)
        {
            if ((ccnum < 380000000000000 && ccnum > 369999999999999) || (ccnum > 339999999999999 && ccnum < 350000000000000))
            {
                printf("AMEX\n");
            }
            else if (ccnum < 5600000000000000 && ccnum > 5099999999999999)
            {
                printf("MASTERCARD\n");
            }
            else if ((ccnum > 3999999999999 && ccnum < 5000000000000) || (ccnum > 3999999999999999 && ccnum < 5000000000000000))
            {
                printf("VISA\n");
            }
        }
        else
        {
            printf("INVALID\n");
        };
    }
};
