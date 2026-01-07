#include <iostream>
using namespace std;

int main() {
    // 1. Constants and Declaration
    const int ARRAY_SIZE = 4;
    int grades[ARRAY_SIZE]; 
    double total = 0.0; // Use double to ensure floating-point division later

    cout << "--- Grade Average Calculator ---\n";

    // 2. Input/Loop: Fill array and calculate total
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "Enter grade for student " << (i + 1) << ": ";
        cin >> grades[i];
        
        // Arithmetic Operation: Accumulate the total
        total += grades[i]; 
    }

    // 3. Calculation
    // We cast ARRAY_SIZE to double to force floating-point division
    double average = total / ARRAY_SIZE; 

    cout << "\n--------------------------\n";
    
    // 4. Output
    cout << "Total sum of grades: " << total << endl;
    cout << "The average grade is: " << average << endl;

    return 0;
}