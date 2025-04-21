//fibanaci memorization

#include<stdio.h>
int fib(int b[],int n){
    if(b[n]!=-1)
        return b[n];
    else if(n==0)
        return b[n]=0;
    else if(n==1)
        return b[n]=1;
    else
        return b[n]=fib(b,n-1)+fib(b,n-2);
}
int main(){
    int a,n;
    printf("Enter size: ");
    scanf("%d",&n);
    int b[n+1];
    for(int i=0;i<=n;i++){
        b[i]=-1;
    }
    a=fib(b,n);
    printf("%d\n",a);
    for(int i=0;i<n;i++){
        printf("%d  ",b[i]);
    }
}