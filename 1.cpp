#include <iostream>
using namespace std;

int main() {
    // 1. Declaration/Initialization
    const int SIZE = 5; // Use a constant for the size for cleaner code
    int numbers[SIZE]; // Declares an array to hold 5 integers
    int sum = 0;       // Variable to store the total sum

    cout << "--- Array Summation Program ---\n";//output

    // 2. Input/Loop 1: Fill the array and calculate the sum simultaneously
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        // I/O Operation: Read the input into the array element at index 'i'
        cin >> numbers[i]; 
        
        // Arithmetic Operation: Add the newly entered number to the running sum
        sum += numbers[i]; // equivalent to: sum = sum + numbers[i];
    }
    
    // Note: We often use a second loop just for summing, but for efficiency, 
    // we included the sum calculation in the input loop.
    
    // 3. Output
    cout << "\n--------------------------\n";
    cout << "The total sum is: " << sum << endl;

    return 0;
}