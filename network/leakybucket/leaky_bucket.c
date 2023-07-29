
// program of leaky bucket

#include <stdio.h>

int bucket_full(int excess, int bucket_size)
{
    printf("Dropped %d bytes of data from the packet\n", excess);
    return bucket_size;
}

int main()
{
    int buffer_size = 0, no_of_packet, out_going_rate, bucket_size, each_packet,i;
    FILE *fp;
    fp = fopen("leaky_input.txt", "r");
    fscanf(fp, "%d", &bucket_size);
    printf("enter the size of the bucket (Bytes):%d\n", bucket_size);
    fscanf(fp, "%d", &out_going_rate);
    printf("enter the outgoing_rate of the bucket(Bytes per second): %d\n", out_going_rate);
    fscanf(fp, "%d", &no_of_packet);
    printf("enter the number of packet : %d\n", no_of_packet);
    for (i = 0; i < no_of_packet; i += 1)
    {
        fscanf(fp, "%d", &each_packet);

        printf("enter the size of packet in bytes: %d\n", each_packet);

        buffer_size = (each_packet + buffer_size) <= (bucket_size) ? buffer_size + each_packet : bucket_full(buffer_size + each_packet - bucket_size, bucket_size);

        printf("current bucket is filled %d bytes from %d bytes \n", buffer_size, bucket_size);

        buffer_size = (buffer_size < out_going_rate) ? 0 : buffer_size - out_going_rate;

        printf("After outgoing %d bytes left out of %d in the buffer \n", buffer_size, bucket_size);

        printf("\n");
    }
    fclose(fp);
    return 0;
}

