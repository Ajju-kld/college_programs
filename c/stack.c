

#include <stdio.h>
int top = -1;

void push(int a[], int size, int item);

void pop(int a[]);

void pop(int a[])
{

    if (top == -1)
    {
        printf("underflow");
    }
    else
    {

        int item = a[top];

        top = top - 1;
        printf("%d is successfully removed",item);
    }
}

void push(int a[], int size, int item)
{

    if (top == size - 1)
    {

        printf("overflow");
    }
    else
    {
        top = top + 1;
        a[top] = item;
        printf("The element is added sucessfully");
    }
}

void main()
{

    int size, option, item;
    printf("enter the size of the stack: ");
    scanf("%d", &size);

    int stack[size];
    int i;
    int ans;

    do
    {

        printf("1.push operation\n2.pop operation\n3.Display the stack\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("enter the number to be inserted: ");
            scanf("%d", &item);
            push(stack, size, item);

            break;
        case 2:
            
            pop(stack);

            break;
        case 3:
            for (i = top; i >= 0; i--)
            {

                printf("%d\n", stack[i]);
            }

            break;
        default:
            printf("invalid choice");
            break;
        }

        printf("\nwheather you wish to repeat then press 1 : ");
        scanf("%d", &ans);

    } while (ans == 1);
}