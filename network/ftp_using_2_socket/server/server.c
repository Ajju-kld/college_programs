#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char send_buf[10000] = "";
void send_file(FILE *fp)
{
    int i = 0;
    while (!feof(fp))
    {
        send_buf[i] = fgetc(fp);
        i++;
    }
    send_buf[i] = '\0';
}

void main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("Usage: ./server <server IP> <control port> \n");
        exit(1);
    }

    struct sockaddr_in client, control, data, data_client;
    FILE *fp, *log;
    int lfd, n, confd, fd, confd2;
    char rBuf[100] = "";


    lfd = socket(AF_INET, SOCK_STREAM, 0);

    control.sin_family = AF_INET;
    control.sin_port = atoi(argv[2]);
    control.sin_addr.s_addr = inet_addr(argv[1]);

    bind(lfd, (struct sockaddr *)&control, sizeof(control));
    listen(lfd, 5);
    printf("\nServer ready,waiting for client....\n");
    n = sizeof client;
    confd = accept(lfd, (struct sockaddr *)&client, &n);
    if (confd == -1)
    {
        printf("Failed to connect");
        exit(0);
    }
    printf("\nClient connected....\n");

    while (1)
    {

        recv(confd, rBuf, sizeof rBuf, 0);

        if (strcmp(rBuf, "get") == 0)
        {

            printf("client command: %s\n", rBuf);

            recv(confd, rBuf, sizeof rBuf, 0);
            printf("\nServer received the file to fetch: %s\n", rBuf);
            fp = fopen(rBuf, "r");
            if (fp == NULL)
            {
                send(confd, "error", sizeof("error"), 0);
                printf("\nfile %s not found ", rBuf);
            }
            else
            {
                send(confd, "success", sizeof("success"), 0);
                fd = socket(AF_INET, SOCK_STREAM, 0);
                // data connection

                data.sin_family = AF_INET;
                data.sin_addr.s_addr = inet_addr(argv[1]);
                data.sin_port = 8080;

                bind(fd, (struct sockaddr *)&data, sizeof(data));
                listen(fd, 10);
                printf("\nServer ready,waiting for client to connect to data socket\n");
                n = sizeof(data_client);
                confd2 = accept(fd, (struct sockaddr *)&data_client, &n);
                if (confd2 == -1)
                {
                    printf( "Failed to connect the data socket\n");
                    exit(0);
                }
                printf("\nClient connected to data socket\n");

                send_file(fp);

                if (send(confd2, send_buf, sizeof(send_buf), 0) == -1)
                    printf("sending failed\n");

                else
                {
                    printf("file send success\n");
                    printf("file send successfully\n");
                }
            
                fclose(fp);
            }
        }
    close(confd2);
    close(fd);
        if (strcmp(rBuf, "close") == 0)
        {
            printf("\nclient command: %s\n", rBuf);
     
            printf("\nClient disconnected and server closed\n");
            break;
        }
    }
    close(confd);
    close(lfd);

}