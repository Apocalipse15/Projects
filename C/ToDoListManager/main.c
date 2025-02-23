int main(void){
    // Code
    printf("Welcome to a simple To Do List Manager\n");
    printf("Commands:\n");
    printf("add <task>: Add a new task to the list\n");
    printf("remove <task number>: Delete a task from the list\n");
    printf("done <task number>: Put the task in the group of done taks\n");
    printf("list: List all active tasks\n");
    printf("listold: List all old/done tasks\n");
    printf("exit: Exit the program\n");


    while (1) {
        char command[1024];
        scanf("%s", command);

        char firstWord[] = strtok(command, " ,.!?");  // Delimiters: space, comma, period, exclamation mark, question mark

        if (firstWord != NULL) { 
            printf("The first word is: %s\n", firstWord); 
        } else { 
            printf("No word found.\n"); 
        } 

    }


    return 0;
}

