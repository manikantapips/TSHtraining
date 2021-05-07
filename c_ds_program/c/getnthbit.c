#include<stdio.h>
void binaryofnum(int );
#define BITS sizeof(int)*8
int main(void){
	int num,nth,mask;
	printf("enter a number \n");
	scanf("%d",&num);
	printf("binary representation of %d ",num);
	binaryofnum(num);
	printf("enter a bit position to get \n");
	scanf("%d",&nth);
	mask=1<<nth;
	if(num&mask)
		printf("nth bit is 1 \n");
	else
		printf("nth bit is 0\n");
	return 0;

}
void binaryofnum(int num){
	for(int i=(BITS-1);i>=0;i--){
		printf("%d",(num&(1<<i))?1:0);
	}
	printf("\n");
}
