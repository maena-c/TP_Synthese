#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void main(){
     char *str = "$ ./enseash\nBienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n";
      write(STDOUT_FILENO , str, strlen(str));
}

