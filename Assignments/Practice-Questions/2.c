#include<stdio.h>
int main() 
{
	int num1, num2;
	scanf("%d %d",&num1,&num2);
	printf("%d",gcd(num1,num2));
	return 0;
}

int gcd(a, b)
{
	if(b == 0)
		return a;
	else if(b>a)
		return gcd(b,a);
	else
		return gcd(a-b,b);
}
