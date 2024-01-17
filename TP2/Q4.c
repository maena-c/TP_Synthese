#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>




void buildRRQPacket(const char *filename, const char *mode, char *rrqPacket) {

                                                                                                                                                                                   uint16_t opcode = htons(1);  // 1 pour RRQ
                                                                                                                                                                                   
                                                                                                                                                                                   strcpy(rrqPacket, (char *)&opcode);
                                                                                                                                                                                   strcat(rrqPacket, filename);
                                                                                                                                                                                   strcat(rrqPacket, "\0");
                                                                                                                                                                                   strcat(rrqPacket, mode);
                                                                                                                                                                                   strcat(rrqPacket, "\0");

   
                                                                                                                                                                                  }






int getaddrinfo(const char *node, const char *service,
        const struct addrinfo *hints, struct addrinfo **res);

#define MAX_BUFFER_SIZE 516


int main(int argc, char *argv[]) {

                        const char *hostname = "srvtpinfo1.ensea.fr";
                       const char *port = "1069";
                        struct addrinfo hints, *res;
                        memset(&hints, 0, sizeof hints);
                     //   hints.ai_family  = AF_UNSPEC;
                        //hints.ai_socktype  = SOCK_STREAM;
                        

                        
                        int status = getaddrinfo(hostname, NULL, &hints, &res);
                       if (status != 0){
                                                       fprintf(stderr,"getaddrinfo error : %s\n", gai_strerror(status));
                                                       exit(EXIT_FAILURE);
                                                      }
                    // création du socket qui se nommera sock

                    int sock = socket(res->ai_family,res->ai_socktype, res->ai_protocol);
                     if (sock == -1){
                                                   perror ("socket");
                                                      exit(EXIT_FAILURE);
                                                    }
 
                 

             printf("Connexon réussie\n");

              // request RQQ construction

               char rrqPacket[MAX_BUFFER_SIZE];
                buildRRQPacket(argv[2], "octet", rrqPacket);

                 //send request
           
               ssize_t sentBytes = sendto("octet", rrqPacket, strlen(rrqPacket), 0,  res->ai_addr, res->ai_addrlen);
printf("abc\n");
               if (sentBytes<0){
                                                    perror("erreur envoi\n");
                                                  
                                                    freeaddrinfo(res);
                                                    exit(EXIT_FAILURE);
                                                 }

                printf("request sent\n");



             freeaddrinfo(res);
             close(sock);
            return 0;
              }




              
                 