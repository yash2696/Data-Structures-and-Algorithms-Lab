#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
	long int number;
	struct linked_list *next;
};

typedef struct linked_list node;

int create_list(node *, int);
long int k_last(node *, int);
int getCount(node *);
void print_list(node *);

int main()
{
	int size,i;
	scanf("%d", &size);

	if(size < 0)
	{
		printf("Enter positive size.\n");
		return 0;
	}
	
	if(size == 0)
	{
		printf("Empty List.\n");
		return 0;
	}
	
	node *head;
	head = (node *)malloc(sizeof(node));
	
	if(create_list(head, size) == 1)
	{
		return 0;
	}
	
	int k;
	scanf("%d", &k);
	if(k > size)
	{
		printf("Invalid Input: %d > %d\n", k, size);
		return 0;
	}
	else if(k <= 0)
	{
		printf("Enter k in given range\n");
		return 0;
	}
	printf("%ld\n",k_last(head, k));
	
	return 0;
}

int create_list(node *head, int size)
{	
	long int temp;
	if(size > 1)
	{
		scanf("%ld", &temp);
		if(temp > 1073741824 || temp < -1073741824)
		{
			printf("Enter elements in the given range.\n");
			return 1;
		}
		head->number = temp;
		
		head->next = (node *)malloc(sizeof(node));
		create_list(head->next, size-1);
		return 0;
	}

	else if(size == 1)
	{
		scanf("%ld", &head->number);
		head->next = NULL;
		return;
	}
}

long int k_last(node *head, int k)
{
	int count = getCount(head);
	int pos = count - k;
	
	while(pos>=1)
	{
		head = head->next;
		pos--;
	}
	return head->number;
}

int getCount(node * head)
{
	if(head!=NULL)
	{
		return (1 + getCount(head->next));
	}
	else
	{
		return 0;
	}
}
void print_list(node *head)
{	
	if(head->next != NULL)
	{
		printf("%ld ", head->number);
		print_list(head->next);
	}
	else
	{
		printf("%ld\n", head->number);
	}
	return;
}
