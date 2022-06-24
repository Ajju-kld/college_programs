#include <stdio.h>
#include <stdlib.h>
struct node
{
    char info;
    struct node *left;
    struct node *right;
};
typedef struct node Tnode;
Tnode *root;
void insertLeft(Tnode *);
void insertRight(Tnode *);
void postorder(Tnode *T){
    if (T != NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf(" %c", T->info);
    }
}
void preorder(Tnode *T);


void inorder(Tnode *T){
    if (T != NULL)
    {
        inorder(T->left);
        printf(" %c", T->info);
        inorder(T->right);
    }
}

int main()
{
    Tnode *newnode;
    char c;
    int ch;
    root = NULL;
    printf("Does there is a non empty tree? ");
    printf("\n YES - 1 \n NO - 0 :: ");
    scanf("%d", &ch);
    if (ch == 1)
    {
        newnode = (Tnode *)malloc(sizeof(Tnode));
        printf("Enter the value in the root node : ");
        getchar();
        scanf("%c", &c);
        newnode->info = c;
        root = newnode;
        printf("Does %c has left child? ", c);
        printf("\n YES - 1 \n NO - 0 :: ");
        getchar();
        scanf("%d", &ch);
        if (ch == 1)
            insertLeft(newnode);
        else
            newnode->left = NULL;
        printf("Does %c has right child? ", c);
        printf("\n YES - 1 \n NO - 0 :: ");
        getchar();
        scanf("%d", &ch);
        if (ch == 1)
            insertRight(newnode);
        else
            newnode->right = NULL;
            printf("\n preorder\n");
        preorder(root);
        printf("\n inorder\n");
        inorder(root);
        printf("\n postorder\n");
        postorder(root);
    }
    return 0;
}
void insertLeft(Tnode *T)
{
    Tnode *newnode;
    char c;
    int ch;
    newnode = (Tnode *)malloc(sizeof(Tnode));
    printf("Enter the value in the node : ");
    getchar();
    scanf("%c", &c);
    newnode->info = c;
    T->left = newnode;
    printf("Does %c has left child? ", c);
    printf("\n YES - 1 \n NO - 0 :: ");
    scanf("%d", &ch);
    if (ch == 1)
        insertLeft(newnode);
    else
        newnode->left = NULL;
    printf("Does %c has right child? ", c);
    printf("\n YES - 1 \n NO - 0 :: ");
    scanf("%d", &ch);
    if (ch == 1)
        insertRight(newnode);
    else
        newnode->right = NULL;
}
void insertRight(Tnode *T)
{
    Tnode *newnode;
    char c;
    int ch;
    newnode = (Tnode *)malloc(sizeof(Tnode));
    printf("Enter the value in the node : ");
    getchar();
    scanf("%c", &c);
    newnode->info = c;
    T->right = newnode;
    printf("Does %c has left child? ", c);
    printf("\n YES - 1 \n NO - 0 :: ");
    scanf("%d", &ch);
    if (ch == 1)
        insertLeft(newnode);
    else
        newnode->left = NULL;
    printf("Does %c has right child? ", c);
    printf("\n YES - 1 \n NO - 0 :: ");
    scanf("%d", &ch);
    if (ch == 1)
        insertRight(newnode);
    else
        newnode->right = NULL;
}
void preorder(Tnode *T)
{
    if (T != NULL)
    {
        printf(" %c", T->info);
        preorder(T->left);
        preorder(T->right);
    }
}
