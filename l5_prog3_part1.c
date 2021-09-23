#include <stdio.h>
#include <omp.h>
int main (void)
{
 int i = 10;
int n;
printf("Enter value of n");
scanf("%d",&n);
int arr[10]={1,2,3,4,5,6,7,8,9,10};
printf("%d\n",arr[8]);
int fac_sum=0;
int j;
int start=1;
int factorial=0;
 #pragma omp parallel for firstprivate(fac_sum,start,factorial) schedule(static,2)
for(j=2;j<=n;j++){
 do{
factorial=j*start;
if(
factorial>=arr[9]){
break;
}
fac_sum=fac_sum+factorial;
start++;
}
while(factorial<arr[8]);
printf("Sum of factorials of %d is %d\n",j,fac_sum);
}
 return 0;
}