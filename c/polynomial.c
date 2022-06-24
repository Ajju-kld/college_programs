
// polynomial multiplication using array

#include <stdio.h>

void addition(int p1[],int p2[],int n,int m){
   int k,l,i;
   if (m > n)
   {
      k = m;
      l = n;
   }

   else
   {
      k = n;
      l = m;
   }
   int p3[k + 1];
   for (i = 0; i <= l; i++)
   {
      p3[i] = p1[i] + p2[i];
   }
   if (k == n)
   {
      for (i; i <= k; i++)
      {
         p3[i] = p1[i];
      }
   }
   else
   {
      for (i; i <= k; i++)
      {
         p3[i] = p2[i];
      }
   }

   for (int i = k; i >= 0; i--)
   {

      if (i != 0)
         printf("\t%dx^%d\t+", p3[i], i);
      else
         printf("\t%d\t", p3[i]);
   }
}

void multiplication(int a[],int b[],int n,int m)
{
   int c[m + n + 1];
   for (int i = 0; i <= (m + n); i++)
   {
      c[i] = 0;
   }

   int k;

   for (int i = 0; i <= n; i++)
   {
      for (int j = 0; j <= m; j++)
      {
         k = a[i] * b[j];
         c[i + j] = c[i + j] + k;
      }
   }
   k=(m+n);
   for (int i = k; i >= 0; i--)
   {

      if (i != 0)
         printf("\t%dx^%d\t+", c[i], i);
      else
         printf("\t%d\t", c[i]);
   }
}




void main()
{

   int n;
   int m;
   printf("enter the degree of first polynomial: ");
   scanf("%d", &n);
   printf("enter the degree of second polynomial:");
   scanf("%d", &m);

   int a[n+1];
   int b[m+1];
   printf("enter the element of first polynomial: \n");
   for (int i = 0; i <= n; i++)
   {

      printf("coefficent of x^%d: ", i);
      scanf("%d", &a[i]);
   }
   printf("enter the element of second polynomial:\n");

   for (int i = 0; i <=m; i++)
   {

      printf("coefficent of x^%d: ", i);
      scanf("%d", &b[i]);
   }

int choice;
printf("1.addition\n2.multiplication ::");
scanf("%d",&choice);


switch (choice)
{
case 1:addition(a,b,n,m);
   
   break;
case 2:multiplication(a,b,n,m);
break;
default:printf("invalid choice");
   break;
}

   
}