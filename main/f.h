#if !defined(f)
#define f

void shell(char **argv);
char cmd(char **argv, char history[10][10], char *command, int *pos);
char cutchar(char *command, char **argv);
char e_execvp(char **argv);
char print_history(char history[10][10], int *pos);


#endif // f



