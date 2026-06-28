#include "lib.h"
#include "func.h"

// Function to execute the command
void e_execvp(char **argv, int c) 
{
    __pid_t pid; // Create variable to store the child pid

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
        signal(SIGINT, SIG_DFL);
        exec_red(argv, c);
        if(execvp(argv[0], argv) == -1) { // execvp() returns -1 on error, and errno is set to indicate the specific error
            perror("Error executing command"); 
            exit(1);
        }
    } else {
        if(waitpid(pid, NULL, 0) == -1) // wait for the child process to finish before continuing
        {
            perror("waitpid");
            exit(1);
        }
    }

    // if(WIFEXITED(status)) 
    // {
    //     fprintf(stdout,"Process %ld terminated with return code %d\n", (long)pid, WEXITSTATUS(status));
    // } else if (WIFSIGNALED(status)) {
    //     fprintf(stdout,"Process %ld terminated due to signal %d\n", (long)pid, WTERMSIG(status));
    // } else if (WIFSTOPPED(status)) {
    //     fprintf(stdout,"Process %ld stopped temporarily with code %d\n", (long)pid, WSTOPSIG(status));
    // }

}