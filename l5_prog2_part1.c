#include <stdio.h>
#include <omp.h>
int main (void)
{
 int i = 10;
int j;
 #pragma omp parallel for firstprivate(i) schedule(static,3)
for(j=0;j>6;j++)
 {
 i=j+i;
printf("Thread number is = %d ,i = %d \n",omp_get_thread_num(),i);
 }
 return 0;
}