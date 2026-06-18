#include "lib.h"
#include "f.h"

// Function to execute the command
char e_execvp(char **argv) 
{
    __pid_t pid;

    // int status;

    do {
        pid = fork(); // fork() may fail temporarily due to insufficient resources, so it is advisable to retry in that case
    } while ((pid == -1) && (errno == EAGAIN)); // EAGAIN: Temporary resource shortage to create a child process, retry   

    if (pid == -1) // fork() failed after several attempts
    {
        fprintf(stderr, "Process forking error\n");
        exit(1);
    }

    if (pid == 0)
    {
        // if ((argv == NULL || argv[0] == NULL))
        // {
        //     exit(0);
        // }
        if (execvp(argv[0], argv) == -1) 
        {
            perror("Error executing command"); 
            exit(1);
        }
        exit(0);

    } else {
        waitpid(pid, NULL /*&status*/, 0); // wait for the child process to finish before continuing
    }

    // if(WIFEXITED(status)) 
    // {
    //     fprintf(stdout,"Process %ld terminated with return code %d\n", (long)pid, WEXITSTATUS(status));
    // } else if (WIFSIGNALED(status)) {
    //     fprintf(stdout,"Process %ld terminated due to signal %d\n", (long)pid, WTERMSIG(status));
    // } else if (WIFSTOPPED(status)) {
    //     fprintf(stdout,"Process %ld stopped temporarily with code %d\n", (long)pid, WSTOPSIG(status));
    // }

    return 0;
}