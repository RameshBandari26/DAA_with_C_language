#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int,int,int);
void merge_sort(int a[],int,int);
int main()
{
	int a[100];
	int i,n ;
	printf("Enter the number of elements in the array \n");
	scanf("%d",&n);
	printf("Enter %d numbers\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge_sort(a,0,n-1);
	printf("The sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void merge(int a[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,k=beg,temp[100],l;
	while((i<=mid)&&(j<=end))
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			i++;
			k++;
		}
		else{
			temp[k]=a[j];
			j++;
			k++;
		}
	}
	if(i>mid){
		while(j<=end)
		{
			temp[k]=a[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid)
		{
			temp[k]=a[i];
			i++;
			k++;
		}
	}
	for(l=beg;l<k;l++)
		a[l]=temp[l];
}

void merge_sort(int a[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		merge_sort(a,beg,mid);
		merge_sort(a,mid+1,end);
		merge(a,beg,mid,end);
	}
}
