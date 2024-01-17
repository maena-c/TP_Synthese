#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>



int getaddrinfo(const char *node, const char *service,
        const struct addrinfo *hints, struct addrinfo **res);



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
 
                  // connexion avec le serveur:

               //   if (connect(sock, res->ai_addr, res->ai_addrlen) == -1){
                   //                                                                                                                       perror ("connection");
                       //                                                                                                               exit(EXIT_FAILURE);
                           //                                                                                                            }
 
              //int sock, size;
              //struct sockaddr_in server;
              //sock = socket(AF_INET, SOCK_DGRAM, 0);
              //if (sock < 0){
                                       //     perror ("erreur de création pour le socket");
                                           //  return 1;
                                           //}
             // memset(&server, 0, sizeof(struct sockaddr_in));
              //server.sin_family = AF_INET;
            // server.sin_port = htons(*argv[4]); 
                                        
                 

             printf("Connexon réussie");

             freeaddrinfo(res);
             close(sock);
            return 0;
              }
              
                                                   


