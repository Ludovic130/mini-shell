#include "lib.h"
#include "func.h"

void exec_chdir(char **argv, char *rep)
{
    if (argv[1] != NULL)
    {
        if(chdir(argv[1]) == 0) // Change the current directory with chdir()
        {
            // Get the current directory
            if ((rep != NULL) && getcwd(rep, 1024) == NULL) // if NULL display the error
            {
                perror("getcwd"); // Changed from "Echec" to standard practice
            }
        } else { // if chdir is -1 display the error
            fprintf(stderr, "error changing directory\n"); // Translated
        }
    } else { // otherwise if argv[1] == NULL 
        if(chdir("/root") == 0) // change directory to root with chdir()
        {
            if (getcwd(rep, 1024) == NULL) // get its directory if NULL
            {
                fprintf(stderr, "failed to get current directory\n"); // Translated
            }
        } else {
            fprintf(stderr, "error changing directory\n"); // Translated
        }
    }
}