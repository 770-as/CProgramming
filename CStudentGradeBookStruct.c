#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student data.
typedef struct {
    char name[50];
    int grade;
} Student;

int main() {
    FILE *file_ptr;
    char filename[256];
    int num_students;
    double total_grade = 0.0;

    // --- PART 1: WRITING TO A FILE ---

    printf("--- Student Gradebook Challenge ---\n");
    printf("Enter a filename for the gradebook: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        printf("Error reading filename.\n");
        return 1;
    }
    // Remove the newline character from the filename string.
    filename[strcspn(filename, "\n")] = 0;

    printf("Enter the number of students: ");
    // Use scanf to read the number of students.
    if (scanf("%d", &num_students) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }
    // Consume the remaining newline character from the input buffer
    // left by scanf to prevent issues with subsequent fgets calls.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Open the file in write mode to create or overwrite it.
    file_ptr = fopen(filename, "w");
    if (file_ptr == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Loop for each student to get name and grade.
    for (int i = 0; i < num_students; i++) {
        Student current_student;
        
        printf("\nEnter name for student %d: ", i + 1);
        if (fgets(current_student.name, sizeof(current_student.name), stdin) == NULL) {
            printf("Error reading student name.\n");
            fclose(file_ptr);
            return 1;
        }
        current_student.name[strcspn(current_student.name, "\n")] = 0;

        printf("Enter grade for student %d: ", i + 1);
        if (scanf("%d", &current_student.grade) != 1) {
            printf("Invalid input. Please enter a number.\n");
            fclose(file_ptr);
            return 1;
        }
        while ((c = getchar()) != '\n' && c != EOF); // Consume newline

        // Write the student's data to the file.
        fprintf(file_ptr, "%s: %d\n", current_student.name, current_student.grade);
    }

    printf("\nSuccessfully wrote all student data to '%s'\n\n", filename);
    fclose(file_ptr);

    // --- PART 2: READING FROM THE FILE AND CALCULATING AVERAGE ---

    printf("--- Reading from file and calculating average ---\n");
    // Re-open the file in read mode.
    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // Read and parse the data line by line.
    int students_read = 0;
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        Student s;
        // sscanf is used here for parsing, which is safe for this formatted input.
        if (sscanf(buffer, "%[^:]:%d", s.name, &s.grade) == 2) {
            printf("Read: Name = %s, Grade = %d\n", s.name, s.grade);
            total_grade += s.grade;
            students_read++;
        }
    }

    // Calculate and display the average grade.
    if (students_read > 0) {
        printf("\nAverage Grade: %.2f\n", total_grade / students_read);
    } else {
        printf("\nNo student data was found in the file.\n");
    }

    fclose(file_ptr);

    return 0;
}
