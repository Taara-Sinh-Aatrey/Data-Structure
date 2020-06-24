#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node * link;
}node;

typedef struct stack
{
	struct node* head;
}stack;

void push(stack *st,int val)
{
	node *newN;
	newN=(node*)malloc(sizeof(node));
	newN->info=val;
	newN->link=st->head;
	st->head=newN;
}

int top(stack *st)
{
	return (st->head->info);
}

void pop(stack *st)
{
	node *t;
	t=st->head;
	st->head=st->head->link;
	free(t);
}

int empty(stack *st)
{
	if(st->head)
		return 0;
	return 1;
}

void menu()
{
	printf("Enter 1 to push value in the stack\n");
	printf("Enter 2 to get top value of the stack\n");
	printf("Enter 3 to pop top value of the stack\n");
}

int main()
{
	stack st;
	st.head=NULL;
	int num,i;
	for(i=1;i<=5;i++)
	push(&st,i*i);
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
			push(&st,num);
			break;
		case 2:
			if(st.head==NULL)
			printf("SORRY!STACK IS EMPTY\n");
			else{
			num=top(&st);
			printf("The top value of the stack is %d\n",num);
		    }
			break;
		case 3:
			if(st.head==NULL)
			printf("SORRY!STACK IS EMPTY\n");
			else{
	        pop(&st);
		    }
			break;
		default:
			exit(0);
	}
}
}
