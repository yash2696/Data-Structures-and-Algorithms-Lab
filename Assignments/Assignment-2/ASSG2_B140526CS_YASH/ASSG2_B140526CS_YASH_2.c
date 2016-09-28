#include<stdio.h>
int main()
{
	int n,m,i,j,flag = 0;
	scanf("%d%d", &n, &m);
	if(n<=0 || m<=0)
	{
		printf("Enter positive array dimensions.\n");
		return 0;
	}
	
	int mat[n][m];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}

	int k;
	scanf("%d", &k);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(k == mat[i][j])
			{
				printf("%d %d\n", (i + 1), (j + 1));
				flag = 1;
			}
		}
	}

	if(flag == 0)
	{
		printf("NOT FOUND\n");
	}
	return 0;
}
