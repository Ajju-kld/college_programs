#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
};

struct node *header = NULL;

void addatbegining(int data)
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->ptr = NULL;

    if (header == NULL)
    {
        header = newnode;
        newnode->ptr = header;
    }
    else
    {
        newnode->ptr = header->ptr;
        header->ptr = newnode;
    }
}
void add(int data)
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->ptr = NULL;
    if (header != NULL)
    {

        newnode->ptr = header->ptr;
        header->ptr = newnode;
        header = newnode;
    }
    else
    {
        header = newnode;
        newnode->ptr = header;
    }
}

int count()
{
    int nodes = 0;

    if (header != NULL)
    {
        struct node *temp;
        temp = header->ptr;
        while (temp != header)
        {
            temp = temp->ptr;
            nodes++;
        }
        nodes++;
    }

    return nodes;
}

void display()
{

    if (header == NULL)
    {

        printf("list in empty");
    }

    else
    {
        struct node *current = header->ptr;
        while (current != header)
        {

            printf("%d\t", current->data);
            current = current->ptr;
        }
        printf("%d\t", current->data);
    }
}

void delete_from_begining()
{

    if (header != NULL)
    {
        struct node *temp = header->ptr;
        if (temp == header)
        {
            header = NULL;
            free(temp);
        }
        else
        {
            header->ptr = temp->ptr;
            free(temp);
        }

        printf("memory freed successfully");
    }
    else
    {
        printf("list is empty");
    }
}

void delete_from_end()
{

    if (header != NULL)
    {
        struct node *next = header->ptr, *prev = NULL;
        while (next != header)
        {
            prev = next;
            next = next->ptr;
        }
        if (prev == NULL)
        {
            header = NULL;
            free(next);
        }
        else
        {
            prev->ptr = next->ptr;
            header = prev;
        }

        printf("element removed successfully");
    }
    else
    {
        printf("the list is empty");
    }
}

void main()
{

    int repeat = 1;
    int item;
    printf("<-----------linked list ------------>");
    while (repeat == 1)
    {

        printf("\n\n1.insert as first node\n2.insert as last node\n3.display the list\n4.number of nodes\n5.delete from begining\n6.delete from end\n7.Exit\n :");
        scanf("%d", &item);
        switch (item)
        {
        case 1:
            printf("enter the item to be inserted: ");
            scanf("%d", &item);
            addatbegining(item);
            break;
        case 2:
            printf("enter the item to be inserted: ");
            scanf("%d", &item);
            add(item);
            break;

        case 3:
            display();
            break;
        case 4:
            item = count();
            printf("%d", item);
            break;

        case 5:
            delete_from_begining();
            break;
        case 6:
            delete_from_end();
            break;

        case 7:
            repeat = 0;
            break;
        default:
            printf("\ninvalid option");
            break;
            getchar();
        }
    }
}