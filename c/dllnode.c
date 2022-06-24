#include <stdio.h>
#include <stdlib.h>
struct dllnode
{
    int info;
    struct dllnode *prev;
    struct dllnode *next;
};
typedef struct dllnode dllnode;
 dllnode *header = NULL;

 dllnode *create_node(int item){
 dllnode *newnode=  (dllnode *)malloc(sizeof (dllnode));
    newnode->info=item;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void reverse()
{

    if (header != NULL)
    {
     dllnode *temp = header, *save;
        while (temp!= NULL)
        {

            if (temp->next == NULL)
            {
                header = temp;
            }
            save = temp->next;
            temp->next = temp->prev;
            temp->prev = save;
            temp = temp->prev;
        
        }
       
    }

    else
    {
        printf("list is empty");
    }
}

void display()
{
 dllnode *temp = header;

    if (header != NULL)
    {
        /* code */

        while (temp != NULL)
        {
            printf("\t%d", temp->info);
            temp = temp->next;
        }
    }
    else
    {
        printf("list is empty");
    }
}
int count()
{
 dllnode *temp = header;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void delete_from_begining()
{

    if (header != NULL)
    {
     dllnode *temp = header;
        header = temp->next;
        header->prev = NULL;
        free(temp);
    }
    else
    {
        printf("list is empty");
    }
}

void insert_in_sort(int item)
{

 dllnode *newnode=create_node(item), *temp = header,*previous=NULL;


    if (header != NULL)
    {
        while (temp!= NULL && temp->info < item)
        {     previous=temp;
            temp = temp->next;
        }

        if (previous == NULL)
        {
            newnode->next = temp;
            temp->prev = newnode;
            header = newnode;
        }
       
       
        else if(temp==NULL){
            previous->next=newnode;
            newnode->prev=previous;
        }

        else
        {

            previous->next = newnode;

            newnode->prev = previous;

            newnode->next = temp;
            temp->prev = newnode;
        }
    }
    else
    {
        header = newnode;
    }
}

void delete_from_end()
{
    if (header != NULL)
    {
     dllnode *current = header, *temp;
        while (current->next != NULL)
        {
            current = current->next;
        }
        if (current->prev == NULL)
        {
            header = NULL;
            free(current);
        }
        else
        {
            temp = current->prev;
            temp->next = NULL;
            free(current);
        }
    }
    else
    {
        printf("list is empty");
    }
}

dllnode  *add_at_end(struct dllnode *p, int data)
{

    dllnode  *newnode, *temp;
  newnode=create_node(data);

    if (header == NULL)
    {
        header = newnode;

        return p;
    }
    else
    {
        temp = header;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;

        return p;
    }
}

 dllnode *add_at_begining(struct dllnode *start, int item)
{
     dllnode *newnode=create_node(item);
    

    if (header != NULL)
    {
        newnode->next = header;
        header->prev = newnode;
        header = newnode;

        return start;
    }
    else
    {
        header = newnode;
        return start;
    }
}

void main()
{
    int repeat = 1;
    int item;
    printf("<-----------linked list ------------>");
    while (repeat == 1)
    {

        printf("\n\n1.insert as first node\n2.insert as last node\n3.insert in sorted order\n4.display the list\n5.number of nodes\n6.reverse\n7.delete from begining\n8.delete from end\n9.Exit\n :");
        scanf("%d", &item);
        switch (item)
        {
        case 1:
            printf("enter the item to be inserted: ");
            scanf("%d", &item);
            add_at_begining(header,item);
            break;
        case 2:
            printf("enter the item to be inserted: ");
            scanf("%d", &item);
            add_at_end(header,item);
            break;
        case 3:
            printf("enter the item to be inserted: ");
            scanf("%d", &item);
            insert_in_sort(item);
            break;
        case 4:
            display();
            break;
        case 5:
            item = count();
            printf("%d", item);
            break;
        case 6:
            reverse();
            break;
        case 7:
            delete_from_begining();
            break;
        case 8:
            delete_from_end();
            break;
       
        case 9:
            repeat = 0;
            break;
        default:
            printf("\ninvalid option");
            break;
            getchar();
        }
    }
}
