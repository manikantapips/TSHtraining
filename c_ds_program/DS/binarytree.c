#include<stdio.h>
#include<stdlib.h>
struct node * create(void);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
struct node{
	int data;
	struct node *left,*right;
};
int main(void){
	struct node *root=NULL;
	root=create();
	printf("preorder:");
	preorder(root);
	printf("\n");
	printf("inorder:");
	inorder(root);
	printf("\n");
	printf("postorder:");
	postorder(root);
	printf("\n");
	return 0;
}

struct node * create(){
	int x;
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter data : enter -1 for no node\n");
	scanf("%d",&x);
	if(x==-1)
		return NULL;
	newnode->data=x;
	printf("enter left child of %d \n",x);
	newnode->left=create();
	printf("enter right child of %d \n",x);
	newnode->right=create();
	return newnode;
}

void preorder(struct node * root){
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node * root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
void inorder(struct node * root){
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);

}

















