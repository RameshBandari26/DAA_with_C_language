//Brute force

struct point{
    int x,y;
};
#include<stdio.h>
#include<math.h>
#include<limits.h>
void main(){
    int n;
    printf("How many point going to enter :");
    scanf("%d",&n);
    struct point p[n];
    int i,j,x1,y1,x2,y2;
    printf("Enter points");
    for(i=0;i<n;i++){
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    int min=INT_MAX;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            int d=sqrt(pow((p[i].x-p[j].x),2)+pow((p[i].y-p[j].y),2));
            if(d<min){
                min=d;
                 x1=p[i].x;
                 x2=p[j].x;
                 y1=p[i].y;
                 y2=p[j].y;
            }
        }
    }
    printf("the closest pair distance is %d",min);
    printf("\n");
    printf("points are (%d,%d) and (%d,%d)",x1,y1,x2,y2);

}