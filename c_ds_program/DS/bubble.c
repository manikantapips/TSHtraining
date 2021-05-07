#include<stdio.h>
void bubblesort(int *);
int main(void){
	int a[10];
	printf("enter a array of 10 elements \n");
	for(int i=0;i<10;i++)
	scanf("%d",&a[i]);
	bubblesort(a);
	printf("afer sorting of array \n");
	for(int j=0;j<10;j++)
	printf("%d\t",a[j]);
	return 0;
}
void bubblesort(int *a){
	int temp;
	for(int i=0;i<10;i++){
		for(int j=0;j<10-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				}
		}
	}	
}

