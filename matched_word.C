#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define MAX_SENTENCE_LENGTH 500 // Constante mise à jour
#define MAX_WORD_LENGTH 50

// Fonction utilitaire pour nettoyer la chaine lue par fgets (retire le '\n')
void clean_newline(char *str) {
    size_t len = strlen(str);
    // Verifie s'il y a un '\n' a la fin et le remplace par '\0'
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    char *matched_word;

    // --- Saisie de la phrase (Utilisation de fgets pour la ligne entiere) ---
    printf("Entrez une phrase de votre choix (max %d caracteres) :\n", MAX_SENTENCE_LENGTH - 1);
    // fgets lit la ligne entiere de stdin et la stocke dans sentence
    if (fgets(sentence, MAX_SENTENCE_LENGTH, stdin) == NULL) {
        printf("Erreur de lecture de la phrase.\n");
        return 1;
    }
    clean_newline(sentence); // Retire le caractere de nouvelle ligne potentiellement ajoute par fgets
    
    // --- Saisie du mot a chercher (Utilisation de scanf pour un seul mot) ---
    printf("Entrez un mot a chercher dans la phrase (max %d caracteres) :\n", MAX_WORD_LENGTH - 1);
    
    // CORRECTION ICI : Utilisation de scanf avec le format %s et la variable 'word'.
    // Nous utilisons aussi un max de caractères (49) pour la sécurité.
    if (scanf("%49s", word) != 1) {
        printf("Erreur de lecture du mot.\n");
        return 1;
    }

    // --- Recherche du mot ---
    matched_word = strstr(sentence, word);
    
    // --- Affichage du resultat (Condition corrigee) ---
    if (matched_word != NULL) {
        printf("\nLe mot donne '%s' a ete trouve dans la phrase : \"%s\".\n", word, sentence);
        printf("Il commence a l'index : %ld\n", matched_word - sentence);
    } else {
        printf("\nLe mot donne '%s' n'a pas ete trouve dans la phrase : \"%s\".\n", word, sentence);
    }
    
    return 0;
}