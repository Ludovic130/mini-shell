#include "lib.h"
#include "func.h"

void exec_red(char **argv, int c) 
{
    for (int i = 0 ; i < c; i++)
    {
        if ((strcmp(argv[i], ">") == 0)) 
        {
            int f = open(argv[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if(f == -1) // If it returns a negative value instead of the descriptor
            {
                perror("File descriptor error"); // Translated from "Error de descripteur de fichier"
                exit(1);
            }

            if (dup2(f, STDOUT_FILENO) == -1) // Redirect output but if the returned value is -1 
            {
                perror("Redirection error"); // Translated from "Error de redirection"
                exit(1);
            }

            close(f);
            argv[i] = NULL; // Set to NULL the symbol ">".

            break; // Exit the loop since the redirection is done.
        } else if ((strcmp(argv[i], "<") == 0)) {
            int f = open(argv[i+1], O_RDONLY, 0644);
            if(f == -1)
            {
                perror("File descriptor error");
                exit(1);
            }
            if (dup2(f, STDIN_FILENO) == -1) // Redirect output but if the returned value is -1 
            {
                perror("Redirection error");
                exit(1);
            }
            close(f);
            argv[i] = NULL; // Set to NULL the symbol "<".

            break; // Exit the loop since the redirection is done.
        } else if ((strcmp(argv[i], ">>") == 0)) {
            int f = open(argv[i+1], O_RDWR | O_CREAT | O_APPEND, 0644);
            if(f == -1)
            {
                perror("File descriptor error");
                exit(1);
            }
            if (dup2(f, STDOUT_FILENO) == -1) // Redirect output but if the returned value is -1 
            {
                perror("Redirection error");
                exit(1);
            }
            close(f);
            argv[i] = NULL; // Set to NULL the symbol ">>".

            break; // Exit the loop since the redirection is done.
        } else if ((strcmp(argv[i], "|") == 0)) {
            exec_pipe(argv, c);
        }
    }
}