#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partion(int l, int h, int a[l][h])
{
    int i,j,pivot;
    pivot=a[l][h];
    j=l-1;
    for (i = l; i <=h; i++)
    {
        if (a[i][h]<pivot)
        {
            j++;
            swap(&a[i][l],&a[j][h]);
        }
        
    }swap(&a[l][j+1],&a[l][h]);
    return (j+1);
}

void quicksort(int l, int h, int a[l][h])
{int p;
if (l<=h)
{
p=partion(l,h,a);
quicksort(l,p-1,a);
quicksort(p + 1,h,a);
/* code */

}


}


void main() {
    FILE *fp;
    fp = fopen("/home/ajmal/projects/codes/c/array.txt", "r");
    int row,col;
    fscanf(fp, "%d%d", &row,&col);
    printf("enter the size of an array:%d%d\n",row,col);

    int array[row][col];
    printf("enter the elements in the array:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            /* code */
        fscanf(fp, "%d", &array[i][j]);
        printf("a[%d][%d]=%d\n", i,j,array[i][j]);
        }
        
    }
    fclose(fp);
int l=0;
int h=col-1;

for (int i = 0; i < row; i++)
{
    for (int j = 0; j < col; j++)
    {
        printf("%4d", array[i][j]);
    }
    printf("\n");
}
    quicksort(l,h,array);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%4d",array[i][j]);
        }
        printf("\n");
        
    }
    
  
    
}