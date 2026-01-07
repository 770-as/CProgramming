#include <iostream>
#include <vector>
#include <stdexcept> // For std::runtime_error
#include <numeric> // For std::accumulate
#include <algorithm> // For std::find

// Use a namespace for cleaner code and to avoid repeating 'std::'
using namespace std; 

/**
 * @brief Performs a sum of numbers, throwing an exception if a negative number is found.
 * * The 'constexpr' keyword means this function *can* be evaluated at compile time 
 * if its arguments are constant expressions.
 * * Note: Throwing an exception inside a constant expression context is permitted in C++20 
 * *if* the exception is caught within the constant expression. 
 * If it's not caught, it leads to a compile-time error.
 * If it's called at runtime, it behaves normally.
 */
constexpr int constexpr_safe_sum(const vector<int>& data) {
    int sum = 0;
    
    for (int value : data) {//for starts the loop, int value declares a temporary variable of type int that will hold the current
        if (value < 0) {//element in each iteration. data is the container being iterated over
            // Throwing at runtime is always fine.
            // If this is evaluated at compile-time and a negative number is found, 
            // the whole constant expression evaluation fails (unless caught).
            throw runtime_error("Negative value detected in input data."); 
        }
        sum += value;
    }
    return sum;
}

// Function to use the constexpr one, handling the exception at runtime
void run_vector_sum_runtime(const vector<int>& data) {
    try {
        int result = constexpr_safe_sum(data);
        cout << "Runtime Sum: " << result << endl;
    } catch (const runtime_error& e) {
        // Catch the exception thrown by the function
        cout << "Runtime Error: " << e.what() << endl;
    }
}

int main() {
    cout << "C++20 Constexpr and Exception Demo\n" << endl;

    // --- 1. Compile-Time Evaluation (Static Assertion) ---
    
    // Create a vector object inside the constexpr context.
    // This vector is temporary and its memory is managed at compile time.
    constexpr vector<int> compile_time_data = {10, 20, 30};
    
    // Use the constexpr function to calculate the result at compile time.
    // If constexpr_safe_sum threw an exception here, the compilation would fail.
    constexpr int compile_time_result = constexpr_safe_sum(compile_time_data);
    
    // Static_assert checks a condition at compile time.
    // This proves the function was executed during compilation.
    static_assert(compile_time_result == 60, "Compile-time sum failed!");
    
    cout << "1. Compile-Time Success (Checked by static_assert)." << endl;
    cout << " Result: " << compile_time_result << "\n" << endl;

    // --- 2. Runtime Success ---
    vector<int> runtime_data_ok = {5, 10, 15};
    cout << "2. Runtime Success Case:" << endl;
    run_vector_sum_runtime(runtime_data_ok);
    
    // --- 3. Runtime Exception (The 'throw' is executed) ---
    vector<int> runtime_data_error = {1, 2, -3, 4};
    cout << "\n3. Runtime Exception Case:" << endl;
    run_vector_sum_runtime(runtime_data_error);

    return 0;
}