// Convex Hull

#include<stdio.h>
#include<math.h>
int main(){
    struct point{
        int x,y;
    };
    int n,i,j,a,b,k,count=0,c;
    printf("Enter the no. of points:");
    scanf("%d",&n);
    struct point p[n];
    printf("Enter the points: ");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&p[i].x,&p[i].y);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            a=p[i].y-p[j].y;
            b=p[j].x-p[i].x;
            c=(p[j].x*p[i].y)-(p[i].x*p[j].y);
            int np=0,nn=0;
            for(k=0;k<n;k++){
                int val=a*p[k].x+b*p[k].y-c;
                if(val>0)
                np++;
                else if(val<0)
                nn++;
            }
            if(np==0||nn==0){
                count++;
                printf("(%d,%d),(%d,%d) are in convex hall \n",p[i].x,p[i].y,p[j].x,p[j].y);
            }
        }
    }
    printf("No. of edges=%d",count);
}