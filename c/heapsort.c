#include<stdio.h>
#include<stdlib.h>
void heapify(int a[],int size,int index);
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}


void heapify(int a[],int size,int index)
{

  
int left=2*index+1;
int right=2*index+2;
int large=index;
if (left<size&&a[large]<a[left])
{
  large=left;
}
if (right<size&&a[large]<a[right])
{
  large=right;
}



if (large!=index)
{ 
 swap(&a[large],&a[index]);
heapify(a,size,large);
}



}
void build(int a[],int n)
 {
   for (int i = n/2; i >=0; i--)
{
heapify(a,n,i);

}

}


void heapsort(int a[],int size)
{
  build(a,size);

  for (int i =size-1; i >=0; i--)
  {
  swap(&a[i],&a[0]);
    heapify(a,i,0);

  }
  
}

void main(){

 int count;
 printf("enter the size of the array:");
 scanf("%d",&count);
 int a[count];
 printf("enter the array elements:");
 for (int i = 0; i < count; i++)
 {
   printf("%d:",i);
   scanf("%d",&a[i]);
 }

 for (int i = 0; i < count; i++)
 {
   printf("%d\t", a[i]);
 }

 printf("\nsorted array\n");
heapsort(a,count);
for (int i = 0; i < count; i++)
{
  printf("%d\t", a[i]);
}
}