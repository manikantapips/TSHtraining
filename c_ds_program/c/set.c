#include<stdio.h>
int main(){
	int n,x;
	printf("enter x value\n");
	scanf("%d",&x);
	printf("enter n value\n");
	scanf("%d",&n);
	x=x|(1<<n);
	printf("%d",x);
return 0;
}
	
/* enter x value
12
enter n value
1
14
*/
