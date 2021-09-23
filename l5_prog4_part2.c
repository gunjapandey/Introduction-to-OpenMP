#include<omp.h>
#include<stdio.h>

int main()
{
	int n;
	printf("Enter Number of Objects:");
	scanf("%d",&n);
	int ar[n];
  	
  	printf("Enter array:");
	for(int i=0; i<n; i++)
  		scanf("%d",&ar[i]);
  
  	int even=0,odd=0;
  	#pragma omp parallel for firstprivate(n) schedule(dynamic,2)
  	for(int i=0;i<n;i++)
  	{
  		if(ar[i]%2==0)
  			even=even+ar[i];
  		else
  			odd=odd+ar[i];
  	}
  	printf("\nEven numbers sum: %d",even);
  	printf("\nOdd numbers sum: %d\n",odd);
}
