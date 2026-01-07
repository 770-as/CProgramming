#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char[512] filename;
int NumberOfStudent;

printf("Enter a filename: ");
scanf("%c",&filename);
printf("Enter the number of students: ");
scanf("%d",&NumberOfStudent);
typedef struct {
    char Name[50];
    int Grade;
} Student;
for (i=0, i<NumberOfStudent, i++) {
    char name;
    int grade;
    struct Student studenti;
    printf("Enter the name and the grade of the %d-th student: ", i);
    fgets(studenti.Name, sizeof(studenti.Name), stdin);
    studenti.Name[strcspn(studenti.Name, "\n")]=0;
    fgets(studenti.Grade, sizeof(studenti.Grade), stdin);
    studenti.Grade[strcspn(studenti.Grade, "\n")]=0;
}
fopen(const char* filename, const char* mode)









