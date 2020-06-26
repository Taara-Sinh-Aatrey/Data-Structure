// MIN HEAP
#include<stdio.h>
#include<stdlib.h>

typedef struct heap
{
	int *arr;
	int capacity;
	int size;
}heap;

heap* createHeap(int cap)
{
	heap *h = (heap*)malloc(sizeof(heap));
	h->arr = (int *)malloc(sizeof(int)*cap);
	h->capacity = cap;
	h->size = 0;
	return h;
}

int par(int i)
{
	return (i-1)/2;
}

void insert(heap *h,int data)
{
	if(h->size == h->capacity)
		return;
	int i = h->size++;
	int temp;
	h->arr[i] = data;
	while(i != 0 && h->arr[par(i)] > h->arr[i])
	{
		temp = h->arr[i];
		h->arr[i] = h->arr[par(i)];
		h->arr[par(i)] = temp;
		i = par(i);
	}
}

// A function to delete node having index i
// so to delete root , we can call this function for index i = 0
void del(heap* h,int i)
{
	h->arr[i] = h->arr[--h->size];
	int p1,p2;
	int temp;
	while(1)
	{
		p1 = 2*i+1;
		p2 = 2*i+2;
		if(p1 >= h->size)
			break;
		if(p1 < h->size && p2 < h->size)
		{
			if(h->arr[p1] > h->arr[p2])
				p1 = p2;
		}
		if(h->arr[i] < h->arr[p1])
			break;
		temp = h->arr[p1];
		h->arr[p1] = h->arr[i];
		h->arr[i] = temp;
		i = p1;
	}
}

void Heap_Sort(heap *h,int res[])
{
	int sz = h->size , i = 0;
	for(i = 0; i < sz; i++)
	{
		res[i] = h->arr[0];
		del(h,0);
	}
}

int main()
{
	/*
	             1
	          3     2
	        15 5  4   45
	*/
	heap *h = createHeap(11);
	insert(h,3);
	insert(h,2);
	insert(h,1);
	insert(h,15);
	insert(h,5);
	insert(h,4);
	insert(h,45);
	int i = 0;
	for(i = 0;i < h->size; i++)
		printf("%d ",h->arr[i]);
	printf("\n");

	del(h,0);
	/*
	             2
	          3     4
	        15 5  45
	*/
	printf("After deleting root\n");
	for(i = 0;i < h->size; i++)
		printf("%d ",h->arr[i]);
	printf("\n");

	return 0;
}