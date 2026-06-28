#include "lib.h"
#include "func.h"

// shell
void shell()
{
    char *argv[20];
    int bool = 1;
    int pos = 0; // position of each character string in the argv array
    char history[500][10];
    char *line; // this pointer points to a single memory cell
    char prompt[300];
    char rep[1024];

    exec_isig();

    while (bool)
    {
       if (getcwd(rep, 1024) != NULL)
        {
            int s = snprintf(prompt, sizeof(prompt), "Ludovic:\n~%s> ", rep); // format multiple strings
            if (s) {
                line = readline(prompt); // read the command entered by the user
            }
        } 

        if(!line){ // If the line is empty, we stop
            break; // with break
        } 
        if (*line) {
            add_history(line); // enables the up/down arrow keys
        }
        int c = small_lex(line, argv);
        exec_cmd(argv, history, line, &pos, rep, c);
        
        free(line);
    }
}