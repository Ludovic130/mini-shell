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
                perror("Echec");
            }
        } else { // if chdir is -1 display the error
            fprintf(stderr, "erreur de changement de repertoire\n"); 
        }
    } else { // otherwise if argv[1] == NULL 
        if(chdir("/root") == 0) // change directory to root with chdir()
        {
            if (getcwd(rep, 1024) == NULL) // get its directory if NULL
            {
                fprintf(stderr, "Echec de l'obtention du répertoire courant\n");
            }
        } else {
            fprintf(stderr, "erreur de changement de repertoire\n");
        }
    }
}