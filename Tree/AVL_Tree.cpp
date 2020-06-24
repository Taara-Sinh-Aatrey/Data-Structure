#include<stdio.h>
#include<stdlib.h>
#include<climits>

int max(int a,int b)
{
	return a > b ? a : b;
}

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
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
	temp->height = 1;
	return temp;
}

int height(node *root)
{
	if(root)
		return root->height;
	return 0;
}

node* leftRotate(node *x)
{
	node *y = x->right;
	node *T = y->left;

	// perform left rotation
	y->left = x;
	x->right = T;

	x->height = 1 + max(height(x->left),height(x->right));
	y->height = 1 + max(height(y->left),height(y->right));

	return y;
}

node* rightRotate(node *x)
{
	node *y = x->left;
	node *T = y->right;

	// perform left rotation
	y->right = x;
	x->left = T;

	x->height = 1 + max(height(x->left),height(x->right));
	y->height = 1 + max(height(y->left),height(y->right));

	return y;
}

node* insert(node* root,int val)
{
	if(root == NULL)
		return create(val);

	if(val < root->data)
		root->left = insert(root->left,val);
	else if(val > root->data)
		root->right = insert(root->right,val);

	root->height = 1 + max(height(root->left),height(root->right));

	int bal = height(root->left) - height(root->right);
    
    // LL rotation
	if(bal > 1 && val < root->left->data)
		return rightRotate(root);
    
    // LR rotation
	if(bal > 1 && val > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
    
    // RR rotation
	if(bal < -1 && val > root->right->data)
		return leftRotate(root);
    
    // RL rotation
	if(bal < -1 && val < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
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
    
    if(root == NULL)
    	return root;

    root->height = 1 + max(height(root->left),height(root->right));

	int bal = height(root->left) - height(root->right);
    
    // LL rotation
	if(bal > 1 && height(root->left) - height(root->right) >= 0)
		return rightRotate(root);
    
    // LR rotation
	if(bal > 1 && height(root->left) - height(root->right) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
    
    // RR rotation
	if(bal < -1 && height(root->left) - height(root->right) <= 0)
		return leftRotate(root);
    
    // RL rotation
	if(bal < -1 && height(root->left) - height(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void preOrder(node *root)
{
     printf("%d ",root->data);
	 if(root->left)
     preOrder(root->left);
     if(root->right)
     preOrder(root->right);
}

int main()
{
	/*
	                            30
	                    20               40
	                10       25               50

	*/
	tree *T;
	T=(tree *)malloc(sizeof(tree));
	T->root = NULL;
	T->root = insert(T->root, 10);  
    T->root = insert(T->root, 20);  
    T->root = insert(T->root, 30);  
    T->root = insert(T->root, 40);  
    T->root = insert(T->root, 50);  
    T->root = insert(T->root, 25);
	preOrder(T->root);   printf("\n"); 
	

	T->root = Delete(T->root,40);
	T->root = Delete(T->root,50);


	/*
	The resultant AVL Tree after deletion
	                       20
	                10           30
	                          25

	*/
	printf("After deletion of 40 & 50 \n");
	preOrder(T->root);   printf("\n");

	return 0;
}
