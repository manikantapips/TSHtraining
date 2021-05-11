#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void peek(struct node **q);
void push(struct node **q,int n);
void display(struct node **q);
void pop(struct node **q);
void count(struct node **q);
void main()
{
int n;
struct node *p=NULL;
struct node **q=&p;
int choice;
while(1)
{
printf("enter any choice\n");
printf("1.push\t 2.pop\t3.display\t4.peek\t5.count\t6.exit\n");
scanf("%d",&choice);

switch(choice)
{

case 1:printf("enter number to add\n");
	scanf("%d",&n);
	push(&p,n);
	break;
case 2:pop(&p);
	break;
case 3:display(&p);
	break;
case 4:peek(&p);
	break;
case 5:count(&p);
	break;
case 6:exit(1);
}
}
}
void push(struct node **q,int n)
{
struct node *temp;
temp=*q;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=n;
temp->next=*q;
*q=temp;
}
void pop(struct node **q)
{
struct node *temp,*temp1;
temp=*q;
if(temp==NULL)
{
printf("stack is empty\n");
}
else
{
*q=temp->next;
free(temp);
}
}
void display(struct node **q)
{
struct node *temp;
temp=*q;
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
}
void peek(struct node **q)
{
struct node *temp;
temp=*q;
if(temp!=NULL)
{
printf("%d\t",temp->data);
}
}
void count(struct node **q)
{
struct node *temp;
temp=*q;
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
1.push	 2.pop	3.display	4.peek	5.count	6.exit
1
enter number to add
1
enter any choice
1.push	 2.pop	3.display	4.peek	5.count	6.exit
1
enter number to add
2
enter any choice
1.push	 2.pop	3.display	4.peek	5.count	6.exit
3
2	1	enter any choice
1.push	 2.pop	3.display	4.peek	5.count	6.exit
2
enter any choice
1.push	 2.pop	3.display	4.peek	5.count	6.exit
3
1	enter any choice
1.push	 2.pop	3.display	4.peek	5.count	6.exit
4
1	enter any choice
1.push	 2.pop	3.display	4.peek	5.count	6.exit
5
1
*/
