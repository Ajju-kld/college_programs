
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *leftchild;
    struct node *rightchild;
};
struct node *Troot = NULL;

// inorder sucesser

struct node *Treemin(struct node *t)
{
    if (t == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *ptr = t;
        while (ptr->leftchild != NULL)
        {
            ptr = ptr->leftchild;
        }
        return ptr;
    }
}

// insertion in bst

void insert(struct node *t, int item)
{
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->info = item;
    newnode->leftchild = NULL;
    newnode->rightchild = NULL;
    if (Troot == NULL)
    {
        Troot = newnode;
    }
    else
    {
        struct node *ptr = Troot, *parent = NULL;

        while (ptr != NULL)
        {
            if (item < ptr->info)
            {
                parent = ptr;
                ptr = ptr->leftchild;
            }
            else
            {
                parent = ptr;
                ptr = ptr->rightchild;
            }
        }
        if (item > parent->info)
        {
            parent->rightchild = newnode;
        }
        else
        {
            parent->leftchild = newnode;
        }
        printf("newnode is added sucessfully");
    }
}

// code to display the tree in  inorder format
void display(struct node *t)
{

    /* code */

    if (t == NULL)
    {

        return;
    }
    else
    {
        display(t->leftchild);
        printf("%d\t", t->info);
        display(t->rightchild);
    }
}

void deletion(struct node *tr, int item)
{

    struct node *ptr = tr, *parent = NULL;
    while (ptr != NULL && ptr->info != item)

    {
        if (item > ptr->info)
        {
            parent = ptr;
            ptr = ptr->rightchild;
        }
        else
        {
            parent = ptr;
            ptr = ptr->leftchild;
        }
    }

    if (ptr == NULL)
    {
        printf("the element is not present in the tree");
        return;
    }
    else
    { // if the node have no child

        if (ptr->rightchild == NULL && ptr->leftchild == NULL)
        {
            if (parent->leftchild == ptr)
            {
                parent->leftchild = NULL;
            }
            else
                parent->rightchild = NULL;
            free(ptr);
        }

        // if the node have 2 child

        else if (ptr->rightchild != NULL && ptr->leftchild != NULL)
        {
            struct node *child = Treemin(ptr->rightchild);
            int info = child->info;
            deletion(ptr, child->info);
            ptr->info = info;
        }

        // if the child have 1 child
        else
        {
            if (ptr->rightchild != NULL)
            {
                parent->rightchild = ptr->rightchild;
            }
            else
            {
                parent->leftchild = ptr->leftchild;
            }
            free(ptr);
        }
        return;
    }
}

void main()
{
    int choice = 1;

    printf("enter the root node  value :");
    scanf("%d", &choice);
    insert(Troot, choice);

    while (choice != 0)
    {
        printf("\n1.add the element to the tree\n2.display the element in the tree\n3.delete from the tree\n4.exit: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to be added to the tree: ");
            scanf("%d", &choice);
            insert(Troot, choice);
            break;
        case 2:
            display(Troot);
            break;
        case 3:
            printf("enter the element to be deleted: ");
            scanf("%d", &choice);
            deletion(Troot, choice);
            break;
        case 4:
            choice = 0;
            break;
        default:
            printf("invalid choice");

            break;
        }
    }
}