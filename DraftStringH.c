




output=strtok(line, delim, pointer)//storing the address of the last character read)
char **split_string(const char *str, const char *delim, int *count) {
    char* ptr=line[0];
    int count=0;
    char* array;
    while (token != NULL) {
        token=strtok_r(ptr, "delil", &ptr);
        char* array=token;
        count=+1;
    }
    return 0;
}


char **split_string(const char *str, const char *delim, int *count) {
    int count=0;
    char* ptr;

}















#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Découpe une chaîne en jetons basés sur un délimiteur, en retournant 
 * un tableau de chaînes alloué dynamiquement.
 *
 * @param str La chaîne d'entrée (non modifiée).
 * @param delim La chaîne de délimiteurs (ex: ",").
 * @param count Pointeur vers un entier qui contiendra le nombre de jetons trouvés.
 * @return char** Un tableau de chaînes alloué dynamiquement (doit être libéré par l'appelant).
 */
char **split_string(const char *str, const char *delim, int *count) {
    if (str == NULL || delim == NULL || count == NULL) {
        return NULL; // Gestion des entrées NULL
    }

    char *str_copy;         // Copie modifiable pour strtok_r (passage 1)
    char *str_copy_temp;    // Copie modifiable pour strtok_r (passage 2)
    char *token;
    char *save_ptr1 = NULL; // Pointeur d'état pour le passage 1 (comptage)
    char *save_ptr2 = NULL; // Pointeur d'état pour le passage 2 (extraction)
    char **result_array = NULL;
    int token_count = 0;
    int i = 0;
    // --- 1. Copie de la chaîne (Nécessaire car strtok_r modifie l'originale) ---
    str_copy = strdup(str);
    if (str_copy == NULL) return NULL; 
    // --- 2. Premier Passage : Comptage des Jeton (Token) ---
    // Utiliser strtok_r sur str_copy pour compter le nombre de jetons.
    token = strtok_r(str_copy, delim, &save_ptr1);
    while (token != NULL) {
        token_count++;
        // Appel avec NULL pour continuer
        token = strtok_r(NULL, delim, &save_ptr1); 
    }

    *count = token_count;
    
    // Si aucun jeton trouvé, libérer la copie et retourner NULL.
    if (token_count == 0) {
        free(str_copy);
        return NULL;
    }

    // --- 3. Allocation de la mémoire pour le tableau de pointeurs ---
    result_array = (char **)malloc(sizeof(char *) * token_count);//result_array is the name of the pointer of pointers
//char ** is the type and the bloc with malloc precise the size. 
    if (result_array == NULL) {
        free(str_copy);
        return NULL;
    }
    // --- 4. Second Passage : Extraction et Copie des Jeton ---
    str_copy_temp = strdup(str); // Recrée une copie propre pour l'extraction
    if (str_copy_temp == NULL) {
        free(str_copy);
        free(result_array);
        return NULL;
    } 
    
    // Réinitialisation de l'analyse
    token = strtok_r(str_copy_temp, delim, &save_ptr2);
    
    while (token != NULL && i < token_count) {
        // strdup crée une copie persistante du jeton (à libérer plus tard)
        result_array[i] = strdup(token); 
        
        if (result_array[i] == NULL) {
            // Gestion des erreurs d'allocation: libérer tout ce qui a été alloué
            for (int j = 0; j < i; j++) {
                free(result_array[j]);
            }
            free(result_array);
            free(str_copy);
            free(str_copy_temp);
            return NULL;
        }
        i++;
        token = strtok_r(NULL, delim, &save_ptr2);
    }
    
    // --- 5. Nettoyage et Retour ---
    free(str_copy);      // Libérer la copie utilisée pour le comptage
    free(str_copy_temp); // Libérer la copie utilisée pour l'extraction
    
    return result_array; // Retourne le tableau de pointeurs
}

// --- Fonction main pour tester ---
int main() {
    char *input = "apple,banana,cherry,date";
    char *delim = ",";
    int count = 0;
    char **tokens;
    printf("Chaîne d'entrée: \"%s\"\n", input);

    // Appel de la fonction
    tokens = split_string(input, delim, &count);

    if (tokens != NULL) {
        printf("Nombre de jetons trouvés: %d\n", count);
        printf("--- Jetons ---\n");
        for (int i = 0; i < count; i++) {
            printf("Token [%d]: \"%s\"\n", i, tokens[i]);
        }
        
        // Nettoyage de la mémoire: ESSENTIEL
        for (int i = 0; i < count; i++) {
            free(tokens[i]); // Libère chaque jeton (alloué par strdup)
        }
        free(tokens); // Libère le tableau de pointeurs
    } else {
        printf("Erreur ou aucun jeton trouvé.\n");
    }
    
    // Test avec chaîne vide
    input = "";
    tokens = split_string(input, delim, &count);
    printf("\nTest chaîne vide. Tokens trouvés: %d\n", count);
    if (tokens != NULL) {
        // En cas de chaînes mal formées (seulement des délimiteurs), assurez-vous de libérer ici aussi
        free(tokens);
    }
    return 0;
}
