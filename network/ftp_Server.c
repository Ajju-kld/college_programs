#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

char send_buf[10000];
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

void main()
{
    struct sockaddr_in client, server_reciever, server_file_send;

    int reciver_port, n, reciever_confd, sending_port, sending_confd;
    char rBuf[100] = "";
    reciver_port = socket(AF_INET, SOCK_STREAM, 0);

    server_reciever.sin_family = AF_INET;
    server_reciever.sin_port = 6000;
    server_reciever.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(reciver_port, (struct sockaddr *)&server_reciever, sizeof server_reciever);
    listen(reciver_port, 1);

    n = sizeof client;
    reciever_confd = accept(reciver_port, (struct sockaddr *)&client, &n);

    // configuring sending port
    sending_port = socket(AF_INET, SOCK_STREAM, 0);
    server_file_send.sin_family = AF_INET;
    server_file_send.sin_port = 3000;
    server_file_send.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sending_port, (struct sockaddr *)&server_file_send, sizeof server_file_send);
    listen(sending_port, 1);
    sending_confd = accept(sending_port, (struct sockaddr *)&client, &n);

    while (1)
        
    {
        recv(reciever_confd, rBuf, sizeof rBuf, 0);


        bool exist = is_valid(rBuf);

        if (exist == false)
        {
            send(reciever_confd,  "false", sizeof("false"), 0);
        

           
        }

        FILE *fp;
        fp = fopen(rBuf, "r");
        send_file(fp);
        send(sending_confd,send_buf,sizeof(send_buf),0);

    } 
}