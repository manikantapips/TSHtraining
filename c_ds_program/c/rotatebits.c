#include<stdio.h>
void binaryofnum(int );
void rightrotate(int num,int d);
void leftrotate(int,int);
#define BITS sizeof(int)*8
int main(void){
	int num,d;
	printf("enter a number \n");
	scanf("%d",&num);
	printf("enter how many bits to rotate \n");
	scanf("%d",&d);
	printf("binary representation of %d\n",num);
	binaryofnum(num);
	leftrotate(num,d);
	rightrotate(num,d);
	return 0;

}
void binaryofnum(int num){
	for(int i=(BITS-1);i>=0;i--){
		printf("%d",(num&(1<<i))?1:0);
	}
	printf("\n");
}
void leftrotate(int num,int d)
{
	num=(num<<d)|(num>>(BITS-d));
	printf("left roatation of number is :");
	binaryofnum(num);
}
void rightrotate(int num,int d)
{
	num=(num>>d)|(num<<(BITS-d));
	printf("right roatation of number is :");
	binaryofnum(num);
}

