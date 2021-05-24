#include <stdio.h>
int main()
{
	int  n,pos,res,temp;
	printf("enter the number of bits\n");
	scanf("%d",&n);
	printf("enter the position\n");//considering the 1st bit position starts with 0
	scanf("%d",&pos);
	res=-1<<pos; 
	temp=pos+n;
	res=(-1<<temp)^res;
	printf("the result is:%d",res);
return 0;
}

/*enter the number of bits
3
enter the position
3
the result is:56
*/
