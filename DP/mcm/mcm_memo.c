#include<stdio.h>
#include<limits.h>
int dp[100][100];
int mcm(int i,int j,int a[]){
    
    if(dp[i-1][j]!=-1) 
        return dp[i-1][j];
    if(i==j)
        return dp[i-1][j]=0;
    int min=INT_MAX,val;
    
    for (int k = i; k < j; k++)
    {
        val=mcm(i,k,a)+mcm(k+1,j,a)+a[i-1]*a[k]*a[j];
    }
    if(val<min){
        min=val;
    }
    return dp[i-1][j]=min;
}
void main(){
    int i,j,n;
    printf("Enter no. of matrices");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter sizes of matrices");
    for(i=0;i<n+1;i++){
        for(j=0;j<n+1;j++){
            dp[i][j]=-1;
        }
    }
    for(i=0;i<n+1;i++)
        scanf("%d",&a[i]);
    int x=mcm(1,n,a);
    printf("%d",x);
}