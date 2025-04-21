//knapsack 

#include<stdio.h>
struct wvalues{
    int x,y;
};
int max(int x,int y){
    if(x>y)
    return x;
    else 
    return y;
}
int ks(struct wvalues a[],int W,int n){
    if(n==0||W==0)
    return 0;
    else if(W<a[n-1].x)
    return ks(a,W,n-1);
    else
    return max(a[n-1].y+ks(a,W-a[n-1].x,n-1),ks(a,W,n-1));
}
int main(){
    printf("enter total no.of weights: ");
    int n,i,W;
    scanf("%d",&n);
    struct wvalues a[n];
    printf("Enter bag weight: ");
    scanf("%d",&W);
    printf("Enter weights and their respective values: ");
    for(i=0;i<n;i++){
      scanf("%d %d",&a[i].x,&a[i].y);
    }
   printf("%d",ks(a,W,n));
}