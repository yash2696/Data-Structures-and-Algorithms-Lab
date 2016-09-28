#include<stdio.h>
#include<math.h>

int countAdjacent(int , int , int p, int mat[][p]);

int main()
{
	int n;
	scanf("%d",&n);
	int mat[n+2][n+2],copy[n+2][n+2],i,j;
	int res[n][n];
	for(i=0;i<n+2;i++)
	{
		for(j=0;j<n+2;j++)
		{
			mat[i][j] = -1;
			copy[i][j] = 0;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i+1][j+1]);
			copy[i+1][j+1] = mat[i+1][j+1];
		}
	}

	int count;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			count = countAdjacent(i,j,n+2,mat);
			
			float sum = ( copy[i-1][j-1] + copy[i][j-1] + copy[i+1][j-1] + copy[i-1][j] + copy[i+1][j] +
						  copy[i-1][j+1] + copy[i][j+1] + copy[i+1][j+1] + copy[i][j] ); 
			res[i-1][j-1] = round(sum / (float) count);
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%2d ",res[i][j]);
		}
		printf("\n");
	}
	return 0;
}


//returns the number of adjacent elements of a given position (i,j)

int countAdjacent(int i, int j,int p, int mat[p][p])
{
	int m,n,count = 0;
	
	for(m=i-1;m<=i+1;m++)
	{
		for(n=j-1;n<=j+1;n++)
		{
			if(mat[m][n] >=0)
			{
				count++;
			}
		}
	}
	return count;
}
