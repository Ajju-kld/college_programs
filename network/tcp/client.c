// TCP Chat : Client

#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
void main()
{
    struct sockaddr_in server;
    int lfd;
    char rBuf[100] = "", sBuf[100] = "";
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    printf("\nClient ready....\n");
   int acpt= connect(lfd, (struct sockaddr *)&server, sizeof server);
    if (acpt==-1)
    {
        printf("\nError connecting to server");
    }
    else printf("\nserver accepted connection");
    
    while (1)
    {

        printf("\nclient:");

        gets(sBuf);
        send(lfd, sBuf, sizeof sBuf, 0);
        if (strcmp(sBuf, "bye") == 0)
        {
            break;
        }

        recv(lfd, rBuf, sizeof rBuf, 0);

        printf("\nServer:%s", rBuf);
   }
    printf("\nsession closed ....");

    close(lfd);
}
