#include "lib.h"
#include "func.h"

void exec_pfils(int nb_cmd,int c, char **argv)
{

    char **ls_cmd[nb_cmd]; // Create split commands grouped after the |
    int index = 0;
    ls_cmd[0] = argv; // position the first command argv[0]

    for (int i = 0; i < c; i++)
    {
        if ((strcmp(argv[i], "|") == 0)) 
        {
            argv[i] = NULL; // Set argv[i] which contains "|" to NULL
            index++;
            ls_cmd[index] = &argv[i+1];
        }
    }

    int num_pipes = nb_cmd - 1;
    // If num_pipes > 0 then tubes[num_pipes][2] else tubes[1][2];
    int tubes[num_pipes > 0 ? num_pipes : 1][2];
    for (int i = 0; i < num_pipes; i++)
    {
        if(pipe(tubes[i]) != 0) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    pid_t pid;

    for (int i = 0; i < nb_cmd; i++)
    {
        pid = fork();

        if(pid == -1) // If pid returns -1, send a message and exit abruptly.
        {
            perror("fork()");
            exit(1);
        } 

        if (pid == 0)
        {
             // redirect to standard output (ignore the last command).
            if (i < nb_cmd - 1)
            {
                if (dup2(tubes[i][1], STDOUT_FILENO) == -1) // duplicate the input of the tube onto the standard output
                {
                    perror("dup2 stdout");
                    exit(1);
                }
            }

            // redirect to standard input (ignore the first command).
            if (i > 0)
            {
                if(dup2(tubes[i-1][0], STDIN_FILENO) == -1) // duplicate the output of the tube onto the standard input
                {
                    perror("dup2 stdin");
                    exit(1);
                }
            }

            for (int i = 0; i < nb_cmd - 1; i++) // Close all descriptors that are in this child
            {
                close(tubes[i][0]);
                close(tubes[i][1]);
            }
            // Execute the command 
            if(execvp(ls_cmd[i][0], ls_cmd[i]) == -1)
            {
                perror("execvp");
                exit(1);
            }
        }
    }

    // We also close all descriptors of the parent
    for (int i = 0; i < nb_cmd - 1; i++)
    {
        close(tubes[i][0]);
        close(tubes[i][1]);
    }

    for (int i = 0; i < nb_cmd; i++)
    {
        if(wait(NULL) == -1) // We wait for the end of all children 
        {
            perror("wait");
            exit(1);
        }
    }
    exit(0);

}