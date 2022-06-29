#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check for 2 command line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check for correct key length (26)
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    else
    {
        string key_lower = argv[1];
        int counts[25];

        // Check key
        for (int i = 0; i < 26; i++)
        {
            // Check key is all letters
            if (argv[1][i] < 'A' || (argv[1][i] > 'Z' && argv[1][i] < 'a') || argv[1][i] > 'z')
            {
                printf("Key must contain 26 letters.\n");
                return 1;
            }
            key_lower[i] = tolower(key_lower[i]);
            // Count number of times a letter appears in the key
            counts[key_lower[i] - 97]++;
        }
        for (int i = 0; i < 26; i++)
        {
            // Fail if a letter appears more than once
            if (counts[i] > 1)
            {
                printf("Key must contain 26 unique letters.\n");
                return 1;
            }
        }

        // Get text to cipher
        string plaintext = get_string("plaintext:  ");

        // Print ciphered text
        printf("ciphertext: ");
        string cipher = argv[1];
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // Cipher capital letters
            if ((int) plaintext[i] > 64 && (int) plaintext[i] < 91)
            {
                for (int j = 0; j < 26; j++)
                {
                    cipher[j] = toupper(cipher[j]);
                }
                int in_key = (int) plaintext[i] - 65;
                plaintext[i] = cipher[in_key];
                printf("%c", plaintext[i]);
            }
            // Cipher lowercase letters
            else if ((int) plaintext[i] > 96 && (int) plaintext[i] < 123)
            {
                for (int j = 0; j < 26; j++)
                {
                    cipher[j] = tolower(cipher[j]);
                }
                int in_key = (int) plaintext[i] - 97;
                plaintext[i] = cipher[in_key];
                printf("%c", plaintext[i]);
            }
            // Leave everything else as is
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
    return 0;
}