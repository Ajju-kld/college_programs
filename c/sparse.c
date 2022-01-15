
//sparse matrix addition by reading input from files
#include <stdio.h>
struct sparse
{
    int row;
    int col;
    int value;
} a[100], b[100], c[100];

int main()
{
    int row1, col1, row2, col2, n, m, i;
    FILE *fp;
    fp = fopen("/home/ajmal/projects/codes/c/test.txt", "r");
    printf("enter the order of first matrix");
    fscanf(fp, "%d%d", &row1, &col1);
    printf("%dx%d", row1, col1);
    printf("enter the number of non zero elements in first matrix:");
    fscanf(fp, "%d", &n);
    printf("%d\n",n);
    printf("enter the details of first matrix:\n");

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &a[i].row);
        printf("enter the row no:%d\n", a[i].row);
        fscanf(fp, "%d", &a[i].col);
        printf("enter the col no:%d\n", a[i].col);
        fscanf(fp, "%d", &a[i].value);
        printf("enter the value:%d\n", a[i].value);
    }
    printf("enter the order of second matrix:");
    fscanf(fp, "%d%d", &row2, &col2);
    printf("%dx%d\n", row2, col2);
    printf("enter the number of non zero elements in 2nd matrix: ");
    fscanf(fp, "%d", &m);
    printf("%d\n", m);
    printf("enter the details of second matrix:\n");

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &b[i].row);
        printf("enter the row no :%d\n", b[i].row);
        fscanf(fp, "%d", &b[i].col);
        printf("enter the col no :%d\n", b[i].col);
        fscanf(fp, "%d", &b[i].value);
        printf("enter the value :%d\n", b[i].value);
    }
    if(row1!=row2&&col1!=col2){
        printf("addition is not possible ");
        return 0;
    }


     i = 0;
     int j = 0,k = 0;
    while (i < n && j < m)
    {
        if (a[i].row == b[j].row)
        {

            if (a[i].col == b[j].col)
            {
                c[k].row = a[i].row;
                c[k].col = a[i].col;
                c[k].value = a[i].value + b[j].value;
                i++, j++;
                k++;
            }

            else if (a[i].col > b[j].col)
            {
                c[k].row = b[j].row;
                c[k].col = b[j].col;
                c[k].value = b[j].value;
                k++;
                j++;
            }
            else
            {
                c[k].row = a[i].row;
                c[k].col = a[i].col;
                c[k].value = a[i].value;
                i++;
                k++;
            }
        }
        else if (a[i].row < b[j].row)
        {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].value = a[i].value;
            i++;
            k++;
        }
        else
        {

            c[k].row = b[j].row;
            c[k].col = b[j].col;
            c[k].value = b[j].value;
                             j++;
            k++;
        }
    }
    while (i < n)
    {
        c[k].row = a[i].row;
        c[k].col = a[i].col;
        c[k].value = a[i].value;
        i++;
        k++;
    }

    while (j < n)
    {
        c[k].row = b[j].row;
        c[k].col = b[j].col;
        c[k].value = b[j].value;
                         j++;
        k++;
    }
printf("si | row | col | value\n");
for (int  i = 0; i < k; i++)
{
    printf("%d | %d | %d | %d |\n",i,c[i].row,c[i].col,c[i].value);
}



    fclose(fp);
return 0;
}