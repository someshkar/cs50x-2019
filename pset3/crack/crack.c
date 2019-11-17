#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

/**
 * Here's how the algorithm progresses in 5 steps.
 * X is a letter placeholder, \0 is a null character.
 * 5 lines = 5 loops
 *
 *    1 2 3 4 5 6
 * 1) X\0\0\0\0\0
 * 2) X X\0\0\0\0
 * 3) X X X\0\0\0
 * 4) X X X X\0\0
 * 5) X X X X X\0
 */

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: crack <hash>\n");
        return 1;
    }

    // 26 lowercase + 26 uppercase + \0 counts as 1 character = 53
    const int letters_count = 53;

    // Initialize string with the alphabet
    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash = argv[1];

    char salt[3];
    memcpy(salt, hash, 2);
    salt[2] = '\0';

    char key_candidate[6] = "\0\0\0\0\0\0";

    // The fifth (outermost) loop maps to the last character in the key_candidate
    // This convention maps in the descendant loops as well
    for (int fifth = 0; fifth < letters_count; fifth++)
    {
        for (int fourth = 0; fourth < letters_count; fourth++)
        {
            for (int third = 0; third < letters_count; third++)
            {
                for (int second = 0; second < letters_count; second++)
                {
                    // The innermost loop advances more frequently compared
                    // to its ascendants, thus it maps to the first letter.
                    // We could initialize it to 0 but that would be an empty string
                    // (i.e. no password) which is not allowed (should not be!)
                    for (int first = 1; first < letters_count; first++)
                    {
                        key_candidate[0] = letters[first];  // 1)
                        key_candidate[1] = letters[second]; // 2)
                        key_candidate[2] = letters[third];  // 3)
                        key_candidate[3] = letters[fourth]; // 4)
                        key_candidate[4] = letters[fifth];  // 5)

                        // The key_candidate full of null characters and progresses from 1-letter
                        // all the way through 5-letter strings.
                        if (strcmp(crypt(key_candidate, salt), hash) == 0)
                        {
                            printf("%s\n", key_candidate);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("Password couldn't be cracked!");

    // Signal failure with exit code 2
    return 2;
}