#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) { 
    if argc<2 {
        fprintf(stderr, "Utilisation: %s <nom_fichier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    pid_t pid;
    pid=fork();
    if (pid<0) {
        perror("echec de fork");
        exit(EXIT_FAILURE);
    }
    if (pid==0) {
        printf("Enfant: tentative de lancement d'un script python...\n");
        char* args={"/usr/bin/python3", "script.py", argv[1], NULL};
        execv(args[0], args);
}













