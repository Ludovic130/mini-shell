#include "lib.h"
#include "func.h"

void exec_pipe(char **argv, int c)
{
    int nb_cmd = 1;
    for (int i = 0; i < c; i++)
    {
        if ((strcmp(argv[i], "|") == 0)) // If argv[i] contains "|" which is equal to "|" 
        {
            nb_cmd++; // We add +1 to nb_cmd
        }
    }

    exec_pfils(nb_cmd, c, argv);
}