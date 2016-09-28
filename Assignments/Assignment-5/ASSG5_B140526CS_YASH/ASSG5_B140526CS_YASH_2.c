#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX "2147483648"
#define INT_MIN "-2147483648"

int visited[10000];
int checkFloat(char []);
int isSorted(int [], int );
int convertInput(char [], int []);

/***********************************************QUEUE DECLARATION ***********************************************/

struct queue
{
	int p;
	struct queue *next;
} *front = NULL, *rear = NULL;

/***********************************************QUEUE DECLARATION ***********************************************/

/***********************************************GRAPH DECLARATION ***********************************************/

struct adjListNode
{
	int node;
	struct adjListNode *next;
};

struct adjList
{
	struct adjListNode *head;
};

struct Graph
{
	int v;
	struct adjList *array;
};

/***********************************************GRAPH DECLARATION ***********************************************/


/******************************************** QUEUE OPERATIONS ****************************************************/

void enqueue(int node)
{
	struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
	temp->p = node;
	temp->next = NULL;

	if(rear == NULL && front == NULL)
	{
		front = rear = temp;
		return;
	}
	
	rear->next = temp;
	rear = temp;
}

int isQueueEmpty()
{
	if(front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int getFront()
{
	return front->p;
}

int dequeue()
{
	int ptr = front->p;
	if(front == NULL)
	{
	 	return -8;
	}

	if(front == rear)
	{
		front = rear = NULL;
	}

	else
	{
		front = front->next;
	}
	return ptr;
}

/******************************************** QUEUE OPERATIONS ****************************************************/

/***************************************************GRAPH OPERATIONS ***********************************************/

struct adjListNode *makenewnode(int key)
{
	struct adjListNode *newnode = (struct adjListNode *)malloc(sizeof(struct adjListNode));
	newnode->node = key;
	newnode->next = NULL;
	return newnode;
};

void makeEdge(struct Graph *graph, int vertex1, int vertex2)
{
	struct adjListNode *newnode = makenewnode(vertex2),
		   *temp = (struct adjListNode *)malloc(sizeof(struct adjListNode));

	if(graph->array[vertex1].head == NULL)
	{
		graph->array[vertex1].head = newnode;
		return;
	}

	temp = graph->array[vertex1].head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = newnode;
}

struct Graph *makeGraph(int v)
{
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->v = v;

	graph->array = (struct adjList *)malloc(v * sizeof(struct adjList));

	int i;
	for(i = 0; i < v; i++)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

/***************************************************GRAPH OPERATIONS ***********************************************/


/****************************************** DFS AND BFS FUNCTIONS' DECLARATION *********************************/

void dfs(struct Graph *, int, int);
void bfs(struct Graph *, int, int);

/****************************************** DFS AND BFS FUNCTIONS' DECLARATION *********************************/


/******************************************** MAIN FUNCTION ****************************************************/
int main()
{
	int v, i, j, index, integers[1000] = {0}, number1, number2;
	char start[100], key[100], s[100];
	scanf("%s", s);
	v = checkFloat(s);
	getchar();
	if(v < 1 || v > 10000 || v == -1)
	{
		printf("INVALID INPUT\n");
		return 0;
	}

	struct Graph *graph = makeGraph(v);

	for(i = 0; i < 10000; i++)
	{
		visited[i] = 0;
	}

	char input[1000];
	for(i = 0; i < v; i++)
	{
		visited[i] = 0;
		gets(input);

		index = convertInput(input, integers);
		if(index == -1)
		{
			printf("INVALID INPUT\n");
			return 0;
		}
		
		if(index > 0)
		{
			if(isSorted(integers, index) == 0)
			{
				printf("INVALID INPUT\n");
				return 0;
			}
		}

		for(j = 0; j < index; j++)
		{
			if(integers[j] < 0 || integers[i] > (v - 1))
			{
				printf("INVALID INPUT\n");
				return 0;
			}
			makeEdge(graph, i, integers[j]);
		}
	}

	while(1)
	{
		for(i = 0; i < v; i++)
		{
			visited[i] = 0;
		}

		char choice[4];
		scanf("%s", choice);

		if(strcmp(choice, "dfs") == 0)
		{
			scanf("%s %s", start, key);
			number1 = checkFloat(start);
			if(number1 < 0 || number1 > (v - 1))
			{
				printf("INVALID INPUT\n");
				return 0;
			}

			number2 = checkFloat(key);
			if(number2 < 0 || number2 > (v - 1))
			{
				printf("INVALID INPUT\n");
				return 0;
			}

			dfs(graph, number1, number2);
			printf("\n");
		}

		else if(strcmp(choice, "bfs") == 0)
		{
			scanf("%s %s", start, key);
			number1 = checkFloat(start);
			if(number1 < 0 || number1 > (v - 1))
			{
				printf("INVALID INPUT\n");
				return 0;
			}

			number2 = checkFloat(key);
			if(number2 < 0 || number2 > (v - 1))
			{
				printf("INVALID INPUT\n");
				return 0;
			}
			bfs(graph, number1, number2);
			printf("\n");
		}

		else if(strcmp(choice, "stp") == 0)
		{
			break;
		}

		else 
		{
			printf("ENTER CORRECT CHOICE\n");
		}
	}
	return 0;
}

/******************************************** MAIN FUNCTION ****************************************************/

/******************************************** MAKE INPUT INTEGERS **********************************************/

int convertInput(char input[], int integers[])
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

/******************************************** MAKE INPUT INTEGERS **********************************************/

/************************************************ DEPTH FIRST SEARCH ********************************************/

void dfs(struct Graph *graph, int start, int key)
{
	printf("%d ", start);
	struct adjListNode *vertex = graph->array[start].head;
	visited[start] = 1;
	while(vertex != NULL && start != key)
	{
		start = vertex->node;

		if(visited[start] == 0)
		{
			dfs(graph, start, key);
		}
		
		vertex = vertex->next;
	}
}

/************************************************ DEPTH FIRST SEARCH ********************************************/

/************************************************ BREADTH FIRST SEARCH ********************************************/

void bfs(struct Graph *graph, int start, int key)
{
	 int x;
	struct adjListNode *vertex = graph->array[start].head;
	enqueue(start);
	printf("%d ", start);

	visited[start] = 1;

	while(!isQueueEmpty())
	{
		int y = dequeue();
		
		for(vertex = graph->array[y].head; vertex != NULL; vertex = vertex->next)
		{
			start = vertex->node;
		
			if(start == key)
			{
				printf("%d", key);
				return;
			}

			if(visited[start] == 0)
			{
				enqueue(start);
				visited[start] = 1;
				printf("%d ", start);
			}
		}
	}
}

/************************************************ BREADTH FIRST SEARCH ********************************************/

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
/************************************************* THE END *******************************************************/
