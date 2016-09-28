#include<stdio.h>

int mergeSort(int [], int, int);
int merge(int [], int, int, int);

int main()
{
	int n,i;
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Enter positive array size.\n");
		return 0;
	}
	
	int array[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	
	printf("%d\n",mergeSort(array, 0, n-1));
	return 0;
}

int mergeSort(int array[], int start, int end)
{
	int mid, count = 0;
	if(start < end)
	{
		mid = (start + end) / 2;
		count = (mergeSort(array,start,mid) + mergeSort(array,mid+1,end) + merge(array,start,mid,end));
	}
	return count;
}

int merge(int array[], int start, int mid, int end)
{
	int k=0, i = start, j = (mid+1), length = (end - start + 1), count = 0;
	int auxarray[length];
	
	while(i<=mid && j<=end)
	{
		if(array[i] <= array[j])
		{
			auxarray[k++] = array[i++];
		}
		else
		{
			auxarray[k++] = array[j++];
			count = count + (mid - i + 1);
		}
	}
	
	while(i<=mid)
	{
		auxarray[k++] = array[i++];
	}
	
	while(j<=end)
	{
		auxarray[k++] = array[j++];
	}
	
	for(i=end;i>=start;i--)
	{
		array[i] = auxarray[--k];
	}
	return count;
}
