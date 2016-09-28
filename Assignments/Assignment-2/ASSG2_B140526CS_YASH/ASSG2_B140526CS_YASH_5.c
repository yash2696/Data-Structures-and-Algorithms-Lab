#include<stdio.h>
int main()
{
	int n,i,j,pos;
	scanf("%d", &n);
	if(n<=0)
	{
		printf("Enter positive array size.\n");
		return 0;
	}
	
	double array[n], temp;
	int k,flag=0;
	for(i = 0; i < n; i++)
	{
		scanf("%lf",&array[i]);
		if(array[i] < 0)
		{
			flag = 1;
		}
		
		int truncated = (unsigned int) array[i];
		if(truncated != array[i])
		{
			flag = 1;
		}
	}
	
	if(flag==1)
	{
		printf("Enter correct input.\n");
		return 0;
	}
	
	for(i=1;i<n;i++)
	{
		k = array[i];
		pos = i;
		while(pos > 0 && array[pos-1] > k)
		{
			array[pos] = array[pos-1];
			pos--;
		}
		array[pos] = k;
	}
	
	for(i=0;i<n;i++)
	{
		printf("%u ",(unsigned int)array[i]);
	}
	printf("\n");
	return 0;
}
