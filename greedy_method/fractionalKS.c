#include<stdio.h>
#include<limits.h>
int wt[100],val[100];
float ratio[100];
void sort(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
       if(ratio[j]<ratio[j+1]){
        int temp=ratio[j];
        ratio[j]=ratio[j+1];
        ratio[j+1]=temp;

         temp=val[j];
         val[j]=val[j+1];
         val[j+1]=temp;

         temp=wt[j];
         wt[j]=wt[j+1];
         wt[j+1]=temp;
       }
        }
    }
    //  for(i=0;i<n;i++){
    //      printf("%f ",ratio[i]);
    //      printf("\n");
    //  }
}
float knapsack(int W,int n){
    float value=0;
    for(int i=0;i<n;i++){
        if(wt[i]<=W){
           value+=val[i];
           W-=wt[i]; 
        }
        else{
            value+=(float)W / wt[i] *val[i];
            break;
        }
    }
    return value;
}
void main(){
    int n,i;
    printf("Enter no.of items");
    scanf("%d",&n);
    wt[n];
    val[n];
    printf("Enter weights and corresponding values");
    for(i=0;i<n;i++){
        scanf("%d%d",&wt[i],&val[i]);
    }
    ratio[n];
    for(i=0;i<n;i++){
        ratio[i]=(val[i]/wt[i]);
        // printf("%d ",ratio[i]);
    }
    // for(i=0;i<n;i++){
    //     printf("%f ",ratio[i]);
    //  }
    printf("Enter Sack capacity");
    int capacity;
    scanf("%d",&capacity);
    sort(n);
    printf("%f is the maximum profit",knapsack(capacity,n));
}







/*
Enter no.of items3
Enter weights and corresponding values10 60 
20 100
30 120
Enter Sack capacity50
240.000000 is the maximum profit
*/