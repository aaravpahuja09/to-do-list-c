#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int task_count = 0;
    int choice;

    do {
        printf("\n--- TO-DO LIST ---\n");
        printf("1. View Tasks\n");
        printf("2. Add Task\n");
        printf("3. Complete / Remove Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        getchar();

        switch (choice) {
            case 1:
                if (task_count == 0) {
                    printf("\nYour to-do list is currently empty.\n");
                } else {
                    printf("\nYour Tasks:\n");
                    for (int i = 0; i < task_count; i++) {
                        printf("%d. %s\n", i + 1, tasks[i]);
                    }
                }
                break;

            case 2:
                if (task_count < MAX_TASKS) {
                    printf("\nEnter task description: ");
                    fgets(tasks[task_count], MAX_LENGTH, stdin);
                    tasks[task_count][strcspn(tasks[task_count], "\n")] = '\0';
                    task_count++;
                    printf("Task added successfully!\n");
                } else {
                    printf("\nTask list is full!\n");
                }
                break;

            case 3:
                if (task_count == 0) {
                    printf("\nThere are no tasks to complete!\n");
                } else {
                    printf("\nYour Tasks:\n");
                    for (int i = 0; i < task_count; i++) {
                        printf("%d. %s\n", i + 1, tasks[i]);
                    }

                    int task_num;
                    printf("Enter the task number you want to complete and remove: ");
                    if (scanf("%d", &task_num) == 1) {
                        getchar();
                        
                        if (task_num >= 1 && task_num <= task_count) {
                            int index = task_num - 1;
                            printf("Completed & removed: \"%s\"\n", tasks[index]);

                            for (int j = index; j < task_count - 1; j++) {
                                strcpy(tasks[j], tasks[j + 1]);
                            }
                            task_count--;
                        } else {
                            printf("Invalid task number entered!\n");
                        }
                    } else {
                        printf("Invalid input.\n");
                        getchar();
                    }
                }
                break;

            case 4:
                printf("\nExiting... Good luck with your tasks!\n");
                break;

            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}our