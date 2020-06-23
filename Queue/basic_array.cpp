#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int min(int a,int b)
{
	return (a<b?a:b);
}

struct Queue
{
	int front,rear,capacity;
	int* array;
};

struct Queue* createQueue(int cap)
{
	struct Queue* q;
	q=(struct Queue *)malloc(sizeof(struct Queue));
	q->front=q->rear=-1;
	q->capacity=cap;
	q->array=(int *)malloc(sizeof(int)*cap);
	return q;
}

void enQueue(struct Queue* q,int val)
{
	if((q->rear+1)%q->capacity==(q->front))
	{
		printf("Queue Overflow\n");
		return;
	}
	if(q->front == -1)
	q->front++;
	q->rear=(q->rear+1)%q->capacity;
	q->array[q->rear]=val;
}

int deQueue(struct Queue* q)
{
	int num;
	if(q->rear == -1)//when queue is empty
	{
		puts("Queue is empty");
		return INT_MIN;
	}
	else if(q->front == q->rear)//when queue has only one element
	{
		num=q->array[q->front];
		q->front=q->rear=-1;
	}
	else
	{
		num=q->array[q->front];
		q->front=(q->front+1)%q->capacity;
	}
	return num;
}

void display(struct Queue *q)
{
	/*
	case 1:(WHEN REAR IS GREATER THAN OR EQUAL TO FRONT):e.g:-front=0,rear=5,capacity=6
	while loop will iterate from i=0 to i=4 and i=5 will be printed separately using the 
	printf line written outside the loop
	
	case 2:(WHEN REAR IS LESS THAN FRONT):e.g:-front=4,rear=2,capacity=8;
	while loop will iterate from i=4 to i=7,after i=7,value of i will be changed to i=0 and
	now while loop will iterate from i=0 to i=1 and i=2 will be printed separately using the 
	printf line written outside the loop
	*/
	int i=q->front;
	while(i!=q->rear)
	{
		printf("%d ",q->array[i]);
		if(i==q->capacity-1)
		i=-1;
		i++;
	}
	printf("%d\n",q->array[q->rear]);
}

int empty(struct queue *q)
{
	return (q->rear == -1);
}

int full(struct queue *q)
{
	return (q->rear+1) % q->capacity == (q->front);
}

void menu()
{
	printf("Enter 1 to insert value at the end of the queue\n");
	printf("Enter 2 to delete first element of the queue\n");
	printf("Enter 3 to display the queue\n");
}

int main()
{
	struct Queue *q;
	int cap;
	printf("Enter the capacity of the queue\n");
	scanf("%d",&cap);
	q=createQueue(cap);
	int num,i;
	for(i=1;i<=min(cap,5);i++)
	enQueue(q,i*i);
	while(1){
	menu();
	printf("Enter your choice\n");
	int ch;
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter the value to insert\n");
			scanf("%d",&num);
			enQueue(q,num);
			break;
		case 2:
			num=deQueue(q);
			if(num!=INT_MIN)
			printf("The deleted value of the queue is %d\n",num);
			break;
		case 3:
			display(q);
			break;
		default:
			exit(0);
	}
}
}

