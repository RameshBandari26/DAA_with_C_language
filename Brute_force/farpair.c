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
    float d,max;
   struct point *p;
   printf("How many point going to enter :");
   scanf("%d",&n);
   p=(struct point*) malloc(n* sizeof(struct point));
   printf("Enter points");
   for(i=0;i<n;i++)
   {
    scanf("%d %d",&(p+i)->x,&(p+i)->y);
   }
   max=0.00;
   for(i=0;i<n-1;i++)
   {
    for(j=i+1;j<n;j++)
    {
        d=sqrt(pow(((p+i)->x-(p+j)->x),2)+pow(((p+i)->y-(p+j)->y),2));
        if(max<d)
        {
            max=d;
            X1=(p+i)->x;
            X2=(p+j)->x;
            Y1=(p+i)->y;
            Y2=(p+j)->y;
        }
    }
   }
   printf("The nearer point distance is: %f\n",max);
   printf("The nearer points are \n x1=%d, y1=%d \n x2=%d, y2=%d\n",X1,Y1,X2,Y2);
}
