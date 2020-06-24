#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

typedef struct tree
{
	struct node *root;
}tree;

node* create(int val)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void preOrder(node *root)
{
     printf("%d ",root->data);
     if(root->left)
     preOrder(root->left);
     if(root->right)
     preOrder(root->right);
}

void inOrder(node *root)
{
	 if(root->left)
     inOrder(root->left);
     printf("%d ",root->data);
     if(root->right)
     inOrder(root->right);
}

void postOrder(node *root)
{
	 if(root->left)
     postOrder(root->left);
     if(root->right)
     postOrder(root->right);
     printf("%d ",root->data);
}

int h = 0;

int calculate_height(node* root,int cur)
{
	if(cur > h)
		h = cur;
	if(root->left)
		calculate_height(root->left,cur+1);
	if(root->right)
		calculate_height(root->right,cur+1);
	return h;
}


// A function to calculate lowest common ancestor of two nodes
node* lca(node *root,int n1,int n2)
{
	if(root == NULL)
		return NULL;

	if(root->data == n1 || root->data == n2)
		return root;

	node *left_lca = lca(root->left,n1,n2);
	node *right_lca = lca(root->right,n1,n2);

	if(left_lca && right_lca)
		return root;

	if(left_lca)
		return left_lca;
	else
		return right_lca;
}

int main()
{
	/*
	                         14
	                    5          7
	                9      2   6       18
	                  0              15

	*/
	tree *T;
	T=(tree *)malloc(sizeof(tree));
	T->root = create(14);
	T->root->left = create(5);
	T->root->right = create(7);
	T->root->left->left = create(9);
	T->root->left->right = create(2);
	T->root->right->left = create(6);
	T->root->right->right = create(18);
	T->root->left->left->right = create(0);
	T->root->right->right->left = create(15);
	preOrder(T->root);   printf("\n");
	inOrder(T->root);   printf("\n");
	postOrder(T->root);   printf("\n");
	printf("Height of the tree is :- %d\n",calculate_height(T->root,0));
	printf("Lca of 0 & 2 is %d\n",lca(T->root,0,2)->data);
	return 0;
}
