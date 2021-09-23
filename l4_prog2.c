#include<stdio.h>
#include<omp.h>
int main(){
int value=0;
int n;
printf("the total no of times the loop should run : ");
scanf("%d",&n);
#pragma omp parallel sections shared(value)
{
#pragma omp section
{
for(int i=0;i<n;i++){
#pragma omp critical
{
if(value>=0){
value++;
}
printf("The value in PRODUCER system is %d and the thread no is %d\n",value,omp_get_thread_num());
}
}
}
#pragma omp section
{
for(int i=0;i<n;i++){
#pragma omp critical
{
if(value>0){
value--;
}
printf("The value in CONSUMER system is %d and the thread no is %d\n",value,omp_get_thread_num());
}
}
}
}
}