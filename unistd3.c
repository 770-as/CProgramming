#include <stdio.h>

int main(void)
{
    // A single block of memory containing multiple strings,
    // each separated by a null terminator ('\0').
    // The sequence is terminated by a double null terminator.
    char text_block[] = "String one\0String two\0String three\0String four\0String five\0"
                        "String six\0String seven\0String eight\0String nine\0String ten\0\0";

    // A single character pointer to traverse the entire memory block.
    char *ptr = text_block;

    // Outer loop: Continues as long as the pointer is not at the end of the entire block.
    // The loop's condition will be false when it encounters the final, double null terminator.
    int string_count = 1;
    while (*ptr != '\0')
    {
        printf("String %d: ", string_count);

        // Inner loop: Processes the characters of a single string.
        // It continues until it hits the null terminator for the current string.
        while (*ptr != '\0')
        {
            // Dereference the pointer to get the current character and print it.
            printf("%c", *ptr);
            
            // Increment the pointer to move to the next memory address (the next character).
            ptr++;
        }

        // After the inner loop, the pointer is at the null terminator.
        // Print a newline for formatting.
        printf("\n");

        // Increment the pointer one more time to skip over the null terminator
        // and move to the start of the next string.
        ptr++;
        string_count++;
    }

    return 0;
}