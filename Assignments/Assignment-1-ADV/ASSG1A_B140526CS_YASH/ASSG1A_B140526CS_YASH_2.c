#include<stdio.h>

void clockwise(int m, int n, unsigned mat[][n]);
void anticlockwise(int m, int n, unsigned mat[][n]);
int main()
{
	int m, n, i, j, flag = 0;
	printf("Enter the elements of matrix:\n");
	
	scanf("%d%d",&m,&n);
	
	if(n > 100 && m <= 100)
	{
		printf("Enter column size less than 100.\n");
		return 0;
	}
	else if(m > 100 && n <= 100)
	{
		printf("Enter row size less than 100.\n");
		return 0;
	}
	else if(m > 100 && n > 100)
	{
		printf("Enter row and column sizes less than 100.\n");
		return 0;
	}
	
	unsigned int mat[m][n];
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%u",&mat[i][j]);
			if(mat[i][j] < 0)
			{
				flag = 1;
			}
		}
	}
	
	getchar();
	
	if(flag == 1)
	{
		printf("Please enter positive integers.\n");
		return 0;
	}

	char choice;
	do
	{
		printf("\nMENU:\n");
		printf("a. Clockwise spiral-order traversal\nb. Anti-clockwise spiral-order traversal\nc. Exit\n\n");
		printf("Enter your choice:");

		scanf("%c",&choice);
		getchar();
		printf("\n");
		switch(choice)
		{
			case 'a':
			case 'A':
				clockwise(m, n, mat);
				printf("\n");
				break;
			case 'b':
			case 'B':
				anticlockwise(m, n, mat);
				printf("\n");
				break;
			case 'c':
			case 'C':
				printf("Exiting...\n");
				printf("\n");
				break;
			default:
				printf("Enter correct choice..\n");
		}
	}	while(choice != 'c' && choice != 'C');
	return 0;
}


void clockwise(int m, int n, unsigned mat[m][n])
{
	int i, j, k, l;
	int count = 0, row = m, column = n;
	
	for(i = 0, j = 0; i < m, j < n, count < (row*column); i++, j++)
	{
		k = i;
		l = j;
				
		while(l < n)
		{
			printf("%u ",mat[k][l]);
			count++;
			l++;
		}
		l--;
		k++;
		
		while(k < m)
		{
			printf("%u ",mat[k][l]);
			count++;
			k++;
		}
		l--;
		k--;
		
		while(l >= j)
		{
			printf("%u ",mat[k][l]);
			count++;
			l--;
		}
		l++;
		k--;
		
		while(k >= i+1)
		{
			printf("%u ",mat[k][l]);
			count++;
			k--;
		}
		m--;
		n--;
	}
	return;
}
		
		
void anticlockwise(int m, int n, unsigned mat[m][n])
{
	int i, j, k, l, count = 0;
	
	int row = m, column = n;
	
	for(i = 0, j = 0; i < m, j < n, count < (row*column); i++, j++)
	{
		k = i;
		l = j;
		
		while(k < m)
		{
			printf("%u ",mat[k][l]);
			count++;
			k++;
		}
		k--;
		l++;
		
		while(l < n)
		{
			printf("%u ",mat[k][l]);
			count++;
			l++;
		}
		l--;
		k--;
		
		while(k >= i)
		{
			printf("%u ",mat[k][l]);
			count++;
			k--;
		}
		k++;
		l--;
		
		while(l >= j + 1)
		{
			printf("%u ",mat[k][l]);
			count++;
			l--;
		}
		m--;
		n--;
	}
}
