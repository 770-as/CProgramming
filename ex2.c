/*Write a C program that takes a number as a command-line argument. Create a function is_prime that checks if a number
is prime. This function will be executed by a separate thread. Use pthread_create to spawn a new thread
that calls is_prime with the number from the command line. The main thread should print "Checking for prime 
status..." and then wait for the child thread to finish using pthread_join. The child thread should return a value 
(e.g., 1 for prime, 0 for not prime) that the main thread can retrieve. The main thread should then print the final
result based on the value received from the thread.*/