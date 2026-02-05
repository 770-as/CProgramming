#include <stdio.h>
#include <stdlib.h>
/*getch peut être utilisée dans des jeux vidéos pour maintenir la dernière image en attendant que l'utilisateur 
presse une touche pour activer getch() qui met fin au programme.*/

#include <stdio.h>
#include <conio.h> // Required for getch() on Windows

int main() {
    int v = 0;
    int displayValue = 0;
    int i;

    printf("How many times should we print? (Press a single digit 0-9): ");
    
    // getch() captures the key immediately without needing 'Enter'
    // We subtract '0' to convert the ASCII character to the actual integer
    v = getch() - '0'; 
    
    printf("\nCaptured V = %d\n", v);

    printf("Enter the number you want to display: ");
    scanf("%d", &displayValue);

    // The Loop
    for (i = 0; i < v; i++) {
        printf("%d ", displayValue);
    }

    printf("\nPress any key to exit...");
    getch(); // Used here to pause the console before it closes
    return 0;
}
