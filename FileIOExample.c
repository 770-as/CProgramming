#include <stdio.h>
#include <string.h>

int main() {
    FILE *file_ptr;
    char buffer[256];
    
    // --- PART 1: WRITING TO A FILE (using 'w' mode) ---
    // The 'w' mode will create the file or overwrite it if it exists.
    printf("--- Writing to file ---\n");
    file_ptr = fopen("example.txt", "w");
    if (file_ptr == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    
    fputs("This is the first line.\n", file_ptr);
    fputs("And this is the second line.\n", file_ptr);
    fputs("We'll add a number: ", file_ptr);
    fprintf(file_ptr, "%d\n", 12345);
    
    printf("Successfully wrote content to example.txt\n\n");
    fclose(file_ptr);

    // --- PART 2: READING FROM THE FILE (using 'r' mode) ---
    // The 'r' mode requires the file to exist.
    printf("--- Reading from file ---\n");
    file_ptr = fopen("example.txt", "r");
    if (file_ptr == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // fgets is safe to use for reading a line.
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        // Print the content read from the file.
        printf("Read: %s", buffer);
    }
    
    printf("\nSuccessfully read all content from example.txt\n\n");
    fclose(file_ptr);

    // --- PART 3: APPENDING TO THE FILE (using 'a' mode) ---
    // The 'a' mode will add content to the end of the file.
    printf("--- Appending to file ---\n");
    file_ptr = fopen("example.txt", "a");
    if (file_ptr == NULL) {
        perror("Error opening file for appending");
        return 1;
    }
    
    fputs("This is a new line added at the end.\n", file_ptr);
    
    printf("Successfully appended content to example.txt\n\n");
    fclose(file_ptr);
    
    // --- PART 4: READING THE FINAL, FULL CONTENT ---
    // We'll read the entire file again to show the appended line.
    printf("--- Reading final content ---\n");
    file_ptr = fopen("example.txt", "r");
    if (file_ptr == NULL) {
        perror("Error opening file for final reading");
        return 1;
    }
    
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        printf("Final Content: %s", buffer);
    }
    
    fclose(file_ptr);

    return 0;
}
