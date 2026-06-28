
#if !defined(FUNC)
#define FUNC

void exec_pfils(int nb_cmd,int c, char **argv);
void exec_pipe(char **argv, int c);
void exec_red(char **argv, int c);
void e_execvp(char **argv, int c);
void exec_chdir(char **argv, char *rep);
char print_history(char history[10][10], int *pos);
char exec_cmd(char **argv, char history[10][10], char *command, int *pos, char *rep, int c);
char small_lex(char *command, char **argv);
void exec_isig();
void shell();

#endif // FUNC
