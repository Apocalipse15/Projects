#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Task {
    char *name; // Defualt size of 1024
    int done;
    struct Task *next;
};

int getNumberTasks() {
    return 0;
}

struct Task *getTasksArray() {
    // First Version - creates a new array each time.
    return NULL;
}

// LinkedList functions
void append(struct Task** head, char* name) {
    struct Task* newTaks = malloc(sizeof(struct Task));
    newTaks->name = name;
    newTaks->done = 0;
    newTaks->next = NULL;

    if (*head == NULL) {
        *head = newTaks;
        return;
    }
    
    struct Task* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newTaks;
}

void removeNode(struct Task **head, char* name) {
    struct Task *temp = *head, *prev = NULL;

    if (temp != NULL && temp->name == name) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", name);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
}

int main(void){
    // Initialize the list of tasks or read it (depends if it's already saved)
    //int numTasks = getNumberTasks();
    struct Task *head = getTasksArray();
    
    printf("Welcome to a simple To Do List Manager\n");
    printf("Commands:\n");
    printf("add <task>: Add a new task to the list\n");
    printf("remove <task number>: Delete a task from the list\n");
    printf("done <task number>: Put the task in the group of done taks\n");
    printf("list: List all active tasks\n");
    //printf("listold: List all old/done tasks\n");
    printf("exit: Exit the program\n");
    printf("Please enter a command:\n");

    while (1) {
        char *buffer = (char*)malloc(1024 * sizeof(char));
        char *command = (char*)malloc(1024 * sizeof(char));
        fgets(buffer, 1024, stdin);
        strcpy(command, buffer);
        
        char *firstWord = strtok(buffer, " ,.!?");

        if (firstWord != NULL) { 
            printf("The first word is: %s\n", firstWord); 
        } else { 
            printf("No word found.\n"); 
        }
        
        if (strcmp(firstWord, "add") == 0) {
            printf("Adding a new task\n");
            printf("The task is: %s\n", command + strlen(firstWord) + 1);
            append(&head, command + strlen(firstWord) + 1);
        }
        else if (strcmp(firstWord, "remove") == 0) {
            printf("Removing task: %s\n", command + strlen(firstWord) + 1);
            removeNode(&head, command + strlen(firstWord) + 1);
        }
        else if (strcmp(firstWord, "done") == 0) {
            printf("Marking a task as done\n");
        }
        else if (strcmp(firstWord, "list\n") == 0) {
            printf("Listing all active tasks\n");
            struct Task* temp = head;
            while (temp) {
                printf("Name: %s", temp->name);
                printf("Done: %d\n", temp->done);
                printf("---------------------------------\n");
                temp = temp->next;
            }
        }
        else if (strcmp(firstWord, "listold") == 0) {
            printf("Listing all old/done tasks\n");
        }
        else if (strcmp(firstWord, "exit") == 0) {
            printf("Exiting the program\n");
            break;
        }
        else {
            printf("Invalid command\n");
        }

        free(buffer);
        
    }


    return 0;
}


