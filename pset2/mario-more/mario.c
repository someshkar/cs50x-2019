#include <cs50.h>

#include <stdio.h>

int main(void)
{
    int height;

    // start loop until user gives correct inputs
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // check for height being in the correct limits
    if (height > 0 || height < 9)
    {
        int counter = 0;

        // loop over blocks of hashes
        for (int row = 0; row < height; row++)
        {
            // make sure you haven't reached the required height already
            if (counter != height)
            {

                // print appropriate spaces
                for (int spaces = (height - 1) - counter; spaces > 0; spaces--)
                {
                    printf(" ");
                }

                // print first half of hashes
                for (int hashes = 0; hashes <= counter; hashes++)
                {
                    printf("#");
                }

                // print gap between hash sections
                printf("  ");

                // print second half of hashes
                for (int hashes = 0; hashes <= counter; hashes++)
                {
                    printf("#");
                }

                // go to the next line to start again
                printf("\n");

                // increment the counter
                counter++;
            }
        }
    }
}
