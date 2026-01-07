/*write a pointer which is pointing to allocated memory and write a temporal variable which is pointing 
to reallocated memory. Set to equal the ptr variable to the temp variable
In a loop, fill the allocated memory and print the result in a loop, then free the
memory and print something to end. */


#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(5 * sizeof(int));

    if (arr == NULL) return 1;
    printf("Original size: ");
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
        printf("%d ", arr[i]); // No newline here
    }
    
    *temp = (int *)realloc(arr, 10 * sizeof(int));

    if (temp != NULL) {
        arr = temp; // Only update if successful
    } else {
        // Handle allocation failure (arr still holds valid memory)
    }
    printf("Final size: ");
    for (int i = 0; i < 5; i++) {
        arr[i+4]=i+5;
        printf("%d", arr[i]); //No newline here
    }
    free(arr);
    printf("\n");
    printf("Memory freed successfully")
    return 0;
}
