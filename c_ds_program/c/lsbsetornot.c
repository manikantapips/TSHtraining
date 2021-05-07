#include<stdio.h>
void binaryofnum(int );
#define BITS sizeof(int)*8
int main(void){
	int num,lsb;
	printf("enter a number \n");
	scanf("%d",&num);
	binaryofnum(num);
	lsb=1<<0;
	if(num&lsb)
		printf("lsb of %d is set",num);
	else
		printf("lsb of %d is not set",num);
	return 0;

}
void binaryofnum(int num){
	for(int i=(BITS-1);i>=0;i--){
		printf("%d",(num&(1<<i))?1:0);
	}
	printf("\n");
}		
