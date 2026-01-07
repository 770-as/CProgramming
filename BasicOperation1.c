#include <stdio.h>
#include <stdlib.h>
// Function prototypes
int add_integers(int nombreA, int nombreB);
int subtract_integers(int nombreA, int nombreB);
int multiply_integers(int nombreA, int nombreB);
int divide_integers(int nombreA, int nombreB);

int add_integers(nombreA, nombreB)
{
    int resultat = nombreA*nombreB;
    return resultat;
}
int subtract_integers(nombreA, nombreB)
{
    int resultat = nombreA*nombreB;
    return resultat;
}
int multiply_integers(nombreA, nombreB)
{
    int resultat = nombreA*nombreB;
    return resultat;
}
int divide_integers(nombreA, nombreB)
{
    int resultat = nombreA*nombreB;
    return resultat;
}
int main() {
    printf("Enter two integers: ");
    int a, b, c, d;
    scanf(" %d%d", &a, &b);
    printf("What operation do you want to perform ? addition:1, subtracting:2, multiplication:3, division:4 ");
    scanf(" %d", &c);
    switch (c)
    {
        case 1:
            d=add_integers(a,b);
            printf("The result is %d", &d);
            break;
        case 2:
            d=subtract_integers(a,b;)
            printf("The result is %d", &d);
            break;
        case 3:
            d=multiply_integers(a,b);
            printf("The result is %d", &d);
            break;
        case 4:
            d=divide_integers(a,b);
            printf("The result is %d", &d);
            break;
    }
    return 0;

}



