#include "lib.h"
#include "func.h"

char exec_cmd(char **argv, char history[10][10], char *command, int *pos, char *rep, int c)
{
    // The input string needs to be processed with strcspn to convert newlines into null terminators
    command[strcspn(command, "\n")] = '\0';

    strcpy(history[*pos], command); // copy the command into history[*pos] using strcpy
    (*pos)++;

    if((argv[0] != NULL) && (strcmp(argv[0],"cd") == 0)) 
    {
        exec_chdir(argv, rep);
    } 
    else if ((argv[0] != NULL) && (strcmp(argv[0], "exit") == 0))
    {
        exit(0);
        perror("exit"); // Translated from "problèms" (Note: this line is never reached because exit(0) is called just before)
    }
    else if ((argv[0] != NULL) && (strcmp(argv[0], "history") == 0))
    {
        print_history(history, pos); // call the print_history function to display the command history
    } else if (argv[0] != NULL) 
    {
        e_execvp(argv, c);
    }

    return 0;
}