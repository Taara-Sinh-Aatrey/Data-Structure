#include<stdio.h>
#include<stdlib.h>
#include<climits>

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

node* insert(node* root,int val)
{
	if(root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->data = val;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	if(val < root->data)
	{
		root->left = insert(root->left,val);
	}
	else if(val > root->data)
	{
		root->right = insert(root->right,val);
	}

	return root;
}

int FINDMAX(node* root,int M)
{
	if(root->data >= M)
		M = root->data;
	if(root->left)
		M = FINDMAX(root->left,M);
	if(root->right)
		M = FINDMAX(root->right,M);
	return M;
}

node* Delete(node *root,int val)
{
	node *temp;
	if(root->data == val)
	{
		temp = root;
		if(root->left == NULL)
		{
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL)
		{
			root = root->left;
			free(temp);
		}
		else
		{
			int M = INT_MIN;
			M = FINDMAX(root->left,M);
			root->data = M;
			root->left = Delete(root->left,M);
		}
	}
	else if(val < root->data)
		root->left = Delete(root->left,val);
	else
		root->right = Delete(root->right,val);
	return root;
}

void inOrder(node *root)
{
	 if(root->left)
     inOrder(root->left);
     printf("%d ",root->data);
     if(root->right)
     inOrder(root->right);
}

int main()
{
	/*
	                            14
	                    5               18
	                2      7          15
	              0       6  9

	*/
	tree *T;
	T=(tree *)malloc(sizeof(tree));
	T->root = NULL;
	T->root = insert(T->root,14);
	T->root = insert(T->root,5);
	T->root = insert(T->root,7);
	T->root = insert(T->root,9);
	T->root = insert(T->root,2);
	T->root = insert(T->root,6);
	T->root = insert(T->root,18);
	T->root = insert(T->root,0);
	T->root = insert(T->root,15);
	inOrder(T->root);   printf("\n"); 
	

	T->root = Delete(T->root,0);
	inOrder(T->root);   printf("\n");

	T->root = Delete(T->root,18);
	inOrder(T->root);   printf("\n");

	T->root = Delete(T->root,5);
	inOrder(T->root);   printf("\n");


	return 0;
}
