/*quick sorting*/
#include<stdio.h>
#include<stdlib.h>
void q_sort(int a[],int low,int high);
void quick_sort(int a[],int );
void swap(int *,int *);

int main()
{
int a[100],size,i;
printf("enter size of array\n");
scanf("%d",&size);

printf("enter elements into the array\n");
for(i=0;i<size;i++)
scanf("%d",&a[i]);

quick_sort(a,size);

printf("the sorted array is \n");
for(i=0;i<size;i++)
printf("%d\n",a[i]);

return 0;
}

void quick_sort(int a[],int size)
{
q_sort(a,0,size-1);
}

void q_sort(int a[],int low,int high)
{
int i,j,pivot_index;
	if(low<high)
	{
		pivot_index=low;
		i=low+1;
		j=high;

			for(;;)
			{
				while(a[i]<a[pivot_index]&&i<=high)
				i++;
				while(a[j]>a[pivot_index]&&j>=low+1)
				j--;
				if(i<j)
				swap(&a[i],&a[j]);

				else
				break;
			}

		swap(&a[j],&a[pivot_index]);
		q_sort(a,low,j-1);
		q_sort(a,j+1,high);
	}
}




void swap(int *x,int *y)
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}











