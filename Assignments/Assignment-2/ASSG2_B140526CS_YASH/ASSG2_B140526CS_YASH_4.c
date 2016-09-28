#include<stdio.h>
int main()
{
	int n,i,j;
	float temp;
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Enter positive array size.\n");
		return 0;
	}
	
	float array[n];
	for(i = 0; i < n; i++)
	{
		scanf("%f",&array[i]);
	}

	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			if(array[j] >= array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for(i = 0; i < n; i++)
	{
		printf("%f ", array[i]);
	}
	return 0;
}
