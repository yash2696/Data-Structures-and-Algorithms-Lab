#include<stdio.h>
int main()
{
	int n, i;
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Enter positive array size.\n");
		return 0;
	}
	
	int list[n];
	scanf("%d", &list[0]);
	int max = list[0], flag = 0;
	for(i = 1; i < n; i++)
	{
		scanf("%d",&list[i]);
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
	scanf("%d",&k);

	int first = 0, last = (n - 1), middle;
	
	middle = (first + last) / 2;
	while(last >= first)
	{
		middle = (first + last) / 2;
		if(list[middle] == k)
		{
			printf("%d\n", (middle + 1));
			break;
		}
		else if(list[middle] > k)
		{
			last = (middle - 1);
		}
		else
		{
			first = middle + 1;
		}
		middle = (first + last) / 2;
	}

	if(first > last)
	{
		printf("NOT FOUND\n");
	}
	return 0;
}
