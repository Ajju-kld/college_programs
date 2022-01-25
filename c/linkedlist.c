#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
   struct node *next;
};

struct node *header=NULL,*tail=NULL;


void add(int data){

 struct node *newnode;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=data;
 newnode->next=NULL;
 if(header==NULL)
 {
     header=newnode;
     tail=newnode;
 }
else{
    tail->next=newnode;
    tail=newnode;
}




}
void display(){

 
struct node *current=header;

  if(header== NULL){

  printf("list is empty");

  }

else {while(current!=NULL)
{

  printf("%d\t",current->data);
  current=current->next;




}
}

}




void main(){

  int size,a;
  printf("enter the number of nodes to be created : ");
  scanf("%d",&size);
 for (int i = 0; i < size; i++)
 {
     printf("type the number to be added :");
     scanf("%d",&a);
     add(a);

 }
 
  display();



}
