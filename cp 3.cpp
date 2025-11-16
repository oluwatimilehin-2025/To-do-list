#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char task[100];
    int choice;

    do {
        printf("\n=== TO-DO LIST ===\n");
        printf("1. Add Task\n2. View Tasks\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter task: ");
            scanf(" %[^\n]", task);
            file = fopen("tasks.txt", "a");
            if(file != NULL) {
                fprintf(file, "%s\n", task);
                fclose(file);
                printf("Task added!\n");
            }
        } else if(choice == 2) {
            char line[100];
            file = fopen("tasks.txt", "r");
            if(file != NULL) {
                printf("\n--- TASKS ---\n");
                while(fgets(line, sizeof(line), file)) {
                    printf("%s", line);
                }
                fclose(file);
            } else {
                printf("No tasks found!\n");
            }
        } else if(choice != 3) {
            printf("Invalid choice!\n");
        }
    } while(choice != 3);

    return 0;
}
