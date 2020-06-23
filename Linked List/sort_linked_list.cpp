#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node* link;
};

//A function to insert data at the beginning of the linked list
void push_front(struct node **head_ref,int data)
{
	struct node* new_node=(struct node *)malloc(sizeof(struct node));
	new_node->info=data;
	new_node->link=*head_ref;
	*head_ref=new_node;
}


//A function to view the linked list
void display(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->info);
		head=head->link;
	}
	printf("\n");
}

void sorting(struct node *head)
{
	struct node *t1=head,*t2=head;
	int temp;
	while(t1)
	{
		t2=t1;
		while(t2)
		{
			if(t1->info>t2->info)
			{
				temp=t1->info;
				t1->info=t2->info;
				t2->info=temp;
			}
			t2=t2->link;
		}
		t1=t1->link;
	}
}


int main()
{
	struct node *head=NULL;
    push_front(&head,2);
    push_front(&head,8);
    push_front(&head,3);
    push_front(&head,6);
    push_front(&head,10);
    push_front(&head,1);
    // display(head);
	sorting(head);
	display(head);
	return 0;
}




