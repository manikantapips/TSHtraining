#include<stdio.h>
void binaryofnum(int );
#define BITS sizeof(int)*8
int main(void){
	int num,nth,mask;
	printf("enter a number \n");
	scanf("%d",&num);
	printf("binary representation of %d\n",num);
	binaryofnum(num);
	printf("enter a bit position to clear \n");
	scanf("%d",&nth);
	mask=~(1<<nth);
	num=num&mask;
	printf("after clear %d bit \n",nth);
	binaryofnum(num);
	return 0;

}
void binaryofnum(int num){
	for(int i=(BITS-1);i>=0;i--){
		printf("%d",(num&(1<<i))?1:0);
	}
	printf("\n");
}
