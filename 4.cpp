#include <iostream>
using namespace std;

int main() {
    // 1. I/O and Declaration
    int base_number; // The number to multiply
    int count;       // The number of multiples to show
    
    cout << "--- Sequence Generator ---\n";
    
    // Input (I/O Operations)
    cout << "Enter a number for the base of the sequence: ";
    cin >> base_number;
    
    cout << "Enter how many multiples to show (e.g., 10): ";
    cin >> count;

    cout << "\n--------------------------\n";
    
    // 2. Loop and Arithmetic
    // The loop counter 'i' goes from 1 (1st multiple) up to 'count' (Nth multiple)
    for (int i = 1; i <= count; i++) {
        // Arithmetic Operation: Calculate the multiple
        int result = base_number * i; 
        
        // Output (I/O Operation)
        cout << "Multiple " << i << ": " << base_number << " x " << i << " = " << result << endl;
    }

    return 0;
}