#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    // probleme rencontrer:
    /*  argv est une variable de type tableau de pointeur de char, pour l'utiliser avec la saisie au clavier on doit definir
        Sa taille puis affecter la commande saisie au clavier et dois toujour se terminer par un pointeur NULL
        exemple: argv[0] = commande;  // ou argv[0] = &commande[0];  // ou argv[0] = (char *)commande;
                 argv[1] = NULL;

        NB: Bad address error: se produit lorsque l'adresse de la commande saisie n'est pas correctement référencée dans le tableau argv, 
            ce qui peut entraîner une tentative d'accès à une adresse mémoire invalide lors de l'exécution de la commande avec execvp().
    */
    
    // Saisie une chaine
    // lire la ligne
    // executer la commande

    char commande[10];

    int pos = 0; // position de chaque chaine de caracère dans le tableau argv

    printf("root@mini-shell:~$ ");
 
    fgets(commande, sizeof(commande), stdin); // saisie une commande au clavier par l'utilisateur

    char *argv[10];
    char *token = strtok(commande, " \t\n");


    while (token != NULL) {

        argv[pos] = token;
        pos++;
        token = strtok(NULL, " \t\n"); // on ignore les tabulations et saut de ligne avec \0 (fin de la chaine)
    }
    argv[pos] = NULL; // on termine le tableau argv par un pointeur NULL pour indiquer la fin du tableau

    __pid_t pid;

    do {
        pid = fork(); // fork() peut échouer temporairement en raison de ressources insuffisantes, il est donc recommandé de réessayer dans ce cas
    } while ((pid == -1) && (errno == EAGAIN)); // EAGAIN: Ressources temporaires insuffisantes pour créer un processus enfant, réessayer   

    if (pid == -1) // échec de fork() après plusieurs tentatives
    {
        fprintf(stderr, "¨Proccess forking error¨");
        exit(1);
    }

    if (pid == 0)
    {
        if(execvp(argv[0], argv)==-1) { // execvp() retourne -1 en cas d'erreur, et errno est défini pour indiquer l'erreur spécifique
            perror("Error executing command"); 
            exit(1);
        }
    } else {
        wait(NULL); // attendre que le processus enfant se termine avant de continuer
    }
    
    return 0;
}
