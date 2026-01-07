#include <pthread.h> // Pour les fonctions pthreads
#include <stdio.h>   // Pour printf
#include <stdlib.h>  // Pour EXIT_SUCCESS
#include <unistd.h>  // Pour sleep

// Nombre de threads à créer
#define NUM_THREADS 5

// Structure pour passer des arguments aux threads
typedef struct {
    int thread_id;
    char *message;
} thread_data_t;

// Fonction que chaque thread va exécuter
void *tache_thread(void *arg) {
    // Cast l'argument void* vers notre structure thread_data_t
    thread_data_t *data = (thread_data_t *)arg;
    printf("Thread %d: Début de la tâche. Message: \"%s\"\n", data->thread_id, data->message);

    // Simule un travail long en dormant
    sleep(1 + (data->thread_id % 3)); // Chaque thread dort un peu différemment
    printf("Thread %d: Tâche terminée.\n", data->thread_id);

    // Les threads doivent se terminer proprement. pthread_exit(NULL) est une bonne pratique.
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS]; // Tableau pour stocker les identifiants des threads
    thread_data_t thread_data[NUM_THREADS]; // Tableau pour stocker les données à passer à chaque thread
    int rc; // Code de retour des fonctions pthread

    printf("Main: Création de %d threads...\n", NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {
        // Préparation des données pour le thread
        thread_data[i].thread_id = i + 1;
        // Allouer de la mémoire pour le message de manière dynamique ou utiliser des chaînes statiques si elles sont courtes
        // Pour cet exemple simple, nous allons le faire statiquement, mais faites attention en production.
        // Si les messages sont uniques par thread, une allocation dynamique par thread_data est meilleure.
        char msg_buffer[50];
        sprintf(msg_buffer, "Salut du thread %d!", i + 1);
        thread_data[i].message = strdup(msg_buffer); // strdup alloue de la mémoire et copie la chaîne

        // Création du thread
        // pthread_create(pthread_t *thread, const pthread_attr_t *attr,
        //               void *(*start_routine)(void *), void *arg)
        // thread: Pointeur vers l'identifiant du thread
        // attr: Attributs du thread (NULL pour les attributs par défaut)
        // start_routine: Fonction que le thread va exécuter
        // arg: Argument à passer à la fonction du thread (doit être un void*)
        rc = pthread_create(&threads[i], NULL, tache_thread, (void *)&thread_data[i]);

        if (rc) {
            printf("ERREUR: Impossible de créer le thread %d, code de retour: %d\n", i + 1, rc);
            exit(EXIT_FAILURE);
        }
    }

    printf("Main: Tous les threads sont lancés. Attente de leur fin...\n");

    // Attendre que tous les threads se terminent
    for (int i = 0; i < NUM_THREADS; i++) {
        // pthread_join(pthread_t thread, void **retval)
        // thread: L'identifiant du thread à attendre
        // retval: Pointeur vers un pointeur pour récupérer la valeur de retour du thread (NULL si non nécessaire)
        pthread_join(threads[i], NULL);
        free(thread_data[i].message); // Libérer la mémoire allouée par strdup
    }

    printf("Main: Tous les threads sont terminés. Programme principal terminé.\n");

    return EXIT_SUCCESS;
}






















#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Demande à l'utilisateur de saisir le chemin d'un programme exécutable à lancer (par exemple, /bin/ls ou /bin/date).
Utilise la fonction fork() pour créer un processus enfant. Dans le processus enfant, remplace son image mémoire par
le programme saisi par l'utilisateur en utilisant execlp(). N'oubliez pas de passer les arguments nécessaires au 
programme (par exemple, un argument -l pour ls). Dans le processus parent, attendez la fin du processus enfant en
utilisant la fonction wait(). Affiche un message indiquant que le processus enfant a terminé et qu'il est temps de
quitter. Ce problème est très similaire à la façon dont un shell (bash, zsh) fonctionne. C'est un excellent exercice 
pour comprendre comment les processus sont créés et gérés par le système d'exploitation.

La fonction fork() est utilisée pour créer un nouveau processus. Ce nouveau processus, appelé processus enfant,
est une copie quasi-identique du processus qui l'a appelé, le processus parent. Bibliothèque : Elle appartient à la
bibliothèque <unistd.h>. Utilisation : Elle ne prend aucun argument. Elle renvoie une valeur différente dans le
processus parent et dans le processus enfant, ce qui permet à votre code de savoir dans quel processus il se trouve.
Comportement : Dans le parent : fork() renvoie le PID (identifiant de processus) du processus enfant.
Dans l'enfant : fork() renvoie la valeur 0. En cas d'erreur : fork() renvoie -1.
a fonction fork() est unique car elle ne renvoie qu'une seule valeur, mais cette valeur est différente pour
les deux processus qui continuent de s'exécuter.
Dans le processus parent : fork() renvoie le PID de l'enfant que le parent vient de créer.
Dans le processus enfant : fork() renvoie 0. C'est le signal qui indique au code qu'il se trouve maintenant
dans le processus enfant.
En cas d'erreur : fork() renvoie -1 et ne crée pas de processus enfant.
Les fonctions getpid() et getppid()
Ce sont des fonctions standard qui permettent à un processus de connaître son propre PID ou celui de son parent.
Elles sont cruciales pour la communication et la gestion des processus.
getpid() : Renvoie le PID du processus qui l'appelle. Si un processus enfant appelle cette fonction,
elle renvoie son propre PID. getppid() : Renvoie le PID du processus parent qui l'a créé. Si un processus enfant
appelle cette fonction, elle renvoie le PID de son parent.
Le bon scénario
Pour obtenir le PID de l'enfant et du parent, voici comment le code de votre exemple fork_wait_example_c procède.
Dans le processus parent, la variable pid est assignée le PID de l'enfant. C'est ce PID que le parent peut utiliser
plus tard avec wait() pour attendre cet enfant spécifique. En même temps, le parent peut appeler getpid() pour 
connaître son propre PID. Dans le processus enfant, la variable pid est assignée 0. Pour connaître son propre PID,
l'enfant doit appeler  getpid(). Et pour connaître le PID de son parent, il peut appeler getppid().
Pour résumer, la variable pid stocke : Le PID de l'enfant dans le processus parent 0 dans le processus enfant
Le code utilise ensuite cette valeur pour différencier les deux processus et leur assigner des tâches différentes. 
C'est pour cette raison qu'on a le if (pid == 0) pour l'enfant et le else pour le parent.*/











#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc<2) {
        fprintf(stderr, "Utilisation: %s <nom_fichier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    pid_t pid;
    pid = fork();
    if (pid<0) {
        perror("echec de fork");
        exit(EXIT_FAILURE);
    }
    if (pid==0) {
        printf("Enfant: tentative de lancement d'un script python...\n");
        char* args[] = {
            "/usr/bin/python3",
            "script.py",
            argv[1],
            NULL
        }
        execv(args[0], args);
        perror("Echec de execv");
        exit(EXIT_FAILURE);
    } else {
        int status;
        printf("Parent: J'attends que mon enfant (PID: %d) finisse...\n", pid);
        wait(&status);
        printf("Parent: L'enfant est termine avec le code de sortie: %d.\n", WEXITSTATUS(status));
    }
    return 0;
}
/*Standard Input (stdin): This is for reading input. By default, it's connected to your keyboard.
Standard Output (stdout): This is for writing regular output. By default, it's connected to your terminal screen.
Standard Error (stderr): This is for writing error messages and diagnostics. By default, it's also connected to 
your terminal screen. 
<stdio.h> (Standard I/O) : Ce fichier d'en-tête gère toutes les opérations de base d'entrée et de sortie. C'est ici
que sont définis stdin, stdout et stderr, ainsi que des fonctions comme printf(), scanf() et fprintf().
<errno.h> (Error Number) : Ce fichier est spécifiquement dédié à la gestion des erreurs. Il contient les définitions
de la variable globale errno et des constantes d'erreur comme ENOENT et EACCES.
wait(&status) est l'appel qui suspend l'exécution du parent jusqu'à ce que son enfant se termine. Cela permet de 
synchroniser les deux processus. Le PID de l'enfant est utilisé dans la phrase pour vous montrer que le parent 
sait qui attendre. La variable status est utilisée pour obtenir le code de sortie de l'enfant. */












#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;sys/types.h&gt;
#include &lt;sys/wait.h&gt;
#include &lt;unistd.h&gt;

int main() {
    pid_t = pid;
// Creation d'un processus enfant
    pid = fork();

    if (pid < 0) {
        perror("La création du processus a échoué");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
// CODE DU PROCESSUS ENFANT
        printf("Je suis le processus enfant. Mon PID est %d.\n", getpid());
        printf("L'enfant va se terminer maintenant et devenir un zombie.\n");
// Le processus enfant se termine, mais le parent ne l'attend pas.
// Cela le transforme en processus zombie.
        exit(EXIT_SUCCESS);
    } else {
// CODE DU PROCESSUS PARENT
        printf("Je suis le processus parent. Mon enfant a le PID %d.\n", pid);
        printf("Le parent ne va PAS attendre l'enfant et va dormir pendant 15 secondes.\n");
        printf("Pendant ce temps, l'enfant est en état 'zombie'.\n");
// Le parent dort, laissant le processus enfant dans l'etat 'Z' (zombie)
        sleep(15); 

// Le parent va maintenant collecter l'enfant zombie
// Notez que si le programme se termine, le systeme d'exploitation
// va automatiquement nettoyer le processus zombie.
        wait(NULL);
        printf("Le parent a appelé wait() et a libéré l'enfant zombie.\n");
    }
    return(EXIT_SUCCESS)
}




//zombie process
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Creation d'un processus enfant
    pid = fork();

    if (pid < 0) {
        perror("La creation du processus a echoue");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        // CODE DU PROCESSUS ENFANT
        printf("Je suis le processus enfant. Mon PID est %d.\n", getpid());
        printf("L'enfant va se terminer maintenant et devenir un zombie.\n");
        // Le processus enfant se termine, mais le parent ne l'attend pas.
        // Cela le transforme en processus zombie.
        exit(EXIT_SUCCESS);

    } else {
        // CODE DU PROCESSUS PARENT
        printf("Je suis le processus parent. Mon enfant a le PID %d.\n", pid);
        printf("Le parent ne va PAS attendre l'enfant et va dormir pendant 15 secondes.\n");
        printf("Pendant ce temps, l'enfant est en etat 'zombie'.\n");

        // Le parent dort, laissant le processus enfant dans l'etat 'Z' (zombie)
        sleep(15);

        // Le parent va maintenant collecter l'enfant zombie
        // Notez que si le programme se termine, le systeme d'exploitation
        // va automatiquement nettoyer le processus zombie.
        wait(NULL);
        printf("Le parent a appele wait() et a libere l'enfant zombie.\n");
    }

    return EXIT_SUCCESS;
}
/*wait(NULL) est une version simplifiée de la fonction wait(). C'est une façon concise de dire
au système d'exploitation que le processus parent doit attendre que n'importe lequel de ses enfants se termine, 
sans se soucier de récupérer le code de sortie.Quand utiliser wait(NULL) ?
L'utilisation de wait(NULL) est très courante et appropriée dans les scénarios où vous n'avez besoin que d'une
chose: libérer le processus zombie. Par exemple, si un processus parent crée un enfant dont l'unique but est 
d'exécuter une commande comme ls -l et que vous vous fichez de savoir si ls a réussi, alors wait(NULL) est parfait.
C'est plus simple à écrire et plus lisible. C'est aussi un moyen de s'assurer que vous ne laisserez pas de processus 
zombie derrière vous. En résumé, wait(NULL) signifie : "Attends que l'un de mes enfants se termine et libère ses 
ressources. Je n'ai pas besoin de connaître la raison de sa fin."
Si vous fournissez un pointeur valide (comme &status), wait() remplit la variable status avec des informations sur la manière
dont l'enfant s'est terminé (s'il s'est terminé normalement, quel était son code de retour, etc.). C'est utile si
vous avez besoin de savoir si l'opération de l'enfant a réussi.*/











//pipeline communication between child-parent process
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    pid_t pid;
    pid=fork();
    
}