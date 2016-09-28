#include<stdio.h>
int main()
{
	int n,i,j,flag = 0;
	scanf("%d",&n);
	
	if(n > 100)
	{
		printf("Range of n is 1 to 100...\n");
		return 0;
	}
	
	unsigned mat[n][n],temp;
	
	//scanning the values
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%u",&mat[i][j]);
			if(mat[i][j] < 0)
			{
				flag = 1;
			}
		}
	}
	
	if(flag == 1)
	{
		printf("Please enter intergers greater than 0..\n");
		return 0;
	}	
	
	//matrix transpose
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)	//interchanging upper triangle with lower triangle
		{
			temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}
	
	//column interchange
	
	for(j=0;j<n/2;j++)
	{
		for(i=0;i<n;i++)
		{
			temp = mat[i][j];
			mat[i][j] = mat[i][n-j-1];
			mat[i][n-j-1] = temp;
		}
	}
	
	//printing matrix
	
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%3u ",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
