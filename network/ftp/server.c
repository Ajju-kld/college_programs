// TCP Chat : Server

#include <stdio.h>
#include <string.h>
#include<stdbool.h>


#include <arpa/inet.h>

char send_buf[100] = "";

bool is_valid(char name[100])
{
    FILE *fp = fopen(name, "r");

    if (fp = NULL)
    {
        return true;
    }

    return false;
}

void send_file(FILE *fp)
{

    int i = 0;
    while (!feof(fp))
    {
        send_buf[i] = fgetc(fp);
        i++;
    }
    send_buf[i] = '\0';
    printf("%s", send_buf);
}

main()
{
    struct sockaddr_in client, server_recieve,server_send;

    int lfd, n, confd;
    char rBuf[100] = "";
    lfd = socket(AF_INET, SOCK_STREAM, 0);

    server_recieve.sin_family = AF_INET;
    server_recieve.sin_port = 7002;
    server_recieve.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(lfd, (struct sockaddr *)&server_recieve, sizeof server_recieve);
    listen(lfd, 1);

    printf("\nServer ready,waiting for client....\n");
    n = sizeof client;
    confd = accept(lfd, (struct sockaddr *)&client, &n);


   //sending using another port

    int lfd_1,confd_1;
    
    lfd_1 = socket(AF_INET, SOCK_STREAM, 0);

    server_send.sin_family = AF_INET;
    server_send.sin_port = 5002;
    server_send.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(lfd_1, (struct sockaddr *)&server_recieve, sizeof server_recieve);
    listen(lfd_1, 1);

    printf("\nServer ready,waiting for client....\n");
    n = sizeof client;
    confd_1 = accept(lfd, (struct sockaddr *)&client, &n);

    while (1)
    {
        /* code */

        recv(confd, rBuf, sizeof rBuf, 0);

        printf("\nClient:%s",rBuf);

        printf("\nServer has replied with the result");

        bool exist = is_valid(rBuf);

        if (exist == false)
        {
            send(confd_1, "false", sizeof("false"), 0);
        }
        else {
        FILE *fp;
        fp = fopen(rBuf, "r");
        send_file(fp);
        send(confd_1, send_buf, sizeof(send_buf), 0);
        fclose(fp);
        }
    }
    
    printf("\n");

    close(confd);
    close(lfd);

    close(confd_1);
    close(lfd_1);
}
