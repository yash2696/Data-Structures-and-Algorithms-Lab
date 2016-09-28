#include<stdio.h>
void binarySearch(int first, int last, int key, int list[]);

int main()
{
	int n, flag = 0, i;
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Enter positive array size.\n");
		return 0;
	}
	
	int list[n];
	scanf("%d",&list[0]);
	int max = list[0];

	for(i = 1; i < n; i++)
	{
		scanf("%d", &list[i]);
		if(list[i] > max)
		{
			max = list[i];
		}
		else
		{
			flag = 1;
		}
	}
	
	if(flag == 1)
	{
		printf("Enter integers in strictly increasing order.\n");
		return 0;
	}

	int k;
	scanf("%d", &k);

	int first = 0, last = (n - 1), middle = (first + last) / 2;
	binarySearch(first, last, k, list);
	return 0;
}

void binarySearch(int first, int last, int key, int list[])
{
	int middle = (first + last) / 2;
	if(first <= last)
	{
		if(list[middle] == key)
		{
			printf("%d\n", (middle + 1));
			return;
		}
		else if(list[middle] > key)
		{
			binarySearch(first, (middle - 1), key, list);
		}
		else
		{
			binarySearch((middle + 1), last, key, list);
		}
	}
	else
	{
		printf("NOT FOUND\n");
		return;
	}
	return;
}
