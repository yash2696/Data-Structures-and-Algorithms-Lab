#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,pos;
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Enter positive array size.\n");
		return 0;
	}
	
	char string[n][11],dummy[11];
	for(i=0;i<n;i++)
	{
		scanf("%s", string[i]);
		int length = strlen(string[i]);
		if(length > 10)
		{
			printf("Please enter strings of length atmost 10.\n");
			return 0;
		}
		
		int flag=0;
		for(j=0;j<length;j++)
		{
			if(string[i][j] < 'a' || string[i][j] > 'z')
			{
				flag = 1;
			}
		}
		
		if(flag==1)
		{
			printf("Please enter only lowercase strings.\n");
			return 0;
		}
	}
	
	for(i=0;i<n;i++)
	{
		pos = i;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(string[j],string[pos]) < 0)
			{
				pos = j;
			}
		}
		strcpy(dummy,string[i]);
		strcpy(string[i],string[pos]);
		strcpy(string[pos],dummy);
	}

	for(i=0;i<n;i++)
	{
		printf("%s ",string[i]);
	}
	printf("\n");
	return 0;
}
