#include <stdio.h>
#include <omp.h>
int main()
{
 int a[]={1,2,4,7,9};
 int i,b=0;
 #pragma omp parallel for reduction(+:b)
 for(i=0;i<5;i++){
 b=(a[i]*a[i])+b;
 printf("Thread:%d : Array Sum = %d\n",omp_get_thread_num(),b);
}
printf("Total Sum of Array : %d\n",b);
}