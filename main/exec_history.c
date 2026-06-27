#include "lib.h"
#include "func.h"

// Function to display the history
char print_history(char history[10][10], int *pos)
{
    for (int i = 0; i < *pos; i++) {
        printf("%d  %s\n", i+1, history[i]); // display the command
    }

    return 0;
}