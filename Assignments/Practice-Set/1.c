#include<stdio.h>


void mul(int p,int q,int m,int n, int mat1[p][q], int mat2[m][n]);
int main()
{
	int p,q,m,n,i,j,k;
	printf("Enter row1:");
	scanf("%d",&p);
	printf("Enter column1:");
	scanf("%d",&q);
	int mat1[p][q];
	printf("Enter matrix1 elements:");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}
	
	printf("Enter row2:");
	scanf("%d",&m);
	printf("Enter column2:");
	scanf("%d",&n);
	printf("Enter matrix2 elements:");
	int mat2[m][n];
	for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf("%d",&mat2[i][j]);
                }
        }

	
	int c[p][n];
	if(q == m)
	{
		for(i=0;i<p;i++)
		{	
			int sum = 0;
			for(j=0;j<n;j++)
			{
				for(k=0;k<p;k++)
				{
					sum = sum + mat1[i][k]*mat2[k][j];
				}
				c[i][j] = sum;
				sum = 0;
			}
		}
	
		for(i = 0; i < p; i++)
		{
			for(j = 0; j < n; j++)
			{
				printf("%4d ",c[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("Incompatible matrices");
	return 0;
}
