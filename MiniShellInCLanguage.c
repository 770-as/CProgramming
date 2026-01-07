#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void parse_input(char *input, char **args) {
    char *token = strtok(input, " ");//The token pointer will temporarily holds the address of each word found in the strtok function.  
    int i = 0;          //a place in memory dedicated to integers is now allocated
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}
//void indicates that the function doesn't return any value, it modifies the args array directly. 
//char *input is the first parameter and it's a pointer to a char which is in C how strings are typically represented
//the strtok function modifies the original input string by placing null terminators, this means the input string will be altered after 
//the function call. 
//char **args is a pointer to a pointer to a char. It's the standard way to represent an array of strings in C. Each element in the
//args array will be a pointer to a string, pointing to one of the tokens found in the input string.


int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];
    pid_t pid;
    int status;

    while (1) {
        printf("mini-shell> ");
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            break;
        }
        
        // Remove newline character
        input[strcspn(input, "\n")] = 0;
        
        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        parse_input(input, args);
        
        pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp failed");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(&status);
        }
    }

    return 0;
}
