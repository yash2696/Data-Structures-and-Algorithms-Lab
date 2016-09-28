#include<stdio.h>
void prime(int);
void palindrome(int);
int main()
{
	int limit;
	scanf("%d",&limit);
	prime(limit);
	return 0;
}

void prime(int lim)
{
	int i,j;
	for(i=10;i<=lim;i++)
	{
		int flag=1;
		for(j=2;j<=i/2;j++)
		{
			if(i%j == 0)
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		if(flag == 1 )
			palindrome(i);
	}
}

void palindrome(int num)
{
	int temp=num,b=num,i,sum=0,k;
	for(i=1;num!=0;i++)
	{
		k=num%10;
		sum=sum*10+k;
		num/=10;
	}
	
	if(sum == b)
		printf("%d\n",b);
}
