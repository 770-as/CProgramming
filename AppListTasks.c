#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASK_LENGTH 100

typedef struct {
    char **tasks;//this is a pointer to a pointer to char where **tasks will point to an array of *char where each
    //*char is a pointer to a task */
    int count;
} TaskList;

void add_task(TaskList *list, const char *task) {/*takes a pointer to a task list structure as it's first argument 
    because you want to modify the tasks array and count member within the original task list structure not just as 
    a copy. and const char *task takes a pointer to a constant character array as the task to be added. const      
    indicates that the function won't modify the original task string.realloc is used to change the size of a       
    previously allocated block of memory. On the first call, list->tasks should be NULL and realloc behaves like    
    malloc*/
    list->tasks = realloc(list->tasks, (list->count + 1) * sizeof(char *));
    if (!list->tasks) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    list->tasks[list->count] = strdup(task);
    list->count++;//after having added a task, the count of tasks in list is incremented
}
/*The prototype of the realloc function is void *realloc(void *ptr, size_t size) where the realloc function returns a pointer of 
type void which will point to the newly allocated memory or will return null if allocation failed. size_t size specify the new size
in bytes for the memory block. The negation operator treats the pointer as a boolean. Since a non NULL pointer is true, a NULL pointer
is false and the negation ! turns it false. Two ways are equivalent : if (list->tasks==NULL) or if (!list->tasks)*/

void remove_task(TaskList *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid task number.\n");
        return;
    }
    free(list->tasks[index]);
    for (int i = index; i < list->count - 1; i++) {
        list->tasks[i] = list->tasks[i + 1];
    }
    list->count--;
    list->tasks = realloc(list->tasks, list->count * sizeof(char *));
}

void display_tasks(const TaskList *list) {
    if (list->count == 0) {
        printf("No tasks available.\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->tasks[i]); 
    }
}
/*the format specifier %s is used to print a string (an array of characters terminated 
by a null terminator \0). list->tasks[i] is a pointer to a string and the printf
function when it encounters %s starts reading characters from the memory
address pointed to by list->tasks[i] and continues printing them until it hits a null 
terminator \0. That's why task->list must be evaluated to a char pointer. 
*/

void free_tasks(TaskList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->tasks[i]);
    }
    free(list->tasks);
}

int main() {
    TaskList list = {NULL, 0};
    int choice;
    char task[MAX_TASK_LENGTH];

    while (1) {
        printf("\n1. Add Task\n2. Remove Task\n3. Display Tasks\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter task: ");
                fgets(task, MAX_TASK_LENGTH, stdin); 
                task[strcspn(task, "\n")] = 0;
                add_task(&list, task);
                break;
            case 2:
                printf("Enter task number to remove: ");
                int index;
                scanf("%d", &index);
                remove_task(&list, index - 1);
                break;
            case 3:
                display_tasks(&list);
                break;
            case 4:
                free_tasks(&list);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
