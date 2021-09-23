#include <stdio.h>
#include <omp.h>
int main()
{
int a[]={1,2,4,7,9};
int i,cube;
#pragma omp parallel for lastprivate(i) schedule(dynamic,3)
for(i=0;i<5;i++){
cube=a[i]*a[i]*a[i];
printf("Thread:%d %d cube = %d\n",omp_get_thread_num(),a[i],cube);
}
printf("The max value of cube: %d\n",cube);
}
