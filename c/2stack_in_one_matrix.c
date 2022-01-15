#include<stdio.h>
int top1=-1;int top2;

void push1(int a[],int item);
void push2(int a[],int item);
void pop1(int a[]);
void pop2(int a[],int size);

void push1(int a[],int item){
if(top1+1==top2){

printf("overflow");
}
else{
    top1=top1+1;
    a[top1]=item;
    printf("element added sucessfully");
    
}

}

void push2(int a[],int item){
if(top1+1==top2){

printf("overflow");
}
else{
    top2=top2-1;
    a[top2]=item;
    printf("element added sucessfully");
    
}

}
void pop1(int a[])
{

if(top1==-1)
printf("underflow");
else{
    int item =a[top1];
    top1=top1-1;
    printf("the element %d is removed from the stack",item);
}

}

void pop2(int a[],int size)
{

if(top2==size)
printf("underflow");
else{
    int item =a[top2];

    top2=top2+1;
    printf("the element %d is removed from the stack",item);






}

}


void main(){
 int size;
 printf("enter the size of the stack: ");
 scanf("%d",&size);
 int stack[size];
 top2=size;
 int i,item;
 int option;
    int ans;

    do
    {

        printf("1.Stack one \n2.Stack two\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:   
         printf("1.push operation\n2.pop operation\n3.Display the stack\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("enter the number to be inserted: ");
            scanf("%d", &item);
            push1(stack,item);

            break;
        case 2:
        
            pop1(stack);

            break;
        case 3:
            for (i = top1; i >= 0; i--)
            {

                printf("%d\n", stack[i]);
            }

            break;
        default:
            printf("invalid choice");
            break;
        }
             
            break;
        case 2:
        printf("1.push operation\n2.pop operation\n3.Display the stack\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("enter the number to be inserted: ");
            scanf("%d", &item);
            push2(stack,item);

            break;
        case 2:
        
            pop2(stack,size);

            break;
        case 3:
            for (i = size; i >top2; i--)
            {

                printf("%d\n", stack[i]);
            }

            break;
        default:
            printf("invalid choice");
            break;
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