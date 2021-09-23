#include<stdio.h>
#include<omp.h>
void main(){
int a,b=12,c=3,i;
#pragma omp parallel sections
{
#pragma omp section
{ a=c+b;
printf("Thread: %d : Value of 12+3 =%d\n",omp_get_thread_num(),a);
}
#pragma omp section
{ a=b-c;
printf("Thread: %d : Value of 12-3 =%d\n",omp_get_thread_num(),a);
}
#pragma omp section
{ a=c*b;
printf("Thread: %d : Value of 12*3 =%d\n",omp_get_thread_num(),a);
}
#pragma omp section
{ a=b/c;
printf("Thread: %d : Value of 12/3 =%d\n",omp_get_thread_num(),a);
}
}
}