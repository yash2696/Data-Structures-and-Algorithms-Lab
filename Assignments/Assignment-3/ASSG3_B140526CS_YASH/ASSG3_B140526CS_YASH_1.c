#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
	long int number;
	struct linked_list *next;
};

typedef struct linked_list node;

void swap(node **, long int, long int);
void print_list(node *);
void push(node **, int);
int find(long int [], long int, int);

int main()
{
	long int size,i;
	scanf("%ld", &size);

	if(size <= 1 && size >= 0)
	{
		printf("Enter atleast two elements.\n");
		return 0;
	}
	else if(size < 0)
	{
		printf("Enter valid input\n");
		return 0;
	}

	long int array[size];
	
	node *head = NULL;

	long int ele;
	for(i = 0; i < size; i++)
	{
		scanf("%d", &ele);
		if(ele > 1073741824 || ele < -1073741824)
		{	
			printf("Enter elements in the given range.\n");
			return 0;
		}
		array[i] = ele;
		push(&head, ele);
	}

	long int x, y, temp1, temp2;
	scanf("%ld%ld", &temp1, &temp2);
	if(temp1 > 1073741824 || temp1 < -1073741824)
	{
		printf("Enter elements in the given range.\n");
		return 0;
	}
	
	x = temp1;
	y = temp2;
	
	int p1 = find(array, x, size);
	int p2 = find(array, y, size);

	if(p1 == 1 && p2 == 1)
	{
		swap(&head, x, y);
		print_list(head);
	}
	else if(p1 == 1 && p2 == 0)
	{
		printf("%ld not found\n", y);
	}
	else if(p1 == 0 && p2 == 1)
	{
		printf("%ld not found\n", x);
	}
	return 0;
}

void swap(node **head, long int x, long int y)
{
	if(x == y)
	{
		return;
	}

	node *preX = NULL, *curX = *head;	
	while(curX->number != x && curX)
	{
		preX = curX;
		curX = curX->next;
	}

	node *previousY = NULL, *curY = *head;
	while(curY->number != y && curY)
	{
		previousY = curY;
		curY = curY->next;
	}

	if(preX != NULL)
	{
		preX->next = curY;
	}
	
	else
	{
		*head = curY;		
	}
	
	if(previousY != NULL)
	{
		previousY->next = curX;
	}
	
	else
	{
		*head = curX;				
	}

	node *temp = curY->next;
	curY->next = curX->next;
	curX->next = temp;
	return;
}

void print_list(node *current)
{	
	if(current == NULL)
	{
		return;
	}
	
	print_list(current->next);	
	printf("%d ", current->number);
}

void push(node** head_ref, int new_number)
{
	node* newnode = (node*) malloc(sizeof(node));
	newnode->number = new_number;
	newnode->next = (*head_ref);
	(*head_ref) = newnode;
}

int find(long int array[], long int x, int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(array[i] == x)
		{
			return 1;
		}
	}
	return 0;
}