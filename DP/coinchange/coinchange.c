//coin-change

#include<stdio.h>
#include<string.h>
int cc(int n,int sum,int wt[])
{
	if(n==0)
		return 0;
	if(sum==0)
		return 1;
	if(wt[n-1]<=sum)
	{
		return cc(n,sum-wt[n-1],wt)+cc(n-1,sum,wt);
	}
	else
		return cc(n-1,sum,wt);
}
int main()
{
	int n,sum;
	printf("Enter the no. of items: ");
	scanf("%d",&n);
	int wt[n];
	printf("Enter the values: ");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("Enter the sum :");
	scanf("%d",&sum);
	int c=cc(n,sum,wt);
	printf("The count of sum is : %d",c);
}
	
