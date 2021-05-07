#include<stdio.h>
void binaryofnum(int );
#define BITS sizeof(int)*8
int main(void){
	int num,nth,count=0;
	printf("enter a number \n");
	scanf("%d",&num);
	printf("binary representation of %d\n",num);
	binaryofnum(num);
	for(int i=(BITS-1);i>=0;i--){
		if(num&(1<<i))
			count++;
	}
	if(count==1)
		printf("given number is power of 2\n");
	else
		printf("number is not power of 2 \n");

	if((num&(num-1))==0)
		printf("given number is power of 2\n");
	return 0;

}
void binaryofnum(int num){
	for(int i=(BITS-1);i>=0;i--){
		printf("%d",(num&(1<<i))?1:0);
	}
	printf("\n");
}
