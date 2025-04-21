#include<stdio.h>
int main()
{
    int i,j,search,mid,size,temp,high,low;
    printf("enter array of size:\n");
    scanf("%d",& size);
    int arr[size];
    printf("enter array of elements:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(j=j+1;j<size;j++)
    {
        if(arr[i]>arr[j])
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    printf("enter search elements:\n");
    scanf("%d",&search);
    low=0,high=size-1;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(arr[mid]==search)
        {
            printf("%d is found at %d",search,mid);
            break;
        }
        else if(arr[mid]<search)
        {
            low=mid+1;
            high=size-1;
            mid=(high+low)/2;
        }
        else if(arr[mid]>search)
        {
            low=0;
            high=mid-1;
            mid=(high+low)/2;
        }
    }
}