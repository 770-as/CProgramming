#include <iostream>
using namespace std;

int main() {
    // 1. Declaration/Initialization
    const int SIZE = 7;
    // Array Initialization: We assign initial values directly
    int scores[SIZE] = {85, 92, 78, 65, 99, 88, 70}; 
    
    // Initialize max and min to the first element of the array
    int max_score = scores[0]; 
    int min_score = scores[0];

    cout << "--- Max/Min Finder ---\n";
    cout << "Scores: ";

    // Optional: Print the array elements using a range-based for loop (modern C++)
    // This loop iterates *over* the elements, not the indices.
    for (int score : scores) {
        cout << score << " ";
    }
    cout << "\n--------------------------\n";

    // 2. Loop and Comparison: Start checking from the *second* element (index 1)
    for (int i = 1; i < SIZE; i++) {
        // Comparison/Update for Maximum
        if (scores[i] > max_score) {
            max_score = scores[i];
        }

        // Comparison/Update for Minimum
        if (scores[i] < min_score) {
            min_score = scores[i];
        }
    }
    
    // 3. Output
    cout << "The highest score is: " << max_score << endl;
    cout << "The lowest score is:  " << min_score << endl;

    return 0;
}