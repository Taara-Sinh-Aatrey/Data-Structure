#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct tree
{
	struct node *root;
};

struct node* create(int val)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct vector
{
	int *arr;
	int size;
	int capacity;
};

struct vector* createVector()
{
	struct vector *v = (struct vector*)malloc(sizeof(struct vector));
	v->arr = (int *)malloc(sizeof(int)*2);
	v->size = 0;
	v->capacity = 2;
	return v;
}

void push_back(struct vector *v,int val)
{
	if(v->size == v->capacity)
	{
		v->capacity *= 2;
		v->arr = (int*)realloc(v->arr,v->capacity*sizeof(int));
	}
	v->arr[v->size] = val;
	v->size++;
}

void pop_back(struct vector *v)
{
	v->size--;
	if(v->capacity == 2*v->size)
	{
		v->capacity /= 2;
		v->arr = (int*)realloc(v->arr,v->capacity*sizeof(int));
	}
}

int getpath(struct vector *path,struct node* root,int n)
{
	if(!root)
		return 0;

	// printf("%d\n",root->data);

	push_back(path,root->data);

	if(root->data == n)
		return 1;

	if(getpath(path,root->left,n) || getpath(path,root->right,n))
		return 1;

	pop_back(path);
	return 0;
}

void findpath(struct node *root,int n1,int n2)
{
	 struct vector *path1,*path2;
	 path1 = createVector();
	 path2 = createVector();
	 getpath(path1,root,n1);
	 getpath(path2,root,n2);  
	 int intersection = -1;
	 int i = 0;
	 while(i < path1->size && i < path2->size)
	 {
	 	if(path1->arr[i] != path2->arr[i])
	 	{
	 		break;
	 	}
	 	i++;
	 }
	 intersection = i-1;


	 for(i = path1->size-1; i > intersection; i--)
	 	printf("%d ",path1->arr[i]);
	 for(i = intersection; i < path2->size; i++)
	 	printf("%d ",path2->arr[i]);
	 printf("\n");
}


int main()
{
	/*
	                         14
	                    5          7
	                9      2   6       18
	                  0              15

	*/
	struct tree *T;
	T=(struct tree *)malloc(sizeof(struct tree));
	T->root = create(14);
	T->root->left = create(5);
	T->root->right = create(7);
	T->root->left->left = create(9);
	T->root->left->right = create(2);
	T->root->right->left = create(6);
	T->root->right->right = create(18);
	T->root->left->left->right = create(0);
	T->root->right->right->left = create(15);
	printf("The path between 9 & 15 is :- ");
	findpath(T->root,9,15);
	return 0;
}