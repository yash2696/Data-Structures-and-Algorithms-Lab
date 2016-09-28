#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
	long int number;
	struct linked_list *next;
};

typedef struct linked_list node;

node *head;

int create_list(node *, long int);
void reverse(node *);
void print_list(node *);

int main()
{
	long int size,i;
	scanf("%ld", &size);

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

	head = (node *)malloc(sizeof(node));
	
	if(create_list(head, size) == 1)
	{
		return 0;
	}
		
	reverse(head);
	print_list(head);
	
	return 0;
}

int create_list(node *head, long int size)
{	
	long int temp;
	if(size > 1)
	{
		scanf("%ld", &temp);
		if(temp >= 1073741824 || temp <= -1073741824)
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
		return 0;
	}
}

void reverse(node *current)
{
	if(current->next == NULL)
	{
		head = current;
		return;
	}
	
	reverse(current->next);
	node* temp = current->next;			//node *next is a local variable.
	temp->next = current;				// next->next is accessing the next variable of structure variable next.
	current->next = NULL;
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