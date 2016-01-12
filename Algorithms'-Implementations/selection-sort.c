#include<stdio.h>
#define N 7
int main()
{
	int array[N] = {18, 6, 66, 44, 9, 22, 14},i,temp,j,smallest;
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			smallest = array[i];
			if(array[j] < smallest)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%d\n",array[i]);
	}
}
