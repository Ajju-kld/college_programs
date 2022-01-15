//polynomial addition using array

#include <stdio.h>
void main()
{

  int n;
  int m;
  int k;
  printf("enter the degree of first polynomial:");
  scanf("%d", &n);
  printf("enter the degree of second polynomial: ");
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

  for (int i = 0; i <= m; i++)
  {

    printf("coefficent of x^%d: ", i);
    scanf("%d", &b[i]);
  }
  int c[100];
  if (m > n)
  {
    k = m;
  }
  else
  {
    k = n;
  }

  for (int i = 0; i <= k; i++)
  {

    c[i] = a[i] + b[i];
  }
  printf("sum:\n");
  for (int i = k - 1; i >= 0; i--)
  {
    if (i != 0)
      printf("\t%dx^%d\t+", c[i], i);
    else
      printf("\t%d\t", c[i]);
  }
}
