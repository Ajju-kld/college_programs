#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

int no_of_packets;
int frame_count = 0;
void display_packet(int *frame_buffer, int window_size)
{
    printf("The received frame  with packets :");
    for (int i = 0; i < window_size; i++)
    {
        if (frame_buffer[i] < no_of_packets)
        {
            printf("%d   ", frame_buffer[i]);
        }
        else
        {
            printf(" \ndropped packet %d ", frame_buffer[i]);
        }
    }
}

void main(int argc, char *argv[])
{  if(argc<2){
    
    printf("error in formate example ./<program> <portno>");
    exit(0);
}

    int control_sock, control_port, window_size;
    char send_buf[100] = " HI IAM CLIENT ", r_Buf[10000];
    struct sockaddr_in servaddr, data;

    // creation of control socket
    control_port = atoi(argv[1]);
    control_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (control_sock < 0)
    {
        printf("Error creating sockets\n");
        exit(0);
    }
    else
        printf("Sockets are created\n");

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = control_port;

    if (connect(control_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        printf("Error in connection\n");
    else
        printf("Connected to server\n");

    send(control_sock, send_buf, sizeof(send_buf), 0);
    recv(control_sock, r_Buf, sizeof(r_Buf), 0);
    if (strcmp(r_Buf, "window_size") == 0)
    {
        printf("server requested window size:");
        scanf("%d", &window_size);
        send(control_sock, &window_size, sizeof(window_size), 0);
    }
    else
        printf("server error");
    int frame_buffer[window_size];
    int ack_buffer[window_size];
    recv(control_sock, &no_of_packets, sizeof(int), 0);

    printf("no of packets %d\n", no_of_packets);

    bool completed = false;
    while (!completed)
    {
        // this recv function executes only once
        // bug in recv function

        printf("\ninitializing the received buffer \nwaiting for the frame\n");
        if ((recv(control_sock, frame_buffer, sizeof(int) * window_size, 0) < 0))
        {
            printf("Error in receiving the frame\n");
            exit(0);
        }

        display_packet(frame_buffer, window_size);
        printf("\nreceived frame %d\n", frame_count);

        printf("\nenter -1 to send negative acknowledgement for the following packets \n");

        for (int j = 0; j < window_size; j++)
        {
            if (frame_buffer[j] < no_of_packets) // this is to ensure that it doesn't accept extra packets
            {
                printf("packet: %d\n", frame_buffer[j]);

                scanf("%d", &ack_buffer[j]);
                printf("\n");
            }
        }

        send(control_sock, ack_buffer, sizeof(int) * window_size, 0);
        frame_count = frame_count + 1;

        recv(control_sock, r_Buf, sizeof(r_Buf), 0);

        if (strcmp(r_Buf, "completed") == 0)
        {
            printf("completed\n");
            break;
        }
    }
    printf("all frames received successfully\n");
    printf("clossing connection with the server\n");
    close(control_sock);
}

// last added packet limit  to prevent infinite recursion