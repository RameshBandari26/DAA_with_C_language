//Knapsack 

#include<stdio.h>
struct wvalues{
    int x,y;
};
int b[100][100];
int max(int x,int y){
    if(x>y)
    return x;
    else 
    return y;
}
int ks(struct wvalues a[],int W,int n){
    if( b[n][W]!=-1)
        return b[n][W];
    if(n==0||W==0)
        return b[n][W]=0;
    else if(W<a[n-1].x)
        return b[n][W]=ks(a,W,n-1);
    else
        return b[n][W]=max(a[n-1].y+ks(a,W-a[n-1].x,n-1),ks(a,W,n-1));
}
int main(){
    printf("Enter total no.of weights: ");
    int n,i,W;
    scanf("%d",&n);
    struct wvalues a[n];
    printf("Enter bag weight: ");
    scanf("%d",&W);
    int b[n][W];
    printf("Enter weights and their respective values: ");
    for(i=0;i<n;i++){
      scanf("%d %d",&a[i].x,&a[i].y);
    }
    for(i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            b[i][j]=-1;
        }
    }
   printf("%d",ks(a,W,n));
}