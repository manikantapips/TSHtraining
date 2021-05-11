#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void peek(struct node **f);
void dequeue(struct node **f,struct node **r1);
void display(struct node **f);
void enqueue(struct node **f,struct node **r1,int n);
void count(struct node **f);
void main()
{
int n;

struct node *front=NULL;
struct node *rear=NULL;
int choice;
while(1)
{
printf("enter any choice\n");
printf("1.enqueue\t 2.dequeue\t3.display\t4.peek\t5.count\t6.exit\n");
scanf("%d",&choice);

switch(choice)
{

case 1:printf("enter number to add\n");
	scanf("%d",&n);
	enqueue(&front,&rear,n);
	break;
case 2:dequeue(&front,&rear);
	break;
case 3:display(&front);
	break;
case 4:peek(&front);
	break;
case 5:count(&front);
	break;
case 6:exit(1);
}
}
}
void enqueue(struct node **f,struct node **r1,int n)
{
	struct node *temp,*temp1;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=NULL;
	if((*f==NULL))
	{

		*f=temp;
		*r1=temp;
//temp->next=NULL;
	}
	else
	{
		temp1=*r1;
	temp1->next=temp;
	*r1=temp;

	}
	}
void dequeue(struct node **f,struct node **r1)
{
struct node *temp;
temp=*f;
*f=temp->next;
free(temp);
if(*f==NULL)
{
*r1=NULL;
}
}
void display(struct node **f)
{
	struct node *temp;
	temp=*f;
	if(temp==NULL)
		{
		printf("queue is empty");

		}
		else
		{
			while(temp->next!=NULL)
			{
				printf("%d\t",temp->data);
				temp=temp->next;
			}
			printf("%d\t",temp->data);
			}
}
void peek(struct node **f)
{
struct node *temp;
temp=*f;
if(temp!=NULL)
{
printf("%d\t",temp->data);
}
}
void count(struct node **f)
{
struct node *temp;
temp=*f;
int count1=0;
while(temp!=NULL)
{
count1++;
temp=temp->next;
}
printf("%d",count1);
}
/*
enter any choice
1.enqueue	 2.dequeue	3.display	4.peek	5.count	6.exit
1
enter number to add
1
enter any choice
1.enqueue	 2.dequeue	3.display	4.peek	5.count	6.exit
1
enter number to add
2
enter any choice
1.enqueue	 2.dequeue	3.display	4.peek	5.count	6.exit
1
enter number to add
3
enter any choice
1.enqueue	 2.dequeue	3.display	4.peek	5.count	6.exit
3
1	2	3	enter any choice
1.enqueue	 2.dequeue	3.display	4.peek	5.count	6.exit
2
enter any choice
1.enqueue	 2.dequeue	3.display	4.peek	5.count	6.exit
3
2	3	enter any choice
1.enqueue	 2.dequeue	3.display	4.peek	5.count	6.exit
4
2	enter any choice
1.enqueue	 2.dequeue	3.display	4.peek	5.count	6.exit
5
2 
*/
