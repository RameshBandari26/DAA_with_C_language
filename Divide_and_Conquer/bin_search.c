#include<stdio.h>
int binary(int a[],int start,int last,int search){
    int mid;
    while(start<=last){
        mid=(start+last)/2;
        if(search==a[mid])
            return mid;
        else if(search<a[mid])
            last=mid-1;
        else if(search>a[mid])
            start=mid+1;
    }
    return -1;
}

int main(){
    int n,i,search;
    printf("Array size: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter key element to search:");
    scanf("%d",&search);
    int result=binary(a,0,n-1,search);
    printf("Found in the index of %d",result);
}
