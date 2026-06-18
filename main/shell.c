#include "lib.h"
#include "f.h"

// shell
void shell(char **argv)
{
    int bool = 1;
    int pos = 0; // position of each character string in the argv array
    char history[10][10];
    char *line; // this pointer points to a single memory cell

    while (bool)
    {
        line = readline("root@mini-shell:~$ "); // displays the prompt and properly retrieves the line

        if(!line){ // If the line is empty, we stop
            break; // with break
        } 
        if (*line) {
            add_history(line); // enables the up/down arrow keys
        }
        cutchar(line, argv);
        cmd(argv, history, line, &pos);
        
        free(line);
    }
}