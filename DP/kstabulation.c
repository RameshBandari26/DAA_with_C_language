//Knapsack Tabulation

#include<stdio.h>
float a[100][100];
int val[100];
int wt[100];
float max(float x,float y){
    if(x>y)
    return x;
    else 
    return y;
}
float ks(int n,int w){
    a[n+1][w+1];
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=w;j++){
            a[i][j]=0;
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=w;j++){
        if(i==0||j==0)
        a[i][j]=0;
        else if(j<wt[i-1]){
        a[i][j]=a[i-1][j];
        }
        else
        a[i][j]=max(val[i-1]+a[i-1][j-wt[i-1]],a[i-1][j]);
        }
    }
    printf("%f",a[n][w]);
}
int main(){
    printf("Enter no.of Weights: ");
    int n,w;
    scanf("%d",&n);
    printf("Enter bag Weight: ");
    scanf("%d",&w);
    printf("Enter weights: ");
    wt[n],val[n];
    for(int i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }
    printf("Enter values: ");
    for(int i=0;i<n;i++){
        scanf("%d",&val[i]);
    }
    ks(n,w);
}