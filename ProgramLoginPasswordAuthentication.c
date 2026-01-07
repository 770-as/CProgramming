#include <stdio.h>  // Pour les fonctions d'entrée/sortie comme printf et scanf
#include <string.h> // Pour la fonction de comparaison de chaînes de caractères strcmp

int main() {
    // Définition du login et du mot de passe corrects
    // Assurez-vous que la taille des tableaux est suffisante pour stocker les chaînes
    // plus le caractère nul de fin de chaîne '\0'.
    // 100 caractères max pour le login et le mot de passe.
    const char correctLogin[] = "utilisateur";
    const char correctPassword[] = "motdepasse123";

    // Déclaration des tableaux pour stocker le login et le mot de passe saisis par l'utilisateur
    // La taille doit être suffisamment grande pour éviter les débordements de tampon (buffer overflow).
    // Ici, on alloue 100 caractères, ce qui est une bonne pratique pour des entrées simples.
    char inputLogin[100];
    char inputPassword[100];

    // --- Saisie du login ---
    printf("Entrez votre login : ");
    // Utilisation de scanf pour lire la chaîne de caractères.
    // %99s limite la lecture à 99 caractères pour éviter le débordement de tampon
    // (le 100ème caractère sera le '\0').
    // Note : scanf("%s", ...) s'arrête au premier espace. Pour lire une ligne entière,
    // il faudrait utiliser fgets ou scanf avec un format plus complexe.
    // Pour cet exemple simple, %99s est suffisant.
    if (scanf("%99s", inputLogin) != 1) {
        printf("Erreur lors de la lecture du login.\n");
        return 1; // Retourne un code d'erreur
    }

    // --- Saisie du mot de passe ---
    printf("Entrez votre mot de passe : ");
    // Nettoyer le tampon d'entrée avant de lire le mot de passe,
    // au cas où l'utilisateur aurait tapé plus de 99 caractères pour le login
    // et qu'il resterait des caractères dans le tampon.
    // Cela évite que le mot de passe soit lu automatiquement à partir du reste de l'entrée précédente.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (scanf("%99s", inputPassword) != 1) {
        printf("Erreur lors de la lecture du mot de passe.\n");
        return 1; // Retourne un code d'erreur
    }

    // --- Comparaison des chaînes ---
    // strcmp retourne 0 si les deux chaînes sont identiques.
    // Si strcmp(chaine1, chaine2) == 0, cela signifie que chaine1 est égale à chaine2.
    if (strcmp(inputLogin, correctLogin) == 0 && strcmp(inputPassword, correctPassword) == 0) {
        printf("Correct : Login et mot de passe valides.\n");
    } else {
        printf("Erreur : Login ou mot de passe incorrect.\n");
    }

    return 0; // Indique que le programme s'est exécuté avec succès