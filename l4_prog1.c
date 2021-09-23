#include<stdio.h>
#include<omp.h>
int main(){
int x=0,y=0,z=0;
#pragma omp parallel shared(x) shared(y) shared(z)
{
#pragma omp critical
{
x=x+1;
printf("This is in Critical section value of x is %d and thread no is %d\n",x,omp_get_thread_num());
}
#pragma omp master
{
y=y+1;
printf("This is in Master section value of y is %d and thread no is %d\n",y,omp_get_thread_num());
}
#pragma omp single
{
z=z+1;
printf("This is in Single section value of z is %d and thread no is %d\n",z,omp_get_thread_num());
}
}
}