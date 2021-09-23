#include<omp.h>
#include<stdio.h>

int main()
{
	int n;
	printf("Enter number of objects:");
	scanf("%d",&n);
	int ar[n], sum[n];
	printf("Enter array:");
	for(int i=0; i<n; i++)
	{
		scanf("%d",&ar[i]);
		sum[i]=0;
	}
	#pragma omp parallel for
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(ar[j]%ar[i]==0)
				sum[i]=sum[i]+ar[j];
		}
		printf("\nSum of factors of %d= %d\n",ar[i],sum[i]);
	}
}