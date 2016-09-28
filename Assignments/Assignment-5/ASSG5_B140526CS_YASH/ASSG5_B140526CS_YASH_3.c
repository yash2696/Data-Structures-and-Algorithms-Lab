#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INT_MAX "2147483648"
#define INT_MIN "-2147483648"

int visited[10000] = {0}, min_vertex, min_dist;
int checkFloat(char []);
int isSorted(int [], int );
int parent(int );
int convertInput(char [], int []);
/************************************************ MinHeap ******************************************************/
typedef struct array
{
	int v;
	int priority;
} minHeap;

int size = 0;
minHeap heap[10000];
int min_dist_array[10000];
int parent(int );
int convertInput(char [], int []);
/************************************************ MinHeap *******************************************************/

/********************************************* MinHeap Functions ************************************************/
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insert(int v, int priority)
{
	int i = size;
	heap[i].v = v;
	heap[i].priority = priority;

	size++;
	while(i > 0 && (heap[i].priority < heap[parent(i)].priority))
	{
		swap(&heap[parent(i)].priority, &heap[i].priority);
		swap(&heap[parent(i)].v, &heap[i].v);
		i = parent(i);
	}  
	return;
}

void minHeapify(int i, int heap_size)
{
  	int l = (2*i+1),
		r = (2*i+2),
      	smallest;
    
	if((l < heap_size) && (heap[l].priority < heap[i].priority))
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}

	if((r < heap_size) && (heap[r].priority < heap[smallest].priority))
	{
		smallest = r;
	}
  
	if(smallest != i)
	{
		swap(&heap[i].priority,&heap[smallest].priority);
		swap(&heap[i].v, &heap[smallest].v);
		minHeapify(smallest,heap_size);
	}
}

void extract_min(minHeap *heap)
{
	min_vertex = heap[0].v;
	min_dist = heap[0].priority;
	min_dist_array[min_vertex] = min_dist;
	heap[0] = heap[size-1];
	size = size - 1;
	minHeapify(0, size);
}

void decreaseKey(int src, int dist)
{
	int i, pos = -1;
	for(i=0;i<size;i++)
	{
	    if(src == heap[i].v)
	    {
			pos = i;
			break;
    	}
  	}

  	heap[pos].priority = dist;

  	while(pos > 0 && (heap[parent(pos)].priority > heap[pos].priority))
  	{
	    swap(&heap[parent(pos)].priority, &heap[pos].priority);
	    swap(&heap[parent(pos)].v, &heap[pos].v);
	    pos = parent(pos);
  	}
}

int parent(int i)
{
	float p;
	p = ( (float) i / 2.0) - 1.0;
	return ceil(p);
}

int isEmptyminHeap()
{
	return size == 0;
}

int get_priority(int src)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(heap[i].v == src)
		{
			return heap[i].priority;
		}
	}
}

int isInMinHeap(int src)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(heap[i].v == src)
		{
			return 1;
		}
	}
	return 0;
}

/*************************************** MinHeap Functions ***************************************************/

/************************************** Graph Construction ***************************************************/
struct adjListNode
{
	int node;
	int weight;
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

/************************************ Graph Construction ***********************************************/

/*********************************** Graph Functions *****************************************/
struct adjListNode *makenewnode(int key, int weight)
{
	struct adjListNode *newnode = (struct adjListNode *)malloc(sizeof(struct adjListNode));
	newnode->node = key;
	newnode->weight = weight;
	newnode->next = NULL;
	return newnode;
};

void makeEdge(struct Graph *graph, int vertex1, int vertex2, int weight)
{
	struct adjListNode *newnode = makenewnode(vertex2, weight),
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

	int i = 0;
	for(; i < v; i++)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

void printGraph(struct Graph *graph)
{
	int v;
	for(v = 0; v < graph->v; ++v)
	{
		struct adjListNode *pCrawl = graph->array[v].head;
		printf("\n adjacency list of vertex %d\n head ", v);
		while(pCrawl)
		{
			printf("-> %d", pCrawl->node);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

/*********************************** Graph Functions *****************************************/

void dijkstra(struct Graph *graph, int src);

/********************************************** MAIN FUNCTION *************************************************/
int main()
{
	int v, i, j, index1, index2, integers1[1000] = {0}, integers2[1000] = {0}, number1, number2;
	char start[100], key[100], s[100];
	scanf("%s", s);
	v = checkFloat(s);
	getchar();
	if(v < 0 || v > 1000 || v == -1)
	{
		printf("INVALID INPUT\n");
		return 0;
	}

	struct Graph *graph = makeGraph(v);

	for(i = 0; i < 10000; i++)
	{
		visited[i] = 0;
	}

	char input[1000][1000], weight[1000][1000];
	for(i = 0; i < v; i++)
	{
		scanf("%[^\n]s", input[i]);
		getchar();
	}

	for(i = 0; i < v; i++)
	{
		scanf("%[^\n]s", weight[i]);
		getchar();
	}

	for(i = 0; i < v; i++)
	{
		index1 = convertInput(input[i], integers1);
		index2 = convertInput(weight[i], integers2);

		if(index1 == -1 || index2 == -1)
		{
			printf("INVALID INPUT\n");
			return 0;
		}

		for(j = 0; j < index2; j++)
		{
			if(integers2[j] < 0 || integers2[j] > 10000)
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
			makeEdge(graph, i, integers1[j], integers2[j]);
		}
	}
	
	while(1)
	{
		char choice[5];
		scanf("%s", choice);
		if(strcmp(choice, "apsp") == 0)
		{
			scanf("%s", start);
			number1 = checkFloat(start);
			if(number1 < 0 || number1 > (v - 1))
			{
				printf("INVALID INPUT\n");
				return 0;
			}

			dijkstra(graph, number1);
			for(i = 0; i < graph->v; i++)
			{
				if(min_dist_array[i] != 50000)
				{
					printf("%d ", min_dist_array[i]);
				}
				else
				{
					printf("INF ");
				}
			}
			printf("\n");
		}
		else if(strcmp(choice, "sssp") == 0)
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
			dijkstra(graph, number1);
			if(min_dist_array[number2] != 50000)
			{
				printf("%d", min_dist_array[number2]);
			}
			else
			{
				printf("UNREACHABLE");
			}
			printf("\n");
		}
		else if(strcmp(choice, "stop") == 0)
		{
			break;
		}

		else 
		{
			printf("ENTER CORRECT CHOICE\n");
		}
	}
}

/********************************************** MAIN FUNCTION *************************************************/

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

/******************************************************** DIJKSTRA ALGORITHM *****************************************/

void dijkstra(struct Graph *graph, int src)
{
	int v = graph->v, i;
	int pr;

	for(i = 0; i < v; i++)
	{
		pr = 50000;
		insert(i, pr);
	}

	decreaseKey(src, 0);
	while(!isEmptyminHeap())
	{
		extract_min(heap);
		int x = min_vertex, y = min_dist;

		struct adjListNode *vertex = graph->array[x].head;
		while(vertex != NULL)
		{
			int v = vertex->node;
			if(isInMinHeap(v) && y != 50000 && vertex->weight + y < get_priority(v))
			{
				pr = y + vertex->weight;
				decreaseKey(v, pr);
			}
			vertex = vertex->next;
		}
	}
	// printArray(graph);
}

/******************************************************** DIJKSTRA ALGORITHM *****************************************/

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
