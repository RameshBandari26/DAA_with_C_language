#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point
{
    int x;
    int y;
};
int main()
{
    int n,i,j,X1,X2,Y1,Y2;
    float d,max=0.00,avg,sum;
   struct point *p;
   printf("Enter How many points going to enter?:");
   scanf("%d",&n);
   p=(struct point*) malloc(n*sizeof(struct point));
   printf("Enter points:");
   for(i=0;i<n;i++)
   {
    scanf("%d %d",&(p+i)->x,&(p+i)->y);
   }
   for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
    {
        d=sqrt(pow(((p+i)->x-(p+j)->x),2)+pow(((p+i)->y-(p+j)->y),2));
        sum=sum+d;
        printf("%f ,",d);
    }
    avg=sum/(n-1);
    if(max<avg)
        {
            max=avg;
            X1=(p+i)->x;
            Y1=(p+i)->y;
        }
   }
   printf("The nearer point distance is: %f\n",max);
   printf("The nearer points are \n x1=%d,y1=%d\n",X1,Y1);
}
