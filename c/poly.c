#include <stdio.h>

#include "poly.h"

poly *p1 = NULL, *q1 = NULL, *r1 = NULL;

void main()
{

    int n, coe, exp, a;
    printf("polynomial representation\n");

    printf("enter the no of elements in polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter the coefficent:");
        scanf("%d", &coe);
        printf("enter the exponential:");
        scanf("%d", &exp);
        p1 = add(p1, coe, exp);
        printf("\n");
    }

    printf("enter the no of element in 2nd polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter the coefficent:");
        scanf("%d", &coe);
        printf("enter the exponential:");
        scanf("%d", &exp);
        q1 = add(q1, coe, exp);
        printf("\n");
    }
    printf("addition of 2 polynomial\n");

    printf("\n\n");
    display(addition(p1, q1, r1));
    printf("\nmutliplication of polynomial\n\n");
    display(multiplication(p1, q1, r1));
}
