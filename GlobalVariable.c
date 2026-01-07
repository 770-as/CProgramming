#include <stdio.h>

int counter = 0; // Global integer variable

void increment_counter() {
    counter++; // Accessing and modifying the global variable
}

int main() {
    increment_counter();
    printf("Counter value: %d\n", counter); // The value is now 1
    return 0;
}