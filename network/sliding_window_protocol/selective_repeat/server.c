#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max_frame_count 20

int packet_no = 0;
int front = -1;
int rear = -1;
int packet_limit = 0;
int no_of_packets;
struct packet_header
{

    int packtno;
};

void initialize_buffer(int *buffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        buffer[i] = packet_no;
        printf("%d ", buffer[i]);
        packet_no++;
    }
}

void enqueue(int packtno, struct packet_header *header)
{

    if (front == -1)
    {
        front = 0;
        rear = 0;
        header[rear].packtno = packtno;
    }
    else
    {
        rear++;
        header[rear].packtno = packtno;
    }
}

void dequeue()
{
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void initialize_buffer_with_lost(int *buffer, int size, struct packet_header *header)
{
    int i = 0;
    while (i < size)
    {
        if (front == -1 && rear == -1)
        {
            buffer[i] = (char)packet_no;
            packet_no++;
        }
        else
        {
            buffer[i] = header[front].packtno;
            dequeue();
        }
        printf("%d ", buffer[i]);
        i = i + 1;
    }
}

void aknowledge(int *ack, int *buffer, int window_size, int fram_no, struct packet_header *header)
{
    int flag = 0;
    for (int i = 0; i < window_size; i++)
    {
        if (ack[i] == -1)
        {
            printf("received negative acknowledgement for packet %d\n", buffer[i]);
            flag = 1;
            enqueue(buffer[i], header);
        }
        else
            packet_limit = packet_limit + 1;
        if (packet_limit == no_of_packets)
            break;
    }
    if (flag == 0)
        printf("\nPositive acknowledgement received for all packets,within the frame:%d\n", fram_no);
    else
    {
        printf("Retransmitting packets: \n");

        for (int i = 0; i < window_size; i++)
        {
            if (ack[i] == -1)
            {
                printf(" %d\t", buffer[i]);
            }
        }
    }
}

void main(int argc, char *argv[])
{

    int control_socket, contol_accept;
    struct sockaddr_in client, control;

    char rBuf[100] = "";

    // creating solclient
    control_socket = socket(AF_INET, SOCK_STREAM, 0);

    control.sin_family = AF_INET;
    control.sin_addr.s_addr = inet_addr("127.0.0.1");
    control.sin_port = atoi(argv[1]);
    bind(control_socket, (struct sockaddr *)&control, sizeof(control));
    listen(control_socket, 5);
    printf("server ready , waiting for client to connect...\n");
    int n = sizeof(client);
    contol_accept = accept(control_socket, (struct sockaddr *)&control, &n);
    if (contol_accept == -1)
    {
        printf("failed to connect \n");
        exit(0);
    }
    recv(contol_accept, rBuf, sizeof(rBuf), 0);
    printf("The client connection obtained: %s\n", rBuf);
    printf("Sending request for window size \n");
    send(contol_accept, "window_size", sizeof("window_size"), 0);
    printf("Waiting for the window size...");
    int window_size;
    int frame_buffer[window_size];
    recv(contol_accept, &window_size, sizeof(window_size), 0);
    printf("\nThe window size obtained from the client: %d\n", window_size);
    printf("Enter the total number of packets:");
    scanf("%d", &no_of_packets);

    struct packet_header queue[no_of_packets];

    printf("Sending total number of packets\n");
    send(contol_accept, &no_of_packets, sizeof(int), 0);

    int acknowledgtment_buf[window_size];
    bool completed = false;
    getchar();
    int frame = 0;
    while (!completed)
    {

        printf("\nThe frame to be send is %d with packets :", frame);
        // initialize the send buffer
        (front == -1)
            ? initialize_buffer(frame_buffer, window_size)
            : initialize_buffer_with_lost(frame_buffer, window_size, queue);
        send(contol_accept, &frame_buffer, sizeof(int) * window_size, 0);
        printf("\nsending frame %d\n", frame);

        recv(contol_accept, &acknowledgtment_buf, sizeof(int) * window_size, 0);
        aknowledge(acknowledgtment_buf, frame_buffer, window_size, frame, queue);

        printf("\nno of packets recieved at client: %d\n", packet_limit);
        frame++;

        // if there are nack packets available then continue to send else close connection
        if (packet_limit == no_of_packets)
        {

            printf("completed\n");
            send(contol_accept, "completed", sizeof("completed"), 0);
            completed = true;
            break;
        }
        else
        {
            send(contol_accept, "continue", sizeof("continue"), 0);
            printf("\nPress enter to proceed\n");
        }
        getchar();
    }

    printf(" All frames sends successfully \n Closing connection with the client ");
    close(contol_accept);
    close(control_socket);
}