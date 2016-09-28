#include<stdio.h>

int main()
{
	int n,flag = 0;
	scanf("%d",&n);
	if(n <= 0)
	{
		printf("Please enter positive array size.\n");
		return 0;
	}

	int array[n],i,j;
	scanf("%d",&array[0]);
	
	for(i=1;i<n;i++)
	{
		scanf("%d",&array[i]);
	}

	if(array[0] <= array[1])
	{
		for(i=0;i<n-1;i++)
		{
			if(array[i] <= array[i+1])
			{
				flag = 1;
			}
			else 
			{
				flag = 0;
			}
		}
	}
	
	else
	{
		for(i=0;i<n-1;i++)
		{
			if(array[i] >= array[i+1])
			{
				flag = 2;
			}
			else 
			{
				flag = 0;
			}
		}
	}
	
	int k;
	scanf("%d",&k);
	
	if(flag == 0)
	{
		printf("Enter elements in sorted order\n");
		return 0;
	}
	
	else if(flag == 1)
	{
		i=0,j=n-1;
		while(i<j)
		{
			if((array[i]+array[j]) == k)
			{
				printf("%d %d\n",array[i],array[j]);
			
				break;
			}
			else if((array[i] + array[j]) > k)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		if(i>=j)
		{
			printf("No two elements sum up to %d.\n",k);
		}
	}
	else if(flag == 2)
	{
		i=0,j=n-1;
		while(i<j)
		{
			if((array[i]+array[j]) == k)
			{
				printf("%d %d\n",array[i],array[j]);
			
				break;
			}
			else if((array[i] + array[j]) < k)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		if(i>=j)
		{
			printf("No two elements sum up to %d.\n",k);
		}
	}
	return 0;
}
