#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH   16      /* max credit card length */

int
main(void)
{
    // ask user for credit card number
    long long CCNumber = get_long_long("Enter the credit card number: ");
    
    
    // put credit card number in string and store its length
    char s[MAXLENGTH];
    sprintf(s, "%lld", CCNumber);
    int len = strlen(s);
    
    
    // when not a valid length, return error
    if (len < 13 || len > 16 || len == 14)
    {
        printf("INVALID\n");
        return 1;
    }
    
    
    // enter number into array - using s[i]-'0' for ASCII conversion
    int number[len];
    for (int i = 0; i < len; i++)
    {
        number[i] = s[i] - '0';
    }    
    
    // multiply every other digit starting with 2nd-to-last by 2, add digits together
    // add not multiplied numbers to sum
    int sum = 0, j = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (j % 2 == 0)
        {
            sum += number[i] * 2 % 10;
            if (number[i] * 2 >= 10)
            {
                sum += 1;   
            } 
        } 
        else
        {
            sum += number[i];
        }
              
        j++;  
    }

    
    // check modulo and starting numbers, print card type   
    if (number[0] == 3 && (number[1] == 4 || number[1] == 7) && sum % 10 == 0 && (len == MAXLENGTH))
    {
        printf("AMEX\n");
    }
    else if (number[0] == 5 && number[1] > 0 && number[1] < 6 && sum % 10 == 0 && (len == MAXLENGTH))
    {
        printf("MASTERCARD\n");
    }
    else if (number[0] == 4 && sum % 10 == 0 && (len == MAXLENGTH))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    
    return 0;
}
