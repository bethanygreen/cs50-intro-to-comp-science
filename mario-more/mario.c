#include <cs50.h>
#include <stdio.h>

int main(void)
{
// Get user-inputted height
int height = get_int("Height: ");
// Only 1-8 integers
while (height < 1 || height > 8)
{
    height = get_int("Height: ");
}

int counter = 0;

while (height > 0)
{
    // Print spaces
    int spaces = height - 1;
    for (int i = spaces; i > 0; i--)
    {
    printf(" ");
    };

    // Print left-side hashes
    for (int i = 1; i < counter + 2; i++)
    {
    printf("#");
    };

    // Print middle spaces
    printf("  ");

    // Print right-side hashes
    for (int i = 1; i < counter + 2; i++)
    {
    printf("#");
    };

    // New line
    printf("\n");

    // Increment counts
    height--;
    spaces--;
    counter++;
}

}