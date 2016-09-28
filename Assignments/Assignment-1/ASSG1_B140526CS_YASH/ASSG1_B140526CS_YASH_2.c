#include<stdio.h>
int counter(int);
int main()
{
	int num;
	printf("Enter a positive decimal number: ");
	scanf("%d",&num);
	if(num < 0)
	{
		printf("Enter positive interger only...\n");
		return 0;
	}
	printf("\nThe binary representation of %d contains %d 1s.\n",num,counter(num));
	return 0;
}

int counter(int num)
{
	static int count = 0;
	int k;
	
	k=num%2;
	if(k==1)
		count++;
	
	if(num == 0)
		return count;
	else
		return counter(num/2);
}
