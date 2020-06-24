#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node* link;
}node;

//A function to insert data at the beginning of the linked list
void push_front(node **head_ref,int data)
{
	node* new_node=(node *)malloc(sizeof(node));
	new_node->info=data;
	new_node->link=*head_ref;
	*head_ref=new_node;
}


//A function to view the linked list
void display(node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->info);
		head=head->link;
	}
	printf("\n");
}

node* reverse(node *head)
{
	node *cur = NULL , *prev1 = NULL, *prev2 = head;
	if(prev2)
		prev1 = prev2->link;
	if(prev1)
		cur = prev1->link;
	prev2->link = NULL;
	if(!prev1)
		return prev2;
	while(1)
	{
		prev1->link = prev2;
        if(!cur)
    	return prev1;
		prev2 = prev1;
		prev1 = cur;
		cur = cur->link;
	}
}


int main()
{
	node *head=NULL;
    push_front(&head,2);
    push_front(&head,8);
    push_front(&head,3);
    push_front(&head,6);
    push_front(&head,10);
    push_front(&head,1);
    display(head);
	head = reverse(head);
	printf("After reversing :-\n");
	display(head);
	return 0;
}