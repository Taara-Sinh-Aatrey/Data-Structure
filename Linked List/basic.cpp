#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node* link;
}node;

typedef struct List
{
	struct node *head;
	struct node *tail;
}List;

List* createList()
{
	List *l = (List *)malloc(sizeof(List));
	l->head = NULL;
	l->tail = NULL;
	return l;
}


//A function to insert data at the beginning of the linked list
void push_front(List *list,int data)
{
	node* new_node=(node *)malloc(sizeof(node));
	new_node->info=data;
	new_node->link=list->head;
	list->head=new_node;
	if(list->tail == NULL)
		list->tail = list->head;
}

//A function to insert data at the end of the linked list
void push_back(List *list,int data)
{
	node* new_node=(node *)malloc(sizeof(node));
	new_node->info=data;
	new_node->link=NULL;
	if(list->tail == NULL)
	{
		list->head = list->tail = new_node;
	}
	else
	{
		list->tail->link = new_node;
		list->tail = new_node;
    }
}

//A function to insert data after a given previous node
void push_after(List *list,node *prev_node,int data)
{
	node* new_node=(node *)malloc(sizeof(node));
	new_node->info=data;
	new_node->link=prev_node->link;
	prev_node->link=new_node;
	if(new_node->link == NULL)
		list->tail = new_node;
}

void insert_at(List *list,int n,int data)
{
    if(n==1)
    {
    	node* new_node=(node *)malloc(sizeof(node));
		new_node->info=data;
		new_node->link=list->head;
		list->head=new_node;
		if(list->tail == NULL)
			list->tail = list->head;
    }
    else
    {
        node* new_node=(node *)malloc(sizeof(node));
	    new_node->info=data;
        node *t=list->head;
        int i=n-2;
        while(i--&&t!=NULL)
            t=t->link;
        
        if(t)
        {
	        new_node->link=t->link;
	        t->link=new_node;
        }   

        if(new_node->link == NULL)
        	list->tail = new_node;
    }
}

//A function to delete the beginning node
void delBeginning(List *list)
{
	node *t=list->head;
	list->head=list->head->link;
	if(list->head == NULL)
		list->tail = NULL;
	free(t);
}

//A function to delete the laat node
void delEnd(List *list)
{
	if(list->tail == NULL)
		return;
	node *t=list->head,*prev_node=NULL;
	if(list->head == list->tail)
	{
		list->head = list->tail = NULL;
		free(t);
	}
	else
	{
		while(t->link)
		{
			prev_node=t;
			t=t->link;
		}
		prev_node->link=NULL;
		list->tail = prev_node;
		free(t);
    }
}

//A function to delete the nth node
void delat(List *list,int n)
{
	node *t=list->head,*prev_node=NULL;
	if(n==1)
	{
		list->head=list->head->link;
		if(list->head == NULL)
			list->tail = NULL;
		free(t);
	}
	else
	{
		while(--n && t!=NULL)
		{
			prev_node=t;
			t=t->link;
		}
		if(t)
		{
			prev_node->link=t->link;
			free(t);
	    }
	    if(prev_node->link == NULL)
	    	list->tail = prev_node;
   }
}


//A function to view the linked list
void viewList(List *list)
{
	node *t = list->head;
	while(t!=NULL)
	{
		printf("%d ",t->info);
		t = t->link;
	}
	printf("\n");
}

void menu()
{
	printf("Enter 1 to insert node at the beginning\n");
	printf("Enter 2 to insert node at the end\n");
	printf("Enter 3 to insert node after a given node\n");
	printf("Enter 4 to insert node at a given position\n");
	printf("Enter 5 to delete the beginning node\n");
	printf("Enter 6 to delete the end node\n");
	printf("Enter 7 to delete the node of a given position\n");
	printf("Enter 8 to view list\n");
}

int main()
{
	List *list = createList(); 
	int i;
    for(i=0;i<5;i++)
    push_front(list,i);
	while(1)
	{
		int ch;
		int n,data;
		menu();
		scanf("%d",&ch);
		//system("CLS");
		switch(ch)
		{
			case 1:
			    printf("Enter the data you want to insert\n");
                scanf("%d",&data);
				push_front(list,data);
				break;
			case 2:
			    printf("Enter the data you want to insert\n");
                scanf("%d",&data);
				push_back(list,data);
				break;
			case 3:
			    printf("Enter the data you want to insert\n");
                scanf("%d",&data);
				push_after(list,list->head->link->link,data);
				break;
            case 4:
                printf("Enter the position where you want to insert\n");
                scanf("%d",&n);
                printf("Enter the data you want to insert\n");
                scanf("%d",&data);
                insert_at(list,n,data);
                break;
            case 5:
                delBeginning(list);
                break;
            case 6:
            	delEnd(list);
            	break;
            case 7:
            	printf("Enter the position of the node which you want to delete\n");
            	scanf("%d",&n);
            	delat(list,n);
            	break;
			case 8:
				viewList(list);
				break;
			default :
				exit(0);
		}
	}
	return 0;
}


