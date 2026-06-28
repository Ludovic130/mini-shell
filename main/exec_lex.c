#include "lib.h"
#include "func.h"

// function to parse the string by removing spaces and other whitespace characters
char small_lex(char *command, char **argv)
{
    int i = 0;
    char *token = strtok(command, " \t\n\r");

    while (token != NULL) {
        argv[i] = token;
        i++;
        token = strtok(NULL, " \t\n\r"); // ignore tabs and newlines, replaced by \0 (end of string)
    }
    argv[i] = (char *) NULL; // terminate the argv array with a NULL pointer to indicate the end of the array

    return i;
}