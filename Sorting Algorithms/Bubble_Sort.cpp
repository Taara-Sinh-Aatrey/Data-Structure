#include<stdio.h>

void Bubble_Sort(int A[],int n)
{
	int i , j , temp , flag;
	for(i = 1; i < n; i++)
	{
		flag = 0;
		for(j = 0; j < n-i; j++)
		{
			if(A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				flag = 1;
			}
		}
		if(flag == 0)
			return;
	}
}

int main()
{
	int A[11] = {10,17,9,1,7,-2,8,11,3,100,-5};
	Bubble_Sort(A,11);
	int i = 0;
	for(i = 0; i < 11; i++)
		printf("%d ",A[i]);
	printf("\n");

	return 0;
}