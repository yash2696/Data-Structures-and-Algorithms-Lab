#include<stdio.h>

void mergeSort(int [], int, int);
void merge(int [], int, int, int);

int main()
{
	FILE *fptr;
	int count = 0, i=0, array[10000],num;
	fptr = fopen("NUMBERS","r");
	if(fptr == NULL)
	{
		printf("Error in opening file.\n");
		return 0;
	}

	while(fscanf(fptr, "%d", &num) > 0)
	{
		array[i] = num;
		i++;
		count++;
	}

	fclose(fptr);
	
	if(count>10000)
	{
		printf("Enter atmost 10000 numbers..\n");
		return 0;
	}

	mergeSort(array,0,count-1);
	fptr = fopen("OUTPUT","w");

	if(fptr == NULL)
	{
		printf("Error in opening file.\n");
		return 0;
	}

	for(i=0;i<count;i++)
	{
		fprintf(fptr,"%d\n",array[i]);
	}

	fclose(fptr);
	return 0;
}

void mergeSort(int array[], int start, int end)
{
	int mid;
	if(start < end)
	{
		mid = (start + end) / 2;
		mergeSort(array,start,mid);
		mergeSort(array,mid+1,end);
		merge(array,start,mid,end);
	}
}

void merge(int array[], int start, int mid, int end)
{
	int k=0;
	int i = start, j = mid+1;
	int length = end - start + 1;
	int auxarray[length];
	
	while(i<=mid && j<=end)
	{
		if(array[i] < array[j])
		{
			auxarray[k++] = array[i++];
		}
		else
		{
			auxarray[k++] = array[j++];
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
}
