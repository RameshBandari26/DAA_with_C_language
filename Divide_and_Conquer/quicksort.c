#include<stdio.h>
void quick(int a[],int low,int high)
{
    int i,j,pivot,temp;
    if(low<high)
    {
        i=low;
        j=high;
        pivot=low;
        while(i<j)
        { 
            while(a[i]<=a[pivot])
                { i++; }
            while(a[j]>a[pivot])
                { j--;}
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[j];
        a[j]=a[pivot];
        a[pivot]=temp;
        quick(a,low,j-1);
        quick(a,j+1,high);
    }
}
int main()
{
    int n,i;
    printf("Enter the size of array :");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements :");
    for (i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
    }
    quick(a,0,n-1);
    printf("\n________SORTED ARRAY_________\n\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

