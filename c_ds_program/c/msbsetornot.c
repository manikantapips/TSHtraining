#include<stdio.h>
void binaryofnum(int );
#define BITS sizeof(int)*8
int main(void){
	unsigned int num,msb;
	printf("enter a number \n");
	scanf("%u",&num);
	binaryofnum(num);
	msb=1<<(BITS-1);
	if(num&msb)
		printf("msb of %d is set",num);
	else
		printf("msb of %d is not set",num);
	return 0;

}
void binaryofnum(int num){
	for(int i=(BITS-1);i>=0;i--){
		printf("%d",(num&(1<<i))?1:0);
	}
	printf("\n");
}
