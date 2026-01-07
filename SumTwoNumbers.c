#include <stdio.h>
int main() {
    int nombre1, nombre2, somme;
    printf("Entrez le premier nombre: ");
    scanf("%d", &nombre1);
    printf("Entrez le deuxième nombre: ");
    scanf("%d", &nombre2);
    somme=nombre1+nombre2;
    printf("La somme de %d et %d est : %d\n", nombre1, nombre2, somme);
    return 0;
}