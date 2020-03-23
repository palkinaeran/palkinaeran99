#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>
void *a()
{
int i,j,n;
printf("Enter the Value ");
scanf("%d",&n);
for(i=2;i<=n;i++)
{
int c=0;
for(j=1;j<=i;j++)
{
if(i%j==0)
{c++;}
}
if(c==2)
{printf("Prime Numbers Are :- %d \t",i);
}}}
int main()
{
pthread_t p;
pthread_create(&p,NULL,a,NULL);
pthread_join(p,NULL);
}


