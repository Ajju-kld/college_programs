#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
};

struct node *header = NULL;


void enqueue(int data)
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->ptr = NULL;
    if (header == NULL)
    {

        newnode->ptr=newnode;
        header=newnode;
        
    }
    else
    {   
    
       
            newnode->ptr=header->ptr;
            header->ptr=newnode;
            header=newnode;
         
      
          
}
    
    
       
    }




void display()
{

    if (header == NULL)
    {

        printf("queue  is empty");
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

void dequeue()
{

    if (header != NULL)
    {
        struct node *temp = header->ptr;
        if(temp==header){
            header=NULL;
            free(temp);
            
        }
        else{
        header->ptr = temp->ptr;
        free(temp);
       
        }
        printf("removed element : ");
        
    }

}


void main()
{

    int repeat = 1;
    int item;
    
    printf("<-----------linked list ------------>");
    while (repeat == 1)
    {

        printf("\n\n1.enqueue\n2.dequeue\n3.display\n4.exit \n:");
        scanf("%d", &item);
        switch (item)
        {
        case 1:
            printf("enter the item to be inserted: ");
            scanf("%d", &item);
            enqueue(item);
            break;

     
     

        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;

        case 4:
            repeat = 0;
            break;
        default:
            printf("\ninvalid option");
            break;
            getchar();
        }
    }
}