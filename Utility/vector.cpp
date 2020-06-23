#include<stdio.h>
#include<stdlib.h>

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

int main()
{
	struct vector *v = createVector();
	for(int i = 0; i < 10; i++)
		push_back(v,i*i);

	for(int i = 0; i < v->size; i++)
		printf("%d ",v->arr[i]);

	printf("\n");

	for(int i = 0; i < 5; i++)
		pop_back(v);

	for(int i = 0; i < v->size; i++)
		printf("%d ",v->arr[i]);

	return 0;
}