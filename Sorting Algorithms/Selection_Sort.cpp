#include<stdio.h>

int getMin(int A[],int i,int n)
{
	int loc = i;
	int m = A[i];
	int j;
	for(j = i+1; j < n; j++)
	{
		if(A[j] < m)
		{
			m = A[j];
			loc = j;
		}
	}
	return loc;
}

void Selection_Sort(int A[],int n)
{
	int i , j , temp;
	for(i = 0; i < n-1; i++)
	{
		j = getMin(A,i,n);
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}

int main()
{
	int A[11] = {10,17,9,1,7,-2,8,11,3,100,-5};
	Selection_Sort(A,11);
	int i = 0;
	for(i = 0; i < 11; i++)
		printf("%d ",A[i]);
	printf("\n");

	return 0;
}