#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stack
{
	int top;
	int size;
	char* arr;
}stack;

stack* createStack(int cap)
{
	stack* s;
	s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	s->size=cap;
	s->arr=(char *)malloc(sizeof(char)*cap);
	return s;
}

int isOperator(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
		return 1;
	else
		return 0;
}

int isOperand(char ch)
{
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		return 1;
	else
		return 0;
}

int operatorValue(char ch)
{
	if(ch=='+'||ch=='-')
		return 0;
	else if(ch=='^')
		return 2;
	else
		return 1;
}

void push(stack *st,char val)
{
	if(st->top==(st->size-1))
		printf("SORRY!STACK IS FULL\n");
	else
		st->arr[++st->top]=val;
}

char top(stack *st)
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

int main()
{
	stack *st=createStack(50);
	char A[50],B[50];
	int l,i=0,j=0;
	char ch;
	puts("Enter the infix expression");
	scanf("%s",A);
	l=strlen(A);
	A[l]=')',A[l+1]='\0';
	push(st,'(');
	while(!empty(st))
	{
		if(isOperand(A[i]))
		{
			B[j++]=A[i++];
		}
		else if(isOperator(A[i]))
		{
			ch=top(st);
			while(isOperator(ch)&&(operatorValue(ch)>=operatorValue(A[i])))
			{
				pop(st);
				B[j]=ch;
				j++;
				ch = top(st);
			}
			push(st,A[i++]);
		}
		else if(A[i]=='(')
		{
			push(st,A[i++]);
		}
		else if(A[i]==')')
		{
			ch = top(st);
			while(ch != '(')
			{
				pop(st);
				B[j] = ch;
				j++;
				ch = top(st);
			}
			pop(st);
			i++;
		}
	}
	B[j]='\0';
	printf("The postfix expression is:- %s\n",B);
	return 0;
}