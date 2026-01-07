/*
std:: is a fundamental part of C++ proramming. 
It's a way to specify the namespace where almost all elements of the C++ standard library are defined. 
A namespace is a container for a set of identifiers (names of functions, classes, variables). Its purpose is to prevent name collisions.
std::cout tells the compiler: "looks inside the standard namespace and find the object named cout." 
std::vector refers to the vector class in the standard library. 
std::endl refers to the end-line manipulator.



*/
void {
    printf("Hello World");
}

void {
    printf("Enter two numbers");
    while scanf("%d %d", &a, &b)!=2 || a<0 or b<0;
        printf("Saisie invalide: entrez deux entiers positifs");
    c=a+b
    print("The result is %d", &c)

}






#include <stdio.h>
#include <string.h>
#include <ctype.h> // Pour les fonctions tolower() et isalnum() (si on veut ignorer la casse et la ponctuation)
#include <stdbool.h> // Pour utiliser le type booléen (True/False)

/**
 * @brief Vérifie si une chaîne de caractères (mot) est un palindrome.
 * * Un palindrome est un mot qui se lit de la même manière à l'envers
 * qu'à l'endroit.
 * * @param str La chaîne de caractères à vérifier.
 * @return true si la chaîne est un palindrome, false sinon.
 */
bool is_palindrome(const char *str) {
    if (str == NULL) {
        return false; // Cas d'une chaîne nulle
    }

    // Pointeur vers le début de la chaîne
    int left = 0;
    
    // Pointeur vers la fin de la chaîne
    // strlen(str) renvoie la longueur SANS le caractère nul (\0).
    // On retire 1 pour obtenir l'index du dernier caractère.
    int right = strlen(str) - 1;

    // Boucle tant que le pointeur de gauche n'a pas dépassé celui de droite.
    while (right > left) {
        // --- Étape optionnelle (gestion des espaces/ponctuations/casse) ---
        // Pour un test simple sur un mot pur, on peut ignorer cette étape.
        // Si on veut ignorer les caractères non-alphanumériques (ponctuation, espace):
        /*
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        while (left < right && !isalnum(str[right])) {
            right--;
        }
        */

        // --- Comparaison ---
        
        // Comparaison simple des caractères :
        // if (str[left] != str[right]) {
        
        // Comparaison IGNORANT la casse (conversion en minuscule avant comparaison) :
        if (tolower(str[left]) != tolower(str[right])) {
            return false; // Les caractères ne correspondent pas : ce n'est pas un palindrome
        }

        // Déplacement des pointeurs
        left++;
        right--;
    }

    // Si la boucle s'est terminée sans trouver de différence, c'est un palindrome.
    return true;
}

int main() {
    // Déclaration des mots à tester
    char word1[] = "Kayak";      // Palindrome, mais avec casse mélangée
    char word2[] = "Bonjour";    // Non-palindrome
    char word3[] = "ressasser";  // Palindrome
    char word4[] = "A man, a plan, a canal: Panama"; // Palindrome complexe (si on gère les espaces/ponctuations)

    // Test des mots
    printf("Mot: \"%s\" -> Palindrome: %s\n", word1, is_palindrome(word1) ? "Oui" : "Non");
    printf("Mot: \"%s\" -> Palindrome: %s\n", word2, is_palindrome(word2) ? "Oui" : "Non");
    printf("Mot: \"%s\" -> Palindrome: %s\n", word3, is_palindrome(word3) ? "Oui" : "Non");
    
    // Pour que word4 fonctionne comme palindrome, il faudrait décommenter
    // les blocs d'ignorance des caractères non-alphanumériques dans la fonction is_palindrome.
    printf("Mot: \"%s\" -> Palindrome: %s\n", word4, is_palindrome(word4) ? "Oui" : "Non");
    
    // Test d'une chaîne vide
    char empty[] = "";
    printf("Mot: \"%s\" -> Palindrome: %s\n", empty, is_palindrome(empty) ? "Oui" : "Non");

    return 0;
}





int mean () {
    int n;
    printf("Choose the number N of notes you want to enter");
    scanf("%d", &n);
    notes=(int*)malloc(n*sizeof(int));
    printf("Enter N notes(integers)");
    scanf("%d", &notes);
    int mean=0;
    for (i=0, i<n, i++) {
        printf("Note i: notes[i]");
        mean=mean+notes[i];
    }
    return mean;
    return 0;
}
#include <stdio.h>
#include <stdlib.h> // Pour malloc et free

/**
 * @brief Calcule la moyenne arithmétique de N notes saisies par l'utilisateur.
 * * @return int Le statut de sortie du programme (0 en cas de succès, 1 en cas d'erreur).
 */
int main() {
    int n;
    printf("Choisissez le nombre N de notes a saisir : ");
    // Lecture du nombre d'éléments
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Erreur: Veuillez entrer un nombre valide et positif de notes.\n");
        return 1;
    }
    int *notes; 
    notes = (int*)malloc(n * sizeof(int));
    if (notes == NULL) {
        printf("Erreur: Echec de l'allocation de memoire (malloc).\n");
        return 1;
    }

    // Déclaration des variables de calcul
    long long sum = 0; // Utiliser long long pour la somme afin d'éviter les débordements (overflow)
    int i; 
    printf("--- Entrez les %d notes (entiers) ---\n", n);
    
    // 4. Boucle de lecture : Lit chaque note une par une
    for (i = 0; i < n; i++) {
        printf("Note %d : ", i + 1);
        
        // Lecture de l'entier dans l'adresse de la case notes[i]
        if (scanf("%d", &notes[i]) != 1) {
            printf("Erreur de saisie. Veuillez entrer un nombre.\n");
            // Libération et sortie en cas d'erreur de lecture
            free(notes); 
            return 1;
        }
        
        // Ajout de la note lue a la somme
        sum += notes[i]; 
    }
    // 5. Calcul de la moyenne (convertie en double pour précision)
    double mean = (double)sum / n;
    // 6. Affichage du résultat
    printf("------------------------------------------\n");
    printf("La somme totale des notes est : %lld\n", sum);
    printf("La moyenne des %d notes est : %.2f\n", n, mean); // Affichage a 2 chiffres après la virgule
    printf("------------------------------------------\n");
    // 7. Libération de la mémoire
    free(notes);   
    return 0;
}
//notes in memory could be used as a list
void fizzbuzz() {
    for (int i=1; i<=100; i++) {
        if (i%15==0) {
            printf("FizzBuzz\n");
        }
        else if (i%3==0) {
            printf("Fizz\n");
        }
        else if (i%5==0) {
            printf("Buzz\n");
        }
        else {
            printf("\n");
        }
    }
}
int main() {
    printf("--- Execution du FizzBuzz (1 a 100) ---\n\n");
    fizzbuzz();
    printf("\n--- Fin du programme ---\n");
    return 0;
}
long long factorial_iterative(int n) {
    if (n<0) {
        printf("Error");
        return -1;
    }
    if (n==0 || n==1) {
        return 1;
    } 

    long long product=1;
    for (int i=1; i<=n; i++) {
        product=(long long)i*product;
    }
        if (product<0 && i>1) {
            printf("Buffer overflow");
            return -2;
        }
    printf("The factorial of n is %d", &product);
    return product;
    //return 0; is used only for the main function
}
int main() {
    int num=10;
    long long result1=factorial_iterative(num);
    if (result1 > 0) {
        printf("Factorial of %d is : %lld\n", num, result1);
    }
    int large_num=20;
    long long result2=factorial_iterative(large_num);
    if (result2>0) {
        printf("Factorial of %d is %lld\n", large_num, result2);
    }
    return 0;
}










#include <stdio.h>
#include <string.h>
#include <ctype.h> // Pour la fonction tolower()
#define MAX_SIZE 100

/**
 * @brief Compte le nombre de voyelles (a, e, i, o, u) dans une chaine.
 *
 * @param str La chaine de caracteres a analyser.
 * @return int Le nombre total de voyelles trouvees.
 */
int count_vowels(const char *str) {
    int count = 0; 
    // Verifie si la chaine est NULL pour eviter une erreur (bonne pratique).
    if (str == NULL) {
        return 0;
    }
    // Boucle qui itere sur chaque caractere de la chaine jusqu'a la fin du NULL (\0).
    for (int i = 0; str[i] != '\0'; i++) {
        
        // Convertit le caractere actuel en minuscule.
        // C'est crucial pour ne tester que 'a', 'e', 'i', 'o', 'u'
        // au lieu de tester 'a', 'A', 'e', 'E', etc.
        char c = tolower(str[i]); 
        // Verifie si le caractere est une voyelle en minuscule.
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    // Declaration du tableau de caracteres (la chaine)
    char user_string[MAX_SIZE];
    printf("--- Compteur de Voyelles ---\n");
    printf("Entrez un mot ou une phrase (max %d caracteres) : \n", MAX_SIZE - 1);    
    // Utilisation de fgets pour lire la ligne entiere, y compris les espaces,
    // de maniere plus sure que scanf, et evite les debordements de tampon (buffer overflow).
    // fgets ajoute un caractere de nouvelle ligne (\n) s'il y a de la place.
    if (fgets(user_string, MAX_SIZE, stdin) == NULL) {
        printf("Erreur de lecture de l'entree.\n");
        return 1;
    }

    // Supprime le caractere de nouvelle ligne ('\n') ajoute par fgets
    // si l'utilisateur n'a pas depasse la taille maximale.
    size_t len = strlen(user_string);
    if (len > 0 && user_string[len - 1] == '\n') {
        user_string[len - 1] = '\0';
    }

    // Appel de la fonction de comptage
    int total_vowels = count_vowels(user_string);

    printf("\n-------------------------------------------------\n");
    printf("Analyse de la chaine: \"%s\"\n", user_string);
    printf("Nombre total de voyelles trouvees : %d\n", total_vowels);
    printf("-------------------------------------------------\n");
    return 0;
}









#include <stdio.h>

int main() {
    // 1. Déclaration du tableau de pointeurs de caractères (chaînes)
    // char *noms[] : C'est un tableau dont chaque élément est un pointeur vers un 'char'.
    // Les chaînes de caractères ("Alice", "Bob", ...) sont stockées ailleurs en mémoire,
    // et ce tableau stocke leurs adresses.
    // Le dernier élément (NULL) sert de marqueur de fin de tableau.
    char *noms[] = {"Alice", "Bob", "Charlie", "Diana", NULL};

    // 2. Déclaration du pointeur-coureur
    // runner est un pointeur qui pointe vers un élément du tableau 'noms'.
    // Puisque 'noms' contient des (char*), 'runner' doit être un (char**).
    char **runner;

    printf("--- Affichage des noms par arithmetique de pointeurs ---\n\n");
    
    // 3. Initialisation du pointeur-coureur
    // 'runner' est initialisé avec l'adresse du DEBUT du tableau 'noms'.
    // Note: 'noms' (sans crochet) est deja l'adresse du premier element.
    runner = noms;

    // 4. Boucle de parcours (Arithmétique de pointeurs)
    // La boucle continue tant que l'élément pointé par 'runner' n'est PAS NULL.
    // L'element pointe par 'runner' est une chaine (char*).
    while (*runner != NULL) {
        
        // *runner : Dereference le pointeur pour obtenir la VALEUR stockee
        //           dans la position actuelle du tableau. Cette valeur est l'adresse
        //           de la chaine ("Alice", "Bob", etc.).
        // printf("%s", ...) : Afficher une chaine a partir de son adresse.
        printf("Nom: %s\n", *runner); 

        // Arithmetique de pointeurs :
        // runner++ incremente 'runner' de sizeof(char*) octets.
        // Cela le fait pointer vers l'ELEMENT (le pointeur) suivant dans le tableau.
        runner++; 
    }

    printf("\n--- Fin du parcours ---\n");

    return 0;
}







/**
 * @brief échange les valeurs de deux entiers en utilisant
 * des pointeurs. Elle modifie les variables originales en utilisant l'opérateur 
 * de déréferencement. int *a : pointeur vers la valeur a, 
 * &a est l'adresse contenant la valeur a, *a est la valeur 
 * stockée en &a et pointée par int* a
 */
void swap(int* a, int* b) {
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main() {
    int x=5;
    int y=10;
    printf("Before swap: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("After: x=%d, y=%d", x, y);
    return 0;
}


#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int index(char c) {
    int a; //comme a nest pas initialisée, si a n'est pas affecté d'un resultat, return a crash, il faut dire int a=0;
    int c_lower;
    char s[27]; //26lettres + '\0' = 27
    int i=0;
    c_lower=tolower(c);
    strcpy(s, "abcdefghijklmnopqrstuvwxyz");  //*s="..." will store the whole string in the first place of the table
    if (c_lower < 'a' || c > 'z') {
            printf("Enter a character among the 26 characters of the alphabet");
            return 1;
        }
    for (i=0; i<strlen(s); i++) {              
        if (c==s[i]) {                        
            a=i;
        }
    }
    return a;
}
bool is_anagram(char* s, char* t) {
    int i=0;
    int j=0;
    int c;
    int c_index;
    int ce;
    int ce_index;
    int l=0;
    if (strlen(s)!=strlen(t)) {
        printf("Error");
        return false;
    }
    int n=strlen(s);
    int frequency[26]={0};
    for (i=0; i<n; i++) {
        c=tolower(s[i]);
        c_index=index(c);
        frequency[c_index]=frequency[c_index]+1;
    }
    for (j=0; j<n; j++) {
        ce=tolower(t[j]);
        ce_index=index(ce);
        frequency[ce_index]=frequency[ce_index]-1;
    }
    for (l=0; l<26; l++) {
        if (frequency[l]!=0) {
            return false;
    }
    
}
    return true;
}
int main() {
    char s[50];
    char t[50];
    bool result;
    printf("Enter two words: ");
    scanf("%s", s);
    scanf("%s", t);

    result=is_anagram(s, t);
    return 0;
}
/*  i write two helpers functions, one to know if each character in one word is inside another word and one to know 
if frequency of characters is the same on both words.
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if s[i]!=t[j];
                return False
        }
    }
    return True
}





On passe en argument la référence si on veut modifier la variable, si la taille est inconnue, elle est dans ce cas typée.
On donne un copie aussi typée si on veut juste lire la valeur sans manipulation ou modification. Pour des tableaux ou des 
ensembles importants de données, on utilise const char* s, const char* t. 
En C, le type de données char est techniquement un type de nombre entier de petite taille. Lorsque vous utilisez des 
caractères dans des opérations mathématiques, le compilateur les traite en utilisant leur valeur numérique correspondante 
selon le standard ASCII (ou Unicode dans des contextes plus modernes). L'opération c_lower - 'a' est une opération 
arithmétique. Par défaut, en C, toute opération arithmétique impliquant de petits types entiers (comme char ou short) est 
automatiquement promue au type int pour garantir l'exactitude des calculs.

C'est ce qu'on appelle la Promotion Entière (Integer Promotion). Le résultat de la soustraction est donc bien un entier.
En C, une chaîne de caractères (comme "bonjour") est stockée dans un tableau de caractères (char[]). Comme tous les 
tableaux en C, le décompte des éléments (l'indexation) commence toujours à zéro (0).
En C, la chaîne "bonjour" occupe 8 cases mémoire (7 lettres + \0). La fonction strlen() retourne 7 (elle ignore le \0), 
*et l'index maximum utilisable est toujours 6.
Puisque les chaînes sont des tableaux terminés par un \0, vous devez parcourir la chaîne et appliquer la fonction 
tolower() à chaque caractère individuel.
C'est exactement ce que nous avons fait pour normaliser les caractères dans la fonction get_index du fichier 
anagram_checker.c.
*/







