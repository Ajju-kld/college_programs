#include<stdio.h>



//function for merge array by spliting it

void merge(int a[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1; 
    
    int n2=r-m;

     int L[n1],R[n2];
     for ( i = 0; i < n1; i++)
     {
         L[i]=a[l+i];
     }
     for ( i = 0; i < n2; i++)
     {
         R[i]=a[m+1+i];
     }
     i=0;
     k=l;
     j=0;
     while (i<n1&&j<n2)
     {
         if (L[i]<=R[j])
         {
             a[k]=L[i];
             i++;
         }
         else{
             a[k]=R[j];
             j++;
         }
         k++;

     }
     while (i<n1)
     {
         a[k]=L[i];
         i++;
         k++;
     }
     while (j<n2)
     {
         a[k] = R[j];
         j++;
         k++;
     }
     
     
     
     
}






void merge_Sort(int a[],int l,int r){
    int m;
    if (l>=r)
    {
        return;
    }
    m=(l+r)/2;
    merge_Sort(a,l,m);
    merge_Sort(a,m+1,r);
    merge(a,l,m,r);

}



void main(){
    FILE *fp;
    fp = fopen("/home/ajmal/projects/codes/c/array.txt","r");
    int count;
    fscanf(fp,"%d",&count);
    printf("enter the size of an array:%d\n",count);

    int array[count];
    printf("enter the elements in the array:\n");
    for (int  i = 0; i < count; i++)
    {
        fscanf(fp,"%d",&array[i]);
         printf("a[%d]=%d\n",i,array[i]);
    }

int l=0;
int r=count-1;

    merge_Sort(array,l,r);
    printf("after the merge sort: \n");
    for (int i = 0; i < count; i++)
    {
        printf("\t%d\t",array[i]);
    }
    
    fclose(fp);
}