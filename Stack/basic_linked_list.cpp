#include<stdio.h>
#include<stdlib.h>

struct stack
{
	struct node* head;
};

struct node
{
	int info;
	struct node * link;
};


void push(struct stack *st,int val)
{
	struct node *newN;
	newN=(struct node*)malloc(sizeof(struct node));
	newN->info=val;
	newN->link=st->head;
	st->head=newN;
}

int top(struct stack *st)
{
	return (st->head->info);
}

void pop(struct stack *st)
{
	struct node *t;
	t=st->head;
	st->head=st->head->link;
	free(t);
}

int empty(struct stack *st)
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
	struct stack st;
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
