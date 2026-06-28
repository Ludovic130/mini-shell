#include "lib.h"
#include "func.h"

void exec_isig()
{
    if(signal(SIGINT, SIG_IGN) == SIG_ERR)  // Ignore SIGINT signal when pressing Ctrl+C 
    {
        fprintf(stderr, "signal non capturé");
    }
}