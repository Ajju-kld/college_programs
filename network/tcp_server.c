// TCP Chat : Server

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
main()
{
    struct sockaddr_in client, server;
    /*
         struct sockaddr_in {
               sa_family_t    sin_family; //address family: AF_INET
               in_port_t      sin_port;   // port address
               struct in_addr sin_addr;  // internet address
         };

         // Internet address.
         struct in_addr {
               uint32_t s_addr;     // ip address
         };

       struct sockaddr {
           sa_family_t sa_family;
           char sa_data[14];
       }
        //sockaddr_in can be casted to a sockaddr
    */
    int lfd, n, confd;
    char rBuf[100] = "", sBuf[100] = "";
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    /* socket - create an endpoint for communication for more details refer "man socket"
    syntax:	int socket(int domain, int type, int protocol)
    AF_INET: 			IPv4 Internet protocols
    SOCK_STREAM:	Provides sequenced, reliable, two-way, connection-based byte  streams. (TCP)
    0: 						only a single protocol exists to support a particular socket type
*/
    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    /*
        Syntax: in_addr_t inet_addr(const char *cp);
        The inet_addr() function converts the Internet  host  address  cp  from
  IPv4  numbers-and-dots notation into binary data.
    */
    bind(lfd, (struct sockaddr *)&server, sizeof server); /*bind - bind a name to a socket
                       Syntax:	int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);

             struct sockaddr {
                 sa_family_t sa_family;
                 char sa_data[14];
             }

          */
    listen(lfd, 1);                                       /* listen - listen for connections on a socket
                                               Syntax: int listen(int sockfd, int backlog);
                                               sockfd: argument  is  a file descriptor that refers to a socket
                                               backlog: argument defines the maximum length to which the queue of
                                                          pending connections for sockfd may grow
                                               */

    printf("\nServer ready,waiting for client....\n");
    n = sizeof client;
    confd = accept(lfd, (struct sockaddr *)&client, &n);
    /*
    accept - accept a connection on a socket
    Syntax: int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    sockfd: is a socket that han created with socket(),s bee
                    bound to a local address with bind(), and is
                    listening for connectons after a listen(
    addr: 	is a pointer to a sockaddr structure.  This structure).
            is filled in with the address of the peer socket.
    addrlen:argument is a value-result argument: the caller must initialize
                  it to contain the size (in bytes) of the structure pointed to by addr;
    */
while (1)
{
    /* code */


    recv(confd, rBuf, sizeof rBuf, 0);
    /*
        ssize_t recv(int sockfd, void *buf, size_t len, int flags);
        if int flags== 0, it means that no flags are specified(these are optional).
        e.g. MSG_ERRQUEUE:	This  flag  specifies that queued errors
                                                should be received from the socket error queue.
    */
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
