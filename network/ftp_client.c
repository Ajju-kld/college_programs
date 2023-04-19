#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

char rBuf[10000] = "";
char send_buf[100]="";


void recieve_file(FILE *fp,int length)
{

    fwrite(rBuf, sizeof(char),length,fp);
 

    printf("%s", rBuf);
}

void main()
{   char choice[100];
    struct sockaddr_in client, server_send, recieve_file_send;

    int send_port, n, reciever_confd, recievinging_port, sending_confd;
    send_port = socket(AF_INET, SOCK_STREAM, 0);
   //sending port to server
    server_send.sin_family = AF_INET;
    server_send.sin_port = 2000;
    server_send.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(send_port, (struct sockaddr *)&server_send, sizeof server_send);
    listen(send_port, 1);

    n = sizeof client;
    reciever_confd = accept(send_port, (struct sockaddr *)&client, &n);

    // configuring recieving port from server

    recievinging_port = socket(AF_INET, SOCK_STREAM, 0);
    recieve_file_send.sin_family = AF_INET;
    recieve_file_send.sin_port = 4000;
    recieve_file_send.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(recievinging_port, (struct sockaddr *)&recieve_file_send, sizeof recieve_file_send);
    listen(recievinging_port, 1);
    sending_confd = accept(recievinging_port, (struct sockaddr *)&client, &n);

    connect(send_port, (struct sockaddr *)&server_send, sizeof server_send);
    

    do {
        printf("get to download the file\n close to close the connection");
        scanf("%s",choice);
        printf("enter the file name: ");
        scanf("%s",send_buf);
    

        send(reciever_confd, send_buf, sizeof(send_buf), 0);
        connect(recievinging_port, (struct sockaddr *)&server_send, sizeof server_send);

        if (send_buf == 'close')
        {
           break;
        }
        recv(sending_confd, rBuf, sizeof rBuf, 0);

        if(rBuf=='false'){
            
           printf("%s not found Process id = %d",send_buf,getpid());
        
        }
        else{
        FILE *fp;
        fp = fopen(send_buf, "w");
        recieve_file(fp,sizeof(rBuf)-1);
        fclose(fp);
        printf("file successfully downloaded");
        
    }
    } while (choice!="close");

    printf("connection closed");
}