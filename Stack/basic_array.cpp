#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
	return (a<b?a:b);
}

struct stack
{
	int top;
	int size;
	int *arr;
};

struct stack* createStack(int capacity)
{
	struct stack *st;
	st=(struct stack *)malloc(sizeof(struct stack));
	if(!st)
	return NULL;
	st->top=-1;
	st->size=capacity;
	st->arr=(int *)malloc(sizeof(int)*capacity);
	if(!st->arr)
	return NULL;
	return st;
}

void push(struct stack *st,int val)
{
	if(st->top==(st->size-1))
		printf("SORRY!STACK IS FULL\n");
	else
		st->arr[++st->top]=val;
}

int top(struct stack *st)
{
	return st->arr[st->top];
}

void pop(struct stack *st)
{
	st->top--;
}

int empty(struct stack *st)
{
	return st->top == -1;
}

void menu()
{
	printf("Enter 1 to push value in the stack\n");
	printf("Enter 2 to get top value of the stack\n");
	printf("Enter 3 to pop top value of the stack\n");
}

int main()
{
	struct stack *st;
	int cap;
	printf("Enter the capacity of the stack\n");
	scanf("%d",&cap);
	st=createStack(cap);
	int num,i;
	for(i=1;i<=min(cap,5);i++)
	push(st,i*i);
	while(1){
	menu();
	printf("Enter your choice\n");
	int ch;
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter the value to push\n");
			scanf("%d",&num);
			push(st,num);
			break;
		case 2:
			if(st->top==-1)
				printf("SORRY!STACK IS EMPTY\n");
			else
			{
				num=top(st);
				printf("The top value of the stack is %d\n",num);
		    }
			break;
		case 3:
			if(st->top==-1)
				printf("SORRY!STACK IS EMPTY\n");
			else
		        pop(st);
			break;
		default:
			exit(0);
	}
}
}
