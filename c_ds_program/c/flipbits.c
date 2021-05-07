#include<stdio.h>
void binaryofnum(int );
#define BITS sizeof(int)*8
int main(void){
	int num,nth,mask;
	printf("enter a number \n");
	scanf("%d",&num);
	printf("binary representation of %d\n",num);
	binaryofnum(num);
	for(int i=(BITS-1);i>=0;i--){
		num=num^(1<<i);
	}
	printf("after flip bits \n");
	binaryofnum(num);
	return 0;

}
void binaryofnum(int num){
	for(int i=(BITS-1);i>=0;i--){
		printf("%d",(num&(1<<i))?1:0);
	}
	printf("\n");
}
