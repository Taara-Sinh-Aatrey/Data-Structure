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
			// printf("p1 = %d p2 = %d\n",p1,p2);
			if(h->arr[p1] > h->arr[p2])
				p1 = p2;
		}
		// printf("p1\n",p1,p2);
		if(h->arr[i] < h->arr[p1])
			break;
		temp = h->arr[p1];
		h->arr[p1] = h->arr[i];
		h->arr[i] = temp;
		i = p1;
	}
}

void Heap_Sort(heap *h,int arr[],int n)
{
	// Sorting the array
	int i = 0;
    for(i = 0; i < n; i++)
    {
    	//storing the value at the root of heap in array
    	arr[i] = h->arr[0];

    	// Deleting the root of the heap
    	del(h,0);
    }
}

int main()
{
	int arr[9] = {8,4,7,5,11,2,1,10,20};
	heap *h = createHeap(9);
	int i = 0;
	for(i = 0; i < 9; i++)
		insert(h,arr[i]);

	Heap_Sort(h,arr,9);
	printf("Sorted array :-\n");
	for(i = 0; i < 9; i++)
		printf("%d ",arr[i]);
	printf("\n");


}