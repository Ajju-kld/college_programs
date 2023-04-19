// TCP Chat : Server

#include <stdio.h>
#include <string.h>


#include <arpa/inet.h>
main()
{
    struct sockaddr_in client, server;
   
    int lfd, n, confd;
    char rBuf[100] = "", sBuf[100] = "";
    lfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
   
    bind(lfd, (struct sockaddr *)&server, sizeof server); 
    listen(lfd, 1);                                       

    printf("\nServer ready,waiting for client....\n");
    n = sizeof client;
    confd = accept(lfd, (struct sockaddr *)&client, &n);
   
while (1)
{
    /* code */


    recv(confd, rBuf, sizeof rBuf, 0);
   
    printf("\nClient:%s", rBuf);

    int i =0,j=strlen(rBuf);
    while (i<j)
    {
      if (rBuf[i]==rBuf[j])
      {
        break;
      }
      i++;
      j--;
    }
    if (i<j)
    {
      send(confd, "it is not paliendrome", sizeof("it is not paliendrome"), 0);
    }
    else
      send(confd, "it is paliendrome", sizeof("it is paliendrome"), 0);

    printf("\nServer has replied with the result");
   
}   
    printf("\n");

    close(confd);
    close(lfd);
}
