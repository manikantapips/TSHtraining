#include<stdio.h>
#include"cal.h"
int main(void)
{
	int o;
	int a,b;
	printf("enter a and b values \n");
	scanf("%d%d",&a,&b);
	printf("1.additon 2.subtraction 3.multiplication 4.division \n");
	printf("enter your option\n");
	scanf("%d",&o);
	switch(o){
			case 1: 
				printf("addition of a and b is %d",add(a,b));
				break;
			case 2:
				printf("subtraction of a and b is %d",sub(a,b));
				break;
			case 3:
				printf("multiplication of a and b is %d",mul(a,b));
				break;
			case 4:
				printf("division  of a and b is %d",div(a,b));
				break;
			default:
				printf("wrong option");
				break;
		}
		return 0;
}
