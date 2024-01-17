#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void welcome(){
     char *str = "$ ./enseash\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n";
      write(STDOUT_FILENO , str, strlen(str));
}


void prompt(){
     char *prompt = " ./enseash%";
      write(STDOUT_FILENO , prompt, strlen(prompt));
}


/*
Display bye bye
*/

void shell_exit(){
          char *ex = "Bye bye...\n";
          write(STDOUT_FILENO, ex, strlen(ex));
          exit(EXIT_SUCCESS);
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

           shell_exit(commande);

          child process with the parent being the terminal of the VM and the child being enseash
          */
         pid_t    pid;
         int status;
          pid = fork();
          if (pid != 0) {
                                   printf("%d\n",pid);
				char *prompt=malloc(20*sizeof(char));
                                    wait(&status);
                                    if (WIFEXITED(status)){
                                                                                      sprintf(prompt, "exit : %d\n" , WEXITSTATUS(status));
                                                                                       }
                                     else  if (WIFSIGNALED(status)){
                                                                                              sprintf(prompt, "sign : %d\n" , WTERMSIG(status));
                                                                                               }
                                      write(STDOUT_FILENO, prompt, strlen(prompt));
                                     } 
                                     else
                                      {
                                       sleep(15);
                  
                                       execlp(commande, commande, NULL);
                                       exit(5);
                            
                                       }
     if (strncmp(commande, "exit", 4)==0){
                                                                                          shell_exit();
     }
     free(commande);
}

int main(){
             welcome();
             char commande[64];
             while(1){
                               prompt();
                                execute(commande);
                                }
                   exit(EXIT_SUCCESS);
}




         
         
         

      
