#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX "2147483648"
#define INT_MIN "-2147483648"

struct linked_list
{
	long int key, rank;
	struct linked_list *next, *parent;
};

long int i = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0;

typedef struct linked_list disjoint_set;
disjoint_set *array1[10000];
disjoint_set *array2[10000];
disjoint_set *array3[10000];
disjoint_set *array4[10000];

/******************** NORMAL OPERATIONS ********************/
void makeSet(long int );
disjoint_set *find_set(disjoint_set *);
disjoint_set *find_node(long int );
disjoint_set *find_union(long int, long int);
/******************** NORMAL OPERATIONS ********************/

/******************** UNION BY RANK OPERATIONS ********************/
void makeSet_rank(long int );
disjoint_set *find_set_rank(disjoint_set *);
disjoint_set *find_node_rank(long int );
disjoint_set *find_union_rank(long int, long int);
/******************** UNION BY RANK OPERATIONS ********************/

/******************** PATH COMPRESSION OPERATIONS ********************/
void makeSet_path(long int );
disjoint_set *find_set_path(disjoint_set *);
disjoint_set *find_node_path(long int );
disjoint_set *find_union_path(long int, long int);
/******************** PATH COMPRESSION OPERATIONS ********************/

/******************** UNION BY RANK & PATH COMPRESSION OPERATIONS ********************/
void makeSet_both(long int );
disjoint_set *find_set_both(disjoint_set *);
disjoint_set *find_node_both(long int );
disjoint_set *find_union_both(long int, long int);
/******************** UNION BY RANK & PATH COMPRESSION OPERATIONS ********************/

long int checkFloat(char []);

int main()
{
	disjoint_set *temp, *temp1, *temp2, *temp3;
	long int j, number, number1, number2;
	for(j = 0; j < 10000; j++)
	{
		array1[j] = NULL;
		array2[j] = NULL;
		array3[j] = NULL;
		array4[j] = NULL;
	}

	char ch;
	char num[100], num1[100], num2[100];
	scanf("%c", &ch);
	getchar();
	do
	{
		switch(ch)
		{
			case 'm':
				scanf("%s", num);
				number = checkFloat(num);
				if(number == -1 || number < 0 || number > 10000)
				{
					printf("INVALID INPUT\n");
					return 0;
				}

				getchar();
				if(find_set(find_node(number)) != NULL && find_set_rank(find_node_rank(number)) != NULL && find_set_path(find_node_path(number)) != NULL && find_set_both(find_node_both(number)) != NULL)
				{
					printf("PRESENT\n");
				}
				else
				{
					makeSet(number);
					makeSet_rank(number);
					makeSet_path(number);
					makeSet_both(number);
					i++;
					printf("%d\n", number);
				}
				break;

			case 'f':
				scanf("%s", num);
				number = checkFloat(num);
				if(number == -1 || number < 0 || number > 10000)
				{
					printf("INVALID INPUT\n");
					return 0;
				}

				getchar();
				temp = find_set(find_node(number)), temp1 = find_set_rank(find_node_rank(number)), temp2 = find_set_path(find_node_path(number)), temp3 = find_set_both(find_node_both(number));
				if(temp == NULL || temp2 == NULL || temp1 == NULL || temp3 == NULL)
				{
					printf("NOT FOUND\n");
				}
				else
				{
					printf("%d %d %d %d\n", temp->key, temp1->key, temp2->key, temp3->key);
				}
				break;

			case 'u':
				scanf("%s %s", num1, num2);
				number1 = checkFloat(num1);
				if(number1 == -1 || number1 < 0 || number1 > 10000)
				{
					printf("INVALID INPUT\n");
					return 0;
				}

				number2 = checkFloat(num2);
				if(number2 == -1 || number2 < 0 || number2 > 10000)
				{
					printf("INVALID INPUT\n");
					return 0;
				}
				getchar();
				temp = find_union(number1, number2),
				temp1 = find_union_rank(number1, number2),
				temp2 = find_union_path(number1, number2),
				temp3 = find_union_both(number1, number2);
				if(temp == NULL || temp2 == NULL || temp1 == NULL || temp3 == NULL)
				{
					printf("ERROR\n");
				}
				else
				{
					printf("%d %d %d %d\n", temp->key, temp1->key, temp2->key, temp3->key);
				}
				break;

			default:
				printf("Enter correct choice.\n");
				break;
		}
		scanf("%c", &ch);
		getchar();
	} while(ch != 's');
	printf("%d %d %d %d\n", count1, count2, count3, count4);
}

/********************************** Noraml Operations Start **********************************/

void makeSet(long int x)
{
	disjoint_set *node = (disjoint_set *)malloc(sizeof(disjoint_set));
	node->key = x;
	node->parent = node;
	node->next = NULL;
	array1[i] = node;
}

disjoint_set *find_node(long int num)
{
	long int j = 0;
	while(array1[j] != NULL)
	{
		
		if(array1[j]->key == num)
		{
			return array1[j];
		}
		else
		{
			j++;
		}
	}
	return NULL;
}

disjoint_set *find_set(disjoint_set *node)
{
	if(node == NULL)
	{
		//count1++;
		return NULL;
	}

	else if(node->parent != node)
	{
		count1++;
		return find_set(node->parent);
	}

	else if(node->parent == node)
	{
		count1++;
		return node->parent;
	}
}

disjoint_set *find_union(long int x, long int y)
{
	disjoint_set *set1 = find_set(find_node(x));
	disjoint_set *set2 = find_set(find_node(y));

	if(set1 == NULL || set2 == NULL)
	{
		return NULL;
	}

	else if(set1 == set2)
	{
		return set1;
	}

	else
	{
		set2->parent = set1;
		return set1;
	}
}

/********************************** Noraml Operations Over **********************************/

/********************************** Union By Rank Start **********************************/

void makeSet_rank(long int x)
{
	disjoint_set *node = (disjoint_set *)malloc(sizeof(disjoint_set));
	node->key = x;
	node->rank = 0;
	node->parent = node;
	node->next = NULL;
	array2[i] = node;
}

disjoint_set *find_union_rank(long int x, long int y)
{
	disjoint_set *set1 = find_set_rank(find_node_rank(x));
	disjoint_set *set2 = find_set_rank(find_node_rank(y));

	if(set1 == NULL || set2 == NULL)
	{
		return NULL;
	}

	else if(set1 == set2)
	{
		return set1;
	}

	else
	{
		if(set1->rank > set2->rank)
		{
			set2->parent = set1;
			return set1;
		}
		else if(set2->rank > set1->rank)
		{
			set1->parent = set2;
			return set2;
		}
		else
		{
			set2->parent = set1;
			set1->rank = set1->rank + 1;
			return set1;
		}
	}
}

disjoint_set *find_node_rank(long int num)
{
	long int j = 0;
	while(array2[j] != NULL)
	{
		if(array2[j]->key == num)
		{
			return array2[j];
		}
		else
		{
			j++;
		}
	}
	return NULL;
}

disjoint_set *find_set_rank(disjoint_set *node)
{
	if(node == NULL)
	{
		return NULL;
	}

	else if(node->parent != node)
	{
		count2++;
		return find_set_rank(node->parent);
	}

	else if(node->parent == node)
	{
		count2++;
		return node->parent;
	}
}

/********************************** Union By Rank Over **********************************/

/********************************** Path Compression Start **********************************/

void makeSet_path(long int x)
{
	disjoint_set *node = (disjoint_set *)malloc(sizeof(disjoint_set));
	node->key = x;
	node->parent = node;
	node->next = NULL;
	array3[i] = node;
}

disjoint_set *find_node_path(long int num)
{
	long int j = 0;
	while(array3[j] != NULL)
	{
		if(array3[j]->key == num)
		{
			return array3[j];
		}
		else
		{
			j++;
		}
	}
	return NULL;
}

disjoint_set *find_set_path(disjoint_set *node)
{
	if(node == NULL)
	{
		return NULL;
	}

	else if(node->parent != node)
	{
		// count3++;
		node->parent = find_set_path(node->parent);
	}

	count3++;
	return node->parent;
}

disjoint_set *find_union_path(long int x, long int y)
{
	disjoint_set *set1 = find_set_path(find_node_path(x));
	disjoint_set *set2 = find_set_path(find_node_path(y));

	if(set1 == NULL || set2 == NULL)
	{
		return NULL;
	}

	else if(set1 == set2)
	{
		return set1;
	}

	else
	{
		set2->parent = set1;
		return set1;
	}
}

/********************************** Path Compression Over **********************************/

/********************************** Combined Operation Start **********************************/

void makeSet_both(long int x)
{
	disjoint_set *node = (disjoint_set *)malloc(sizeof(disjoint_set));
	node->key = x;
	node->rank = 0;
	node->parent = node;
	node->next = NULL;
	array4[i] = node;
}

disjoint_set *find_union_both(long int x, long int y)
{
	disjoint_set *set1 = find_set_both(find_node_both(x));
	disjoint_set *set2 = find_set_both(find_node_both(y));

	if(set1 == NULL || set2 == NULL)
	{
		return NULL;
	}

	else if(set1 == set2)
	{
		return set1;
	}

	else
	{
		if(set1->rank > set2->rank)
		{
			set2->parent = set1;
			return set1;
		}
		else if(set2->rank > set1->rank)
		{
			set1->parent = set2;
			return set2;
		}
		else
		{
			set2->parent = set1;
			set1->rank = set1->rank + 1;
			return set1;
		}
	}
}

disjoint_set *find_node_both(long int num)
{
	long int j = 0;
	while(array4[j] != NULL)
	{
		if(array4[j]->key == num)
		{
			return array4[j];
		}
		else
		{
			j++;
		}
	}
	return NULL;
}

disjoint_set *find_set_both(disjoint_set *node)
{
	if(node == NULL)
	{
		return NULL;
	}

	else if(node->parent != node)
	{
		// count4++;
		node->parent = find_set_both(node->parent);
	}
	count4++;
	return node->parent;
}

/********************************** Combined Operation Over **********************************/

long int checkFloat(char num[])
{
	if(strcmp(num, INT_MAX) ==0 || strcmp(num, INT_MIN) == 0)
	{
		return -1;
	}

	long int i, sum = 0, val;
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
