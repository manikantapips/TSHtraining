#include<stdio.h>
void insertionsort(int *);
int main(void){
	int a[10];
	printf("enter a array of 10 elements \n");
	for(int i=0;i<10;i++)
	scanf("%d",&a[i]);
	insertionsort(a);
	printf("afer sorting of array \n");
	for(int j=0;j<10;j++)
	printf("%d\t",a[j]);
	return 0;
}
void insertionsort(int *a){
	int temp,j;
	for(int i=1;i<10;i++){
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;

	}
}
