#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORTNUM 2300
#define MAXRCVLEN 8

void printMenu(void);
void *guiThread(void *arg);

int main(int argc, char *argv[])
{
    //---------Threads-------
    pthread_t guiThreadID;
    int threadError = pthread_create(&guiThreadID, NULL, guiThread, NULL);
    if (threadError != 0)
    {
        printf("Cannot create thread, error: %d\n", threadError);
        exit(-1);
    }

    int mysocket = 0, consocket = 0, bytesReceived, totalBytes;
    struct sockaddr_in serv;
    char recvBuff[MAXRCVLEN + 1];
    char buffer[MAXRCVLEN + 1]; // +1 so we can add null terminator

    mysocket = socket(AF_INET, SOCK_STREAM, 0);
    printf("Socket created\n");

    memset(&serv, '0', sizeof(serv));
    memset(recvBuff, '0', sizeof(recvBuff));

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv.sin_port = htons(PORTNUM);

    bind(mysocket, (struct sockaddr *)&serv, sizeof(serv));
    listen(mysocket, 10);

    while (1)
    {
        consocket = accept(mysocket, (struct sockaddr *)NULL, NULL);
        if (consocket == -1)
        {
            printf("Client Overload\n");
            continue;
        }
        recv(consocket, buffer, 21, 0);
        printf("Filename: %s\n", buffer);
        recv(consocket, buffer, 8, 0);
        if (strcmp(buffer, "sample2.txt") == 0)
        {
            printf("hello\n");
        }
        FILE *fp = fopen("outPut.txt", "w++");
        totalBytes = 0;
        if (fp != NULL)
        {
            while ((bytesReceived = recv(consocket, recvBuff, 1024, 0)) > 0)
            {
                totalBytes += bytesReceived;
                fwrite(recvBuff, 1, bytesReceived, fp);
            }
            printf("Received byte: %d\n", totalBytes);
            int received_int = 0;
            int return_status = read(consocket, &received_int, sizeof(received_int));
            if (return_status > 0)
            {
                fprintf(stdout, "Received int = %d\n", ntohl(received_int));
            }
            else
            {
                // Handling erros here
            }

            if (bytesReceived < 0)
            {
                printf("Receiving\n");
            }
            fclose(fp);
        }
        else
        {
            printf("Invalid File\n");
            return 1;
        }
        close(consocket);
    }
    pthread_join(guiThreadID, NULL);
    return 0;
}

void *guiThread(void *arg)
{
    int usrMenuChoice = 0;
    char userRawInput[25];
    while (usrMenuChoice != 3 || usrMenuChoice != 2)
    {
        printMenu();
        fgets(userRawInput, 25, stdin);
        usrMenuChoice = atoi(userRawInput);
        switch (usrMenuChoice)
        {
        case 1:
            printf("Active Downloads:\n");
            break;

        case 2:
            printf("Shutting server dowsn.....\n");
            break;

        case 3:
            printf("Shutting server dowsn.....\n");
            break;
        }
        printf("\n");
    }
    return NULL;
}
void printMenu(void)
{
    printf("Select a menu option:\n");
    printf("1.View Active Downlods.\n");
    printf("2.Soft shutdown.\n");
    printf("3.Hard shutdown.\n");
    printf(">");
}
