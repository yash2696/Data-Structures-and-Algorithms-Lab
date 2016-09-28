#include<stdio.h>

int fibonacci(int num);

int main()
{
	int num;
	scanf("%d",&num);
	if(fibonacci(num) == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

int fibonacci(int num)
{
	int i,a=0,b=1,c=1;
	
	do
	{
		if(num == c)
		{
			return 1;
		}
		c = a + b;
		a = b;
		b = c;
	}
	while(num >= c);
	return -1;
}
