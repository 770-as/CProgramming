/*Create a C program that uses a global integer variable, counter, initialized to zero. Write a function 
increment_counter that increments the counter variable a large number of times (e.g., 1,000,000). Create two threads
that both run the increment_counter function. Use pthread_create to start both threads and pthread_join to wait for
them to finish. Print the final value of counter. You'll notice it's likely not the expected value (2,000,000).
Why? (This is a classic race condition problem). Fix the problem: Use a mutex (pthread_mutex_t) to protect the
critical section where the counter is incremented. Initialize the mutex, lock it before incrementing, and unlock it
after. Print the final correct value*/

