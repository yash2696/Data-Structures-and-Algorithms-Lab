#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INT_MAX "2147483648"
#define INT_MIN "-2147483648"
#define INF 50000

struct array
{
	int node;
	float weight;
};

int v;

void Floyd_Warshall(struct array [][v]);
void print(struct array [][v]);
int checkFloat(char []);
int isSorted(int [], int );
int convertInputPositive(char [], int []);
int convertInputFloat(char [], float []);

/********************************************** MAIN FUNCTION *************************************************/

int main()
{
	int i, j, index1, index2, integers1[1000] = {0};
	float integers2[1000];
	char s[100];
	scanf("%s", s);
	v = checkFloat(s);
	getchar();
	if(v < 0 || v > 1000 || v == -1)
	{
		printf("INVALID INPUT\n");
		return 0;
	}
	struct array adj_mat[v][v];

	for(i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
		{
			adj_mat[i][j].node = INF;
			adj_mat[i][j].weight = INF;
		}
	}

	char input[1000][1000], weight[1000][1000];
	for(i = 0; i < v; i++)
	{
		gets(input[i]);
	}

	for(i = 0; i < v; i++)
	{
		gets(weight[i]);
	}

	for(i = 0; i < v; i++)
	{
		index1 = convertInputPositive(input[i], integers1);
		index2 = convertInputFloat(weight[i], integers2);

		if(index1 == -1 || index2 == -1)
		{
			printf("INVALID INPUT\n");
			return 0;
		}

		for(j = 0; j < index2; j++)
		{
			if(integers2[j] < -10000 || integers2[j] > 10000)
			{
				printf("INVALID INPUT\n");
				return 0;
			}
		}
		
		if(index1 > 0)
		{
			if(isSorted(integers1, index1) == 0)
			{
				printf("INVALID INPUT\n");
				return 0;
			}
		}
	
		for(j = 0; j < index1; j++)
		{
			if(integers1[j] < 0 || integers1[j] > (v - 1))
			{
				printf("INVALID INPUT\n");
				return 0;
			}
			adj_mat[i][integers1[j]].node = 1;
			adj_mat[integers1[j]][i].node = 1;
			adj_mat[i][integers1[j]].weight = integers2[j];
			adj_mat[integers1[j]][i].weight = integers2[j];
		}
	}

	Floyd_Warshall(adj_mat);

	for(i = 0; i < v; i++)
	{
		if(adj_mat[i][i].weight < 0)
		{
			printf("NEGATIVE EDGE CYCLE EXISTS.\n");
			return 0;
		}
	}

	print(adj_mat);
	return 0;
}

/********************************************** MAIN FUNCTION *************************************************/

int convertInputPositive(char input[], int integers[])
{
	int j = 0, i = 0, temp = 0;
	while(input[i] != '\0')
	{
		temp = 0;
		while(input[i] != ' ' && input[i] != '\0' && input[i] != '.' && input[i] != '-')
		{
			temp = temp * 10 + (input[i++] - '0');
		}

		if(input[i] == ' ')
		{
			i++;
		}
		else if(input[i] == '.' || input[i] == '-')
		{
			return -1;
		}

		integers[j++] = temp;
	}
	return (j);
}

int convertInputFloat(char input[], float integers[])
{
	int j = 0, i = 0, temp = 0, count = 0, flag = 0, flag1 = 0;
	while(input[i] != '\0')
	{
		flag = 0;
		flag1 = 0;
		count = 0;
		temp = 0;
		while(input[i] != ' ' && input[i] != '\0')
		{
			if(input[i] == '.' && input[i+1] >= '0' && input[i+1] <= '9')
			{
				flag1 = 1;
				i++;
			}

			if(input[i] == '-' && input[i+1] >= '0' && input[i+1] <= '9')
			{
				flag = 1;
				i++;
			}

			if(flag1 != 1)
			{
				count++;
			}

			temp = temp * 10 + (input[i++] - '0');
		}

		int new = temp, number = 0;
		while(new)
		{
			number++;
			new /= 10;
		}

		if(input[i] == ' ')
		{
			i++;
		}

		if(flag == 1 && flag1 == 1)
		{
			integers[j++] = - ((float) temp / (pow (10, number - count)));
		}
		else if(flag1 == 1 && flag == 0)
		{
			integers[j++] = ((float) temp / (pow (10, number - count)));
		}
		else if(flag1 == 0 && flag == 1)
		{
			integers[j++] = -temp;
		}
		else
		{
			integers[j++] = temp;
		}
	}
	return (j);
}

void Floyd_Warshall(struct array adj_mat[][v])
{
	int i, j, k;
	for(k = 0; k < v; k++)
	{
		for(i = 0; i < v; i++)
		{
			for(j = 0; j < v; j++)
			{
				if(i != j)
				{
					if((adj_mat[i][k].weight + adj_mat[k][j].weight < adj_mat[i][j].weight))
					{
						adj_mat[i][j].weight = adj_mat[i][k].weight + adj_mat[k][j].weight;
					}
				}
				else
				{
					adj_mat[i][j].weight = 0;
				}
			}
		}
	}
}

void print(struct array adj_mat[][v])
{
	int i, j;
	for(i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
		{
			if(adj_mat[i][j].weight == INF)
			{
				printf("INF ");
			}
			else
			{
				printf("%4.1f ", adj_mat[i][j].weight);
			}
		}
		printf("\n");
	}
}

int checkFloat(char num[])
{
	if(strcmp(num, INT_MAX) == 0 || strcmp(num, INT_MIN) == 0)
	{
		return -1;
	}

	int i, sum = 0, val;
	for(i = 0; num[i] != '\0'; i++)
	{
		if(num[i] < '0' || num[i] > '9')
		{
			return -1;
		}
		else
		{
			val = num[i] - '0';
			sum = sum * 10 + val;
		}
	}
	
	return sum;
}

int isSorted(int array[], int index)
{
	int i;
	
	for(i = 0; i < index - 1; i++)
	{
		if(array[i] > array[i + 1])
		{
			return 0;
		}
	}
	return 1;
}
