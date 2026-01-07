#include <stdio.h>
#include <stdlib.h>

void greater_among_three(int a, int b, int c) {
    if (a<b) {
        if (b>c) {
            printf("b is the greater number");
        } else {
            printf("c is the greater number");
        }
    else if {
        if (a>c) {
            printf("a is the greater number");
        } else {
            printf("c is the greater number");
        }
    }
    }
}
int main() {
    int a;
    int b;
    int c;
    printf("Enter three integers positive: ");
    while (scanf(" %d%d%d", &a, &b, &c) != 3 | (a<0 || b<0 || c<0)) {
        printf("Please enter three valid positive integers");
    }
    greater_among_three(a, b, c);    
}










#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Utile pour les fonctions de validation

/**
 * @brief Détermine et affiche le plus grand parmi trois entiers.
 * * NOTE: Cette fonction ne gère pas le cas où des nombres sont égaux. 
 * Elle affichera le premier rencontré dans l'ordre de la logique de vérification.
 *
 * @param a Le premier entier.
 * @param b Le deuxième entier.
 * @param c Le troisième entier.
 */
void greater_among_three(int a, int b, int c) {
    // 1. Vérification si 'a' est le plus grand
    if (a >= b && a >= c) {
        printf("%d est le plus grand nombre.\n", a);
    } 
    // 2. Si 'a' n'est pas le plus grand, vérification si 'b' l'est
    else if (b >= a && b >= c) {
        printf("%d est le plus grand nombre.\n", b);
    } 
    // 3. Sinon, 'c' est nécessairement le plus grand
    else {
        printf("%d est le plus grand nombre.\n", c);
    }
}

/**
 * @brief Fonction pour lire et valider trois entiers positifs.
 * * @param a Pointeur vers le premier entier.
 * @param b Pointeur vers le deuxième entier.
 * @param c Pointeur vers le troisième entier.
 * @return true si la lecture et la validation ont réussi, false sinon.
 */
bool read_and_validate(int *a, int *b, int *c) {
    int result;
    printf("Entrez trois entiers positifs : ");
    // Tentative de lire les trois nombres.
    result = scanf("%d %d %d", a, b, c);
    // Vérifie si 3 valeurs ont été lues ET si elles sont toutes positives.
    if (result == 3 && *a >= 0 && *b >= 0 && *c >= 0) {
        return true;
    } else {
        // En cas d'échec de lecture ou de valeurs négatives/non-numériques:
        // Nettoyage du tampon d'entrée (important pour que la boucle while ne se bloque pas)
        while (getchar() != '\n' && !feof(stdin));        
        return false;
    }
}
int main() {
    int a, b, c;
    // Boucle de validation robuste : continue tant que la lecture échoue.
    while (!read_and_validate(&a, &b, &c)) {
        printf("Veuillez entrer trois entiers valides et positifs.\n");
    }
    // Appel de la fonction de comparaison
    greater_among_three(a, b, c);    
    return 0;
}