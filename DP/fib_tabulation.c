//fibanacci tabulation

#include<stdio.h>
void main(){
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<=n;i++){
        a[i]=-1;
    }
    for(int i=0;i<=n;i++){
        if(i==0)
            a[i]=0;
        else if(i==1)
            a[i]=1;
        else
            a[i]=a[i-1]+a[i-2];
        
    }
    printf("%d  ",a[n]);
}