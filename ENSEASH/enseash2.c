#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void prompt(){
     char *prompt = " ./enseash%";
      write(STDOUT_FILENO , prompt, strlen(prompt));
}

void execute (char *cmde){
       /* 
          lecture  de la commande
         */
       char buffer[64];
        int n_oct = read(STDIN_FILENO, buffer, 64);
        char *commande = malloc((n_oct - 1)*sizeof(char));
         strncpy(commande, buffer, n_oct - 1);
          /*
          child process with the parent being the terminal of the VM and the child being enseash
          */
         pid_t    pid;
         int status;
          pid = fork();
          if (pid != 0) {
                                    wait(&status);
                                     } 
                                     else
                                      {
                                       execlp(commande, commande, NULL);
                                       }
}

int main(){
             char commande[64];
             while(1){
                               prompt();
                                execute(commande);
                                }
                   exit(EXIT_SUCCESS);
}




         
         
         

      











