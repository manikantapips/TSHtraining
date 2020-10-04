#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int *m,*c,*r;
	m=(int *)malloc(20);
	printf("value of m is %p\n",m);
	printf("value at m is %d\n",*m);
	c=(int *)calloc(5,sizeof(int));
	printf("value of c is %p\n",c);
	printf("value at c is %d\n",*c);
	r=(int *)realloc(m,25);
	printf("value of r is %p\n",r);
	printf("value at r is %d\n",*r);
	return 0;
}
