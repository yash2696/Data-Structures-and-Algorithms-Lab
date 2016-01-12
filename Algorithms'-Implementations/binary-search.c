#include<stdio.h>
int main()
{
	int array[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97},key,max,min,mid;
	scanf("%d",&key);
	min = 0;
	max = 24;
	while(min <= max)
	{
		mid = (min + max)/ 2;
		if(array[mid] > key)
		{
			max = mid - 1;
		}
		else if(array[mid] == key)
		{
			printf("Found");
			break;
		}
		else
		{
			min = mid + 1;
		}
	}
	
	if( min > max)
		printf("Not Found");
}
