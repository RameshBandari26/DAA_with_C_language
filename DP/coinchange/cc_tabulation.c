//Coin-change with Tabulation

#include<stdio.h>
#include<string.h>
int cc(int n,int sum,int wt[])
{
	int a[n+1][sum+1];
	memset(a,-1,sizeof(a));
	for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
			if (j==0){
                a[i][j]=1;
                continue;
            }
            if (i==0){
                a[i][j]=0;
                continue;
            }
			if(wt[i-1]<=j)
			{
				a[i][j]=a[i][j-wt[i-1]]+a[i-1][j];
			}
			else
				a[i][j]=a[i-1][j];
		}
	}
	return a[n][sum];
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
	
