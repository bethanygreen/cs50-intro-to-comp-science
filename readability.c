#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get text and calculate letters, words, sentences, and Coleman-Liau index
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = round(0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8);

    // Print numer of letters, words. and sentences
    printf("Letters: %d\n", letters);
    printf("Words: %d\n", words);
    printf("Sentences: %d\n", sentences);

    // Print grade if between 1 and 16
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

int count_letters(string text)
{
    // Calculate number of letters
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Convert all to lowercase and increment counter if letter
        char letter = tolower(text[i]);
        if ((int) letter < 123 && (int) letter > 96)
        {
            letters++;
        }
        else
        {
            continue;
        }
    }
    return letters;
}

int count_words(string text)
{
    // Caluclate number of words by counting spaces
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        char letter = text[i];
        if ((int) letter == 32)
        {
            words++;
        }
        else
        {
            continue;
        }
    }
    return words;
}

int count_sentences(string text)
{
    // Calculate number of sentences by counting punctuation
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char letter = text[i];
        if ((int) letter == 33 || (int) letter == 46 || (int) letter == 63)
        {
            sentences++;
        }
        else
        {
            continue;
        }
    }
    return sentences;
}