#include<stdio.h>

void Merge(int A[],int beg,int mid,int end)
{
	int B[end+1-beg];
	int i = beg , j = mid+1 , k = 0;
	while(i <= mid && j <= end)
	{
		if(A[i] < A[j])
		{
			B[k++] = A[i++];
		}
		else 
		{
			B[k++] = A[j++];
		}
	}

	while(i <= mid)
	{
		B[k++] = A[i++];
	}

	while(j <= end)
	{
		B[k++] = A[j++];
	}

	k = 0;
	i = beg;
	while(i <= end)
	{
		A[i++] = B[k++];
	}
}

void Merge_Sort(int A[],int beg,int end)
{
	if(beg == end)
		return;
	int mid = (beg+end)/2;
	Merge_Sort(A,beg,mid);
	Merge_Sort(A,mid+1,end);
	Merge(A,beg,mid,end);
}

int main()
{
	int A[11] = {10,17,9,1,7,-2,8,11,3,100,-5};
	Merge_Sort(A,0,10);
	int i = 0;
	for(i = 0; i < 11; i++)
		printf("%d ",A[i]);
	printf("\n");

	return 0;
}