//Divide and conquer

struct point
{
    int x,y;
};
#include<stdio.h>
#include<math.h>
void quicksort(struct point p[], int start,int end){  
    if(start<end){
        int i=start,j=end;
        int pivot=start;
        while(i<j){
            while(p[pivot].x<p[j].x){j--;}
            while(p[pivot].x>=p[i].x){i++;}
            if(i<j){
                struct point t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
        struct point temp=p[j];
        p[j]=p[pivot];
        p[pivot]=temp;
        quicksort(p,0,j-1);
        quicksort(p,j+1,end);
    }
}

float brute(struct point p[],int start,int end){
    int i,j,x1,x2,y1,y2;
    float min=1000;
    for(i=0;i<end;i++){
        for(j=i+1;j<end+1;j++){
            float d=sqrt(pow((p[i].x-p[j].x),2)+pow((p[i].y-p[j].y),2));
            if(d<min){
                min=d;
                 x1=p[i].x;
                 x2=p[j].x;
                 y1=p[i].y;
                 y2=p[j].y;
            }
        }
    }
 
    return min;
}
float closest(struct point p[],int start,int end){
    float d;
    if((end-start>=2)||(end>start+1)){
        int mid=(start+end)/2;
        float left=closest(p,start,mid);
        float right=closest(p,mid+1,end);
        d=(left>right)?left:right;
    }
    else{
        d=brute(p,start,end);    
    }
    return d;
}
void main()
{
    int i,n;
    printf("How many point are you going to enter: ");
    scanf("%d",&n);
    struct point p[n];
    printf("Enter points :\n");
    for(i=0;i<n;i++){
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    quicksort(p,0,n-1);
    for(i=0;i<n;i++){
        printf("%d %d",p[i].x,p[i].y);
        printf("\n");
    }
    printf("%f\n",closest(p,0,n-1));
}
