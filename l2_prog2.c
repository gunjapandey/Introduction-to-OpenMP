#include <stdio.h>
#include <omp.h>
int main()
{
int i=10;
int j;
#pragma omp parallel for firstprivate(i)
for(j=0;j<8;j++)
{
i=j+i;
printf("i=%d\tThread=%d\n",i,omp_get_thread_num());
}
printf("%d\n",i);
}
