#include<stdio.h>
#include<omp.h>
void main(){
int n1=0,n2=1,n3,i,number,fib[20];
int j,fact=1;
int c=0;
int k,fac,l,prime[20],d=0;
printf("\nEnter the number : ");
scanf("%d",&number);
#pragma omp parallel sections private(i)
{
#pragma omp section
{
for(i=2;i<number;++i)
{
n3=n1+n2;
fib[c]=n3;
c++;
n1=n2;
n2=n3;
}
printf("\n");
}
#pragma omp section
{
for(j=1;j<=number;j++){
fact=fact*j;
}
}
#pragma omp section
{
for(int l=2;l<=number;l++)
{
int values=0,k;
for(k=2;k<l;k++)
{
if(l%k==0)
values=1;
}
if(values==0)
{
prime[d]=l;
d++;
}
}
}
}
printf("\n%d Fibonacci Series nos : 0 1 ",number);
for(int ii=0;ii<c;ii++)
printf(" %d ",fib[ii]);
printf("\nFactorial of %d is: %d",number,fact);
printf("\nPrime Numbers upto %d: ",number);
for(int m=0;m<d;m++)
printf(" %d ",prime[m]);
}
