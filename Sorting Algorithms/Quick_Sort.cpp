#include<stdio.h>

void Quick(int A[],int beg,int end,int *loc)
{
	int left = beg;
	int right = end;
	*loc = beg;
	int temp;
	while(1)
	{
		while(right > *loc && A[right] >= A[*loc])
		{
			right--;
		}
		if(right == *loc)
			return;
        temp = A[*loc];
        A[*loc] = A[right];
        A[right] = temp;
        *loc = right;

        while(left < *loc && A[left] <= A[*loc])
		{
			left++;
		}
		if(left == *loc)
			return;
        temp = A[*loc];
        A[*loc] = A[left];
        A[left] = temp;
        *loc = left;
	}
}

void Quick_Sort(int A[],int beg,int end)
{
	int loc;
	Quick(A,beg,end,&loc);
	if(loc-1 > beg)
	Quick_Sort(A,beg,loc-1);
    if(end > loc+1)
	Quick_Sort(A,loc+1,end);
	
}

int main()
{
	int A[11] = {10,17,9,1,7,-2,8,11,3,100,-5};
	Quick_Sort(A,0,10);
	int i = 0;
	for(i = 0; i < 11; i++)
		printf("%d ",A[i]);
	printf("\n");

	return 0;
}