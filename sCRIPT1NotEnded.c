#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // Pour enregistrer la date et l'heure

int is_safe_file(const char *filename) {                                           //la fonction is safe file contient
    const char *allowed_files[] = {"data1.txt", "data2.txt"};               //une liste blanche des fichiers autorisés et
    int num_files = sizeof(allowed_files) / sizeof(allowed_files[0]);       //compare le fichier demandé avec cette liste
/*si le fichier est autorisé retourne 1 sinon retourne 0 interdit*/
    for (int i = 0; i < num_files; i++) {
        if (strcmp(filename, allowed_files[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {                  //argc is the number of arguments and argv[0] is the program'name
    if (argc < 2) {                                //argv[1] is the name of the file. 
        printf("Usage: %s <filename>\n", argv[0]);  //si l'utilisateur n'entre pas de fichier, on affiche un message
        return 1;                               //d'utilisation et on quitte
    }
    if (argc == 2 && strcmp(argv[1], "--logs") == 0) {
        show_logs();  // Affiche le contenu du fichier log.txt
        return 0;
    }
    if (argc == 2 && strcmp(argv[1], "--report") == 0) {
        generate_security_report();
        return 0;
    }
    
    if (argc == 3 && strcmp(argv[1], "--email") == 0) {
        send_report_by_email(argv[2]);
        return 0;
    }
        


    if (!is_safe_file(argv[1])) {
        printf("Accès refusé : fichier non autorisé !\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }



    void log_attempt(const char *filename) {
    FILE *logFile = fopen("log.txt", "a");  // "a" = ajout (append)

    if (logFile == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier log.\n");
        return;
    }

    // Obtenir la date et l'heure actuelles
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Écrire la tentative bloquée avec date et heure
    fprintf(logFile, "Tentative bloquée : %s - %04d-%02d-%02d %02d:%02d:%02d\n",
            filename,
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec);

    fclose(logFile);  // Fermer le fichier log
    }

//Fonction pour lire et afficher le contenu du fichier log.txt
    void show_logs() {
        FILE *logFile = fopen("log.txt", "r");
    
        if (logFile == NULL) {
            printf("Aucun journal de sécurité trouvé.\n");
            return;
        }
    
        printf("\n🔍 Journal des tentatives d'accès bloquées :\n");
        
        char line[256];  // Pour stocker chaque ligne
        while (fgets(line, sizeof(line), logFile)) {
            printf("%s", line);
        }
    
        fclose(logFile);
    }
    
    int count_blocked_attempts() {
        FILE *logFile = fopen("log.txt", "r");
        if (logFile == NULL) {
            return 0;  // Aucun log enregistré
        }
    
        int count = 0;
        char line[256];
    
        while (fgets(line, sizeof(line), logFile)) {
            count++;  // Compte chaque ligne = 1 tentative bloquée
        }
    
        fclose(logFile);
        return count;
    }

    
    void generate_security_report() {
        FILE *logFile = fopen("log.txt", "r");
        FILE *reportFile = fopen("security_report.txt", "w");
    
        if (reportFile == NULL) {
            printf("Erreur : Impossible de créer le fichier de rapport.\n");
            return;
        }
    
        int total_attempts = count_blocked_attempts();
        fprintf(reportFile, "🔒 Rapport de Sécurité - Tentatives Bloquées\n");
        fprintf(reportFile, "--------------------------------------------\n");
        fprintf(reportFile, "Nombre total de tentatives bloquées : %d\n\n", total_attempts);
    
        if (logFile == NULL) {
            fprintf(reportFile, "Aucune tentative bloquée enregistrée.\n");
        } else {
            fprintf(reportFile, "📜 Détails des accès bloqués :\n");
            char line[256];
            while (fgets(line, sizeof(line), logFile)) {
                fprintf(reportFile, "%s", line);  // Copie chaque ligne du log
            }
            fclose(logFile);
        }
    
        fclose(reportFile);
        printf("📄 Rapport de sécurité généré : security_report.txt\n");
    }
    
    fclose(file);
    return 0;
}
