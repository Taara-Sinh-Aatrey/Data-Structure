#include<stdio.h>
#include<stdlib.h>
#include<climits>

struct queue
{
	struct node* head;
};

struct node
{
	int info;
	struct node * link;
};


void enQueue(struct queue *q,int val)
{
	struct node *newN, *t;
	newN = (struct node*)malloc(sizeof(struct node));
	newN->info = val;
	newN->link = NULL;
	if(q->head == NULL)
	{
		q->head=newN;
	}
	else
	{
		t = q->head;
		while(t->link != NULL)
		{
			t = t->link;
		}
		t->link = newN;
	}
}

int deQueue(struct queue *q)
{
	int num;
	struct node *t=q->head;
	num=q->head->info;
	q->head=q->head->link;
	free(t);
	return num;
}

int empty(struct queue *q)
{
	return q->head == NULL;
}

void display(struct queue *q)
{
	struct node *t=q->head;
	while(t!=NULL)
	{
		printf("%d ",t->info);
		t=t->link;
	}
	printf("\n");
}

void menu()
{
	printf("Enter 1 to insert value at the end of the queue\n");
	printf("Enter 2 to delete first element of the queue\n");
	printf("Enter 3 to display the queue\n");
}

int main()
{
	struct queue q;
	q.head=NULL;
	int num,i;
	for(i=1;i<=5;i++)
	enQueue(&q,i*i);
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
			enQueue(&q,num);
			break;
		case 2:
		    if(!empty(&q))
		    {
		        num=deQueue(&q);
		        if(num!=INT_MIN)
		        printf("The deleted value is %d\n",num);
		    }
		    else
		    {
		    	printf("The queue is empty\n");
		    }
			break;
		case 3:
			display(&q);
			break;
		default:
			exit(0);
	}
}
}
