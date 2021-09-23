#include<omp.h>
#include<stdio.h>
main()
{
int i;
int a[10],b[10];
int sum[10];
for(i=0;i<10;i++){
printf("Enter value of a at index %d ",i);
scanf("%d",&a[i]);
printf("Enter value of b at index %d ",i);
scanf(" %d",&b[i]);
}
#pragma omp parallel for schedule(dynamic,1)
for(i=0;i<10;i++){
sum[i]=a[i]+b[i];
printf("CPU:%d \t Thread:%d\t Value:%d where index is:%d\n",sched_getcpu(),omp_get_thread_num(),sum[i],i);
}
}