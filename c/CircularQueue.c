#include <stdio.h>
int front = -1;
int rear = -1;

void Enqueue(int a[], int size, int item);
void Dequeue(int a[], int size);

void Enqueue(int a[], int size, int item)
{

    if (front == ((rear + 1) % size))
        printf("overflow");
    else
    {
        if (front == -1)
        {
            front = front + 1;
        }
        rear = (rear + 1) % size;
        a[rear] = item;
        printf("element added successfully ");
    }
}
void Dequeue(int a[], int size)
{
    int item;
    if (front == -1)
    {
        printf("underflow");
    }
    else
    {
        item = a[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        printf("%d is removed from the queue", item);
    }
}

void main()
{
    int size, i;
    printf("enter the size of the queue:");
    scanf("%d", &size);
    int Queue[size];
    int option, item;

    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display element\n");
        scanf("%d", &option);
        switch (option)

        {
        case 1:
            printf("enter the element to be added to the list:");
            scanf("%d", &item);
            Enqueue(Queue, size, item);
            break;
        case 2:
            Dequeue(Queue, size);

            break;
        case 3:
            printf("elements in queue are \n");
            for (i = front; i != rear; i = (i + 1) % size)
            {
                printf("%d\t", Queue[i]);
            }
            printf("%d", Queue[i]);
            break;
        default:
            printf("invalid choice\n");
            break;
        }

        printf("\nwheather you wish to repeat then press 1 : ");
        scanf("%d", &option);

    } while (option == 1);
}