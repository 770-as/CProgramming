#include <iostream>
using namespace std;

int main() {
    // 1. Declaration
    double num1, num2; // Using 'double' for floating-point numbers

    cout << "--- Basic Arithmetic Calculator ---\n";
    
    // 2. Input (I/O Operations)
    cout << "Enter the first number: ";
    cin >> num1;
    
    cout << "Enter the second number: ";
    cin >> num2;

    cout << "\n--------------------------\n";
    
    // 3. Calculation and Output (Arithmetic Operations)
    cout << "Sum:        " << num1 + num2 << endl;
    cout << "Difference: " << num1 - num2 << endl;
    cout << "Product:    " << num1 * num2 << endl;
    
    // It's good practice to check for division by zero
    if (num2 != 0) {
        cout << "Quotient:   " << num1 / num2 << endl;
    } else {
        cout << "Quotient:   Cannot divide by zero." << endl;
    }

    return 0;
}