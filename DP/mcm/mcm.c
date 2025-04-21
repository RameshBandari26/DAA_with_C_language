#include<stdio.h>
#include<limits.h>
int mcm(int i,int j,int a[]){
    if(i==j)
        return 0;
    int min=INT_MAX,val;
    for (int k = i; k < j; k++)
    {
        val=mcm(i,k,a)+mcm(k+1,j,a)+a[i-1]*a[k]*a[j];
    }
    if(val<min){
        min=val;
    }
    return min;
}
void main(){
    int i,j,n;
    printf("Enter no. of matrices");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter sizes of matrices");
    for(i=0;i<n+1;i++)
        scanf("%d",&a[i]);
    int x=mcm(1,n,a);
    printf("%d",x);
}