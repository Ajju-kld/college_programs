
// polynomial multiplication using array

#include <stdio.h>
void main()
{

   int n;
   int m;
   printf("enter the degree of first: ");
   scanf("%d", &n);
   printf("enter the second:");
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
   int c[m+n];
   for (int i = 0; i <(m*n); i++)
   {
      c[i] = 0;
   }

   int k;

   for (int i = 0; i <=n; i++)
   {
      for (int j = 0; j<=m; j++)
      {
         k = a[i] * b[j];
         c[i + j] = c[i + j] + k;
      }
   }
   k=(m+n);
   for (int i=k; i>=0; i--)
   {

      if(i!=0)
        printf("\t%dx^%d\t+",c[i],i);
        else
        printf("\t%d\t",c[i]);
        
   }
}