#include<stdio.h>
void selectionsort(int *,int,int);
void swap(int* ,int* );
int main(void){
	int i, count, number[25];
	printf("Enter some elements (Max. - 25): ");
	scanf("%d",&count);
	printf("Enter %d elements: ", count);
	for(i=0;i<count;i++)
	scanf("%d",&number[i]);
	selectionsort(number,0,count);
	printf("The Sorted Order is: ");
	for(i=0;i<count;i++)
	printf(" %d",number[i]);
	return 0;
}
void selectionsort(int *a,int lb,int ub){
	for(int i=0;i<ub-1;i++){
		int min=i;
		for(int j=i+1;j<ub;j++){
			if(a[j]<a[min])
				min=j;
		}
	if(min!=i)
		swap(&a[i],&a[min]);
	}
}
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
