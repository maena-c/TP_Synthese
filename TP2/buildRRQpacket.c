#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "buildRRQPacket.h"

#define MAX_BUFFER_SIZE 516


void buildRRQPacket(const char *filename, const char *mode, char *rrqPacket) {

                                                                                                                                                                                uint16_t opcode = htons(1);  // 1 pour RRQ

   
                                                                                                                                                                                   strcpy(rrqPacket, (char *)&opcode);
                                                                                                                                                                                   strcat(rrqPacket, filename);
                                                                                                                                                                                   strcat(rrqPacket, "\0");
                                                                                                                                                                                   strcat(rrqPacket, mode);
                                                                                                                                                                                   strcat(rrqPacket, "\0");
}


