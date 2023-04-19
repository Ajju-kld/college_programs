// TCP Chat : Client

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

char rBuf[10000] = "";

void recieve_file(FILE *fp, int length)
{

    fwrite(rBuf, sizeof(char), length, fp);

    printf("%s", rBuf);
}

void main()
{
    struct sockaddr_in server_recive, server_send;
    int lfd, lfd_1;
    char choice[100];
    char send_buf[100] = "";
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    server_recive.sin_family = AF_INET;
    server_recive.sin_port = 7002;
    server_recive.sin_addr.s_addr = inet_addr("127.0.0.1");
    printf("\nClient ready....\n");

    // second port to recieve
    lfd_1 = socket(AF_INET, SOCK_STREAM, 0);
    server_send.sin_family = AF_INET;
    server_send.sin_port = 5002;
    server_send.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (1)
    {
        /* code */

        connect(lfd, (struct sockaddr *)&server_recive, sizeof server_recive);
        printf("enter the file name :");
        gets(send_buf);
        send(lfd, send_buf, sizeof send_buf, 0);
        connect(lfd_1, (struct sockaddr *)&server_send, sizeof server_send);
        recv(lfd_1, rBuf, sizeof rBuf, 0);

        if (rBuf == "false")
        {

            printf("%s not found Process id = %d", send_buf, getpid());
        }
        else
        {
            FILE *fp;
            fp = fopen(send_buf, "w");
            recieve_file(fp, sizeof(rBuf) - 1);
            fclose(fp);
            printf("file successfully downloaded");
        }

        printf("\nServer:%s", rBuf);
    }
    printf("\n");

    close(lfd);
}