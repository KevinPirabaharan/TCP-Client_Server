#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <arpa/inet.h>

#define MAXRCVLEN 8
#define PORTNUM 2300

int main(int argc, char *argv[]){

    int mysocket = 0, bytesSent, buffSize;
    buffSize = MAXRCVLEN;
    
    char buff[buffSize];
    char* msg;
    struct sockaddr_in deset;
    mysocket = socket(AF_INET, SOCK_STREAM, 0);

    deset.sin_family = AF_INET;
    deset.sin_port = htons(PORTNUM);
    deset.sin_addr.s_addr = inet_addr("127.0.0.1");

    bytesSent = connect(mysocket, (struct sockaddr *)&deset, sizeof(deset));
    if (bytesSent == bytesSent - 1)
    {
        printf("Can't connect\n");
        return 1;
    }
    msg = "sample2.txt";
    FILE *fp = fopen(msg, "rb");
    if(fp == NULL)
    {
        printf("Invalid File\n");
        return 2;
    }
    else
    {
    	send(mysocket, msg, 21, 0); 
    }
    int totBytesSent = 0;
    while( (bytesSent = fread(buff, 1, sizeof(buff), fp)) > 0 )
    {
        send(mysocket, buff, bytesSent, 0);
        totBytesSent = totBytesSent + bytesSent;
    } 
	int tmp = 0;
	tmp = htonl((uint32_t)totBytesSent);
	write(mysocket, &tmp, sizeof(tmp));
	printf("%d\n", tmp);
    printf("Done sending! Sent %d bytes\n", totBytesSent);

    fclose(fp);
    return 0;
}
