//No. of ways to claim the stairs

#include<stdio.h>
int fib(int n){
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}
int countWays(int a){
    return fib(a+1);
}
int main(){
    int a;
    printf("Enter the total no. of stairs:");
    scanf("%d",&a);
    printf("Number of ways =%d\n",countWays(a));
}