#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string digs);
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    // Check for correct number of command line arguments, ie 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Check second command line argument is only digits
    else if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // Convert key to integer
        int key = atoi(argv[1]);
        // Get text to cipher
        string plaintext = get_string("plaintext:  ");
        // Print ciphered text
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++)
        {
            char new_letter = rotate(plaintext[i], key);
            printf("%c", new_letter);
        }
        printf("\n");
    }
}

bool only_digits(string digs)
{
    // Test key is only digits
    for (int i = 0; i < strlen(digs); i++)
    {
        if ((int) digs[i] > 47 && (int) digs[i] < 58)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

char rotate(char letter, int key)
{
    // Rotate nuber of spots indicated by key
    // Reduce key to 1-26
    key = key % 26;

    // Cipher capital letters
    if ((int) letter > 64 && (int) letter < 91)
    {
        int new_ascii = (int) letter + key;
        if (new_ascii > 90)
        {
            new_ascii = new_ascii - 26;
        }
        return (char) new_ascii;
    }
    // Cipher lowercase letters
    else if ((int) letter > 96 && (int) letter < 123)
    {
        int new_ascii = (int) letter + key;
        if (new_ascii > 122)
        {
            new_ascii = new_ascii - 26;
        }
        return (char) new_ascii;
    }
    // Leave everything else
    else
    {
        return letter;
    }
}
