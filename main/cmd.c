#include "lib.h"
#include "f.h"

char cmd(char **argv, char history[10][10], char *command, int *pos)
{
    // The input string needs to be processed with strcspn to convert newlines into null terminators
    command[strcspn(command, "\n")] = '\0';

    strcpy(history[*pos], command); // copy the command into history[*pos] using strcpy
    (*pos)++;

    if ((argv[0] != NULL && strcmp(argv[0], "exit") == 0))
    {
        exit(0);
        perror("problèms");
    }
    else if ((argv[0] != NULL && strcmp(argv[0], "history") == 0))
    {
        print_history(history, pos); // call the print_history function to display the command history
    } else {
        e_execvp(argv);
    }

    return 0;
}