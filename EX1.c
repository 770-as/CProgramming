int multiplier_nombres(nombreA, nombreB)
{
    int resultat = nombreA*nombreB;
    return resultat
}
int echanger_entiers(nombre1,nombre2)
{
    printf("%d,%d"nombre1,nombre2)
    int temporaire=nombre1;
    nombre1=nombre2;
    nombre2=temporaire;
    printf("%d,%d"nombre1,nombre2)
}
char ASCII()
{

}
int pair_ou_impair(entier)
{
    if entier%2==0
        return pair
    else;
        return impair 
}
int plus_grand2(intA,intB,intC)
{
    if intA>intB 
        return plus_grand(intA,intC)
    else;
        return plus_grand(intB,intC)
}



#include <stdio.h>
int main() {
    int nombre;
    printf("Entrez un nombre entier:");
    scanf("%d", &nombre);

    if (nombre%2==0) {
        printf("Le nombre %d est pair.\n", nombre);
    } else {
        printf("Le nombre %d est impair.\n", nombre);
    }
    return 0;
}



#include <stdio.h>

int factorielle(int n) {
    if (n==0 || n==1) {
        return 1;
    } else {
        return n*factorielle(n-1);
    }
}
int main() {
    int nombre;
    printf("La factorielle est définie uniquement pour les entiers positifs.\n");
} else {
    printf("La factorielle de %d est: %d\n", nombre, factorielle(nombre));
}
return













#include <stdio.h>

float lireNombre() {
    float nombre;
    int resultat;

    while (1) {
        printf("Entrez un nombre : ");
        resultat = scanf("%f", &nombre);

        if (resultat==1) {
            while (getchar() != '\n');
            return nombre;
        } else {
            printf("Erreur ! Veuillez entrer un nombre valide.\n");
            while (getchar() != '\n');
        }
    }
}
int main() {
    float nombre1, nombre2, somme;
    char choix;

    do{
        nombre1= lireNombre();
        nombre2= lireNombre();
        somme= nombre1+nombre2;
        printf("La somme de %.2f et %.2f est %.2f\n", nombre1, nombre2, somme);
        printf("Voulez-vous faire un autre calcul ?(o/n):");
        while (1) {
            scanf("%c", &choix);
            while (getchar() != '\n');
            if (choix=='o' || choix=='o' || choix == 'n' || choix == 'N') {
                break;
            }
            printf("Entrée invalide. Tapez 'o' pour continuer ou 'n' pour quitter : ")
        }
    } while (choix=='o' || choix == 'O');
    printf("Programme terminé. Merci d'avoir utlisé le calculateur!\n");
    return 0;
}
/*On a créé la boucle de gestion des erreurs. La fonction scanf stocke les caractères saisis dans une zone mémoire
appelée buffer d'entrée mais la fonction scanf ne consomme pas tous les caractères dans le buffer. Elle lira les 
premiers caractères du buffer et le problème est que lors de la prochaine lecture, scanf ne lira pas les nouveaux
caractères entrés mais ceux restant dans le buffer. getchar() lit un caractère à la fois et va vider ces caractères
restants. La condition getchar() != '\n' garantit qu'on lit et qu'on ignore tous les caractères dans le buffer jusqu'à
ce qu'on rencontre un saut de ligne. En d'autres termes, cela évacue tout ce qui reste pour s'assurer que la prochaine
saisie soit propre.
while(1) crée une boucle infinie, elle continue tant que l'utilisateur n'entre pas la bonne réponse. scanf(" %c", &choix) est
important il permet de ignorer les espaces ou retours à la ligne laissés dans le buffer. Si l'utilisateur entre
o, O, n, N alors la boucle se termine avec break sinon, le programme affiche un message d'erreur et redemande la saisie.
do while permet de répéter le processus du calcul. break est une instruction qui permet de sortir immédiatement de la 
boucle dans laquelle elle se trouve. Ca permet de passer à l'étape suivante. continue signifie que la boucle continue sans
sortir d'elle-même, continue fait en sorte que la boucle demanderait encore une saisie.*/