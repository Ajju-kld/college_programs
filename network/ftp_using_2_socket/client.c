#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
FILE *Log;

char r_Buf[10000];
void get_function();

void main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: ./client <server IP> <control port> \n");
        exit(1);
    }

    int csd, n, ser, s, cli, cport, newsd, dd;
    char command[100];
    Log = fopen("client.log", "a");
    struct sockaddr_in servaddr, data;
    fprintf(Log, "the control port is %s\n", argv[2]);
    cport = atoi(argv[2]);

    csd = socket(AF_INET, SOCK_STREAM, 0);

    if (csd < 0)
    {
        fprintf(Log, "Error creating sockets\n");
        exit(0);
    }
    else
        fprintf(Log, "Sockets are created\n");

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = cport;

    if (connect(csd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        fprintf(Log, "Error in connection\n");
    else
        printf("Connected to server\n");

    while (1)
    {
        printf("Enter the command: ");
        scanf("%s", command);

        if (strcmp(command, "get") == 0)
        {
            send(csd, command, sizeof(command), 0);
            get_function(csd, data, argv[1]);
            wait(NULL);
            getchar();
        }
        else if (strcmp(command, "close") == 0)
        {
            send(csd, command, sizeof(command), 0);
            break;
        }
        else
        {
            printf("Invalid command\n",command);
        }
    }
    close(csd);
}
void get_function(int csd, struct sockaddr_in data, char *data_addr)
{

    char name[256];
    char valid[10];
    printf("Enter the existing file name: ");
    scanf("%s", name);
    send(csd, name, sizeof(name), 0);
    recv(csd, valid, sizeof(valid), 0);

    if (strcmp(valid, "error") == 0)
    {
        printf("FILE NOT FOUND PROCESS ID = %d\n", getpid());
        return;
    }
    printf("enter the new file name: ");
    scanf("%s", name);

    int dd = socket(AF_INET, SOCK_STREAM, 0);
    if (dd < 0)
    {
        fprintf(Log, "Error creating sockets\n");
        exit(0);
    }
    fprintf(Log, "data socket created\n");

    data.sin_family = AF_INET;
    data.sin_addr.s_addr = inet_addr(data_addr);
    data.sin_port = 8080;

    if (fork() == 0)
    {
        if (connect(dd, (struct sockaddr *)&data, sizeof(data)) < 0)
            fprintf(Log, "Error in connection of data socket\n");
        else
            fprintf(Log, "Connected to server to data socket\n");

        if (recv(dd, r_Buf, sizeof r_Buf, 0) < 0)
        {
            fprintf(Log, "not received the file\n");
            close(dd);
            exit(0); // Exit the child process
        }

        FILE *fp;
        fp = fopen(name, "w");
        fprintf(fp, "%s\n\n", r_Buf);
        fprintf(fp, "FILE %s RECEIVED FROM SERVER WITH PROCESS ID = %d", name, getpid());
        fclose(fp);

        close(dd);
        exit(0); // Exit the child process
    }
}