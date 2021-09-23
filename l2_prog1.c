#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main()
{
    int a[10], b[10], i, sum[10];
    for(i=0; i<10; i++)
    {
        printf("Enter values: ");
        scanf("%d%d", &a[i], &b[i]); 
    }
    
    #pragma omp parallel for
    for (i=0; i<10; i++)
    {
        sum[i] = a[i] + b[i];
        printf("CPU: %d\tThread: %d\tValue: %d\n", sched_getcpu(), omp_get_thread_num(), sum[i]);
    }
}