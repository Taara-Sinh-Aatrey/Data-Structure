#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
	return (a<b?a:b);
}

typedef struct stack
{
	int top;
	int size;
	int *arr;
}stack;

stack* createStack(int capacity)
{
	stack *st;
	st=(stack *)malloc(sizeof(stack));
	if(!st)
	return NULL;
	st->top=-1;
	st->size=capacity;
	st->arr=(int *)malloc(sizeof(int)*capacity);
	if(!st->arr)
	return NULL;
	return st;
}

void push(stack *st,int val)
{
	if(st->top==(st->size-1))
		printf("SORRY!STACK IS FULL\n");
	else
		st->arr[++st->top]=val;
}

int top(stack *st)
{
	return st->arr[st->top];
}

void pop(stack *st)
{
	st->top--;
}

int empty(stack *st)
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
	stack *st;
	st=createStack(100);
	int num,i;
	for(i = 1; i <= 5; i++)
	push(st,i*i);
	while(1)
	{
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
