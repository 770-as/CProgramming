#include <stdio.h>
#include <string.h>


void display_fixed(const char *str) {
    int max_char=4;
    printf("Affichage avec 4 caractères maximum:\n");

    printf("3(a)\n");
    for (int i=0; i<max_char; i++) {
        printf("%d\n", i+1);
        for (int j=0; j<=i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("3(b)\n");
    int len=strlen(str);
    for (int i=0; i<max_char; i++) {
        printf("%d\n", i+1);
        for (int j=0; j<=i; j++) {
            printf("%c", str[len-1-j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("3(c)\n");
    for (int i=0; i<max_char; i++) {
        printf("%d\n", i+1);
        for (int j=max_char-1-i; j<max_char; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}
void display_variable(const char *str) {
    int max_char;
    printf("Entrez le nombre de caractères max à afficher: ");
    scanf("%d", &max_char);
    
    int len = strlen(str);
    if (max_char > len) {
        max_char=len;
    }
    printf("\nAffichage avec %d caractères maximum:\n", max_char);

    printf("3(a)\n");
    for (int i=0; i<max_char; i++) {
        printf("%d\n", i+1);
        for (int j=0; j<=i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("3(b)\n");
    int len=strlen(str);
    for (int i=0; i<max_char; i++) {
        printf("%d\n", i+1);
        for (int j=0; j<=i; j++) {
            printf("%c", str[len-1-j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("3(c)\n");
    for (int i=0; i<max_char; i++) {
        printf("%d\n", i+1);
        for (int j=max_char-1-i; j<max_char; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}


int main() {
    char str[] = "abcde";
    return 0;
}