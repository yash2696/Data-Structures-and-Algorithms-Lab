#include<stdio.h>

void buildHeap(int [], int);
void maxHeapify(int [], int, int);
void heapSort(int [], int);
void swap(int *, int *);

int main()
{
	int n,i;
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf("Invalid Input.\n");
		return 0;
	}
	
	int array[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	
	heapSort(array,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
	
	printf("\n");
	
	return 0;
}

void buildHeap(int array[], int n)
{
	int i;
	int	heapsize = n;
	for(i=((heapsize/2)-1);i>=0;i--)
	{
		maxHeapify(array,i,heapsize);
	}
}

void maxHeapify(int array[], int i, int heapsize)
{
	int l = (2*i+1),
		r = (2*i+2),
		temp,largest;
		
	if((l < heapsize) && (array[l] > array[i]))
	{
		largest = l;
	}
	else
	{
		largest = i;
	}

	if((r < heapsize) && (array[r] > array[largest]))
	{
		largest = r;
	}
	
	if(largest != i)
	{
		swap(&array[i],&array[largest]);
		maxHeapify(array,largest,heapsize);
	}
	
}

void heapSort(int array[], int heapsize)
{
	buildHeap(array,heapsize);
	int i;
	for(i=(heapsize-1);i>=1;i--)
	{
		swap(&array[i],&array[0]);
		heapsize=heapsize-1;
		maxHeapify(array,0,heapsize);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
