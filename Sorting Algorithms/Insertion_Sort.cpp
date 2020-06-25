#include<stdio.h>

void Insertion_Sort(int A[],int n)
{
	int i , j , temp;
	for(i = 1; i < n; i++)
	{
		temp = A[i];
		j = i-1;
		while(j >= 0 && A[j] > temp)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;
	}
}

int main()
{
	int A[11] = {10,17,9,1,7,-2,8,11,3,100,-5};
	Insertion_Sort(A,11);
	int i = 0;
	for(i = 0; i < 11; i++)
		printf("%d ",A[i]);
	printf("\n");

	return 0;
}