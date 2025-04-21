//Coin-change with memorization

#include<stdio.h>
#include<string.h>
int cc(int n,int sum,int wt[])
{
	int a[n+1][sum+1];
	memset(a,-1,sizeof(a));
	if(a[n][sum]!=-1)
	{
		return a[n][sum];
	}
	if(n==0)
		return a[n][sum]=0;
	if(sum==0)
		return a[n][sum]=1;
	if(wt[n-1]<=sum)
	{
		return a[n][sum]=cc(n,sum-wt[n-1],wt)+cc(n-1,sum,wt);
	}
	else
		return a[n][sum]=cc(n-1,sum,wt);
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
	
