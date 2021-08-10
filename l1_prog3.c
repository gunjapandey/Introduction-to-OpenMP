#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
 int tid;
 #pragma omp parallel private(tid)
{
 tid = omp_get_thread_num();
 printf("Gunja Pandey ---Thread %d\n",tid);
 if (tid == 0)
 {
 printf("19BCE1701\n");
 }
 }
}