#include <stdio.h> // Inclusion de la bibliothèque standard d'entrée/sortie

int main() {
    int nombre; // Déclaration de la variable pour stocker le nombre entré par l'utilisateur
    int i;      // Déclaration de la variable pour la boucle (multiplicateur)

    // Demander à l'utilisateur d'entrer un nombre
    printf("Entrez un nombre entier positif : ");

    // Lire le nombre entré par l'utilisateur
    // scanf retourne le nombre d'éléments lus avec succès.
    // Si ce n'est pas 1 (c'est-à-dire que l'entrée n'est pas un entier),
    // ou si le nombre est négatif, on affiche un message d'erreur.
    if (scanf("%d", &nombre) != 1 || nombre < 0) {
        printf("Erreur : Veuillez entrer un nombre entier positif valide.\n");
        // Retourner un code d'erreur pour indiquer que le programme n'a pas pu s'exécuter correctement
        return 1;
    }

    // Afficher l'en-tête de la table de multiplication
    printf("\nTable de multiplication de %d jusqu'à 10 :\n", nombre);

    // Boucle pour calculer et afficher les produits de 1 à 10
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", nombre, i, nombre * i);
    }

    // Retourner 0 pour indiquer que le programme s'est exécuté avec succès
    return 0;
}
