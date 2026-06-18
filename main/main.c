#include "lib.h"
#include "f.h"


int main(void)
{
    // issue encountered:
    /*  argv is a variable of type array of pointers to char. To use it with keyboard input, we must define
        its size, then assign the command entered at the keyboard, and it must always end with a NULL pointer.
        example: argv[0] = command;  // or argv[0] = &command[0];  // or argv[0] = (char *)command;
                 argv[1] = NULL;

        NB: Bad address error: occurs when the address of the entered command is not correctly referenced in the argv array,
            which can lead to an attempt to access an invalid memory address when executing the command with execvp().
    */
    // Read a string
    // read the line
    // execute the command

    char *argv[10];
    shell(argv); // shell

    return 0;
}