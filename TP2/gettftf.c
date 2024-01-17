#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 516

void error(char *msg){
                                                perror(msg);
                                                exit(EXIT_FAILURE);
                                                 }


int getaddrinfo(const char *node, const char *service,
        const struct addrinfo *hints, struct addrinfo **res);



int main() {
                        const char *hostname = "google.com";
                        const char *port = "1069";
                        struct addrinfo hints, *res;
                        memset(&hints, 0, sizeof hints);
                        hints.ai_family  = AF_UNSPEC;
                        hints.ai_socktype  = SOCK_STREAM;
                        int status = getaddrinfo(hostname, port, &hints, &res);
                       if (status != 0){
                                                       fprintf(stderr,"getaddrinfo error : %s\n", gai_strerror(status));
                                                       exit(EXIT_FAILURE);
                                                      }
                         struct addrinfo *p;
                        for( p = res; p != NULL; p = p->ai_next){
                                                                                                          char ipstr[INET6_ADDRSTRLEN];
                                                                                                          void *addr;
                                                                                                           if (hints.ai_family==AF_INET){
                                                                                                                                                                struct sockaddr_in *ipv4 =(struct sockaddr_in *)p->ai_addr;
                                                                                                                                                                addr = &(ipv4 ->sin_addr);
                                                                                                                                                                }
                                                                                                            else{
                                                                                                                       struct sockaddr_in6 *ipv6 =(struct sockaddr_in6 *)p->ai_addr;
                                                                                                                                                                addr = &(ipv6 ->sin6_addr);
                                                                                                                        }
                                                                                                            inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr); 
                                                                                                            printf("Adresse IP: %s\n", ipstr); 
                                                                                                           }
                   freeaddrinfo(res);
                   return 0;
                  }
                                                                                                                     



                        