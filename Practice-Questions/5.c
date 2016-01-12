#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
	int number;
	struct linked_list *next;
};

typedef struct linked_list node;

void create(node *);
int count(node *);
void print(node *);
node *insert(node *);
node *find(node *, int);
node *delete(node *);

int main()
{
	int choice;
	node *head;
	head = (node *)malloc(sizeof(node));
	if(head == NULL)
		printf("Insufficient Memory\n");
	do 
	{
		printf("\n1.Create\n2.Insert\n3.Delete\n4.Count\n5.Print\n6.Exit...\n");
		printf("Enter your choice(1-6):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create(head);
				break;
			case 2:
				head = insert(head);
				break;
			case 3:
				head = delete(head);
				break;
			case 4:
				printf("Number of elements:%d\n",count(head));
				break;
			case 5:
				print(head);
				break;
			case 6:
				break;
		}
	}	while(choice!=6);
	return 0;
}

void create(node *head)
{
	printf("\nEnter numbers to be entered in linked list, enter -1 to exit:\n");
	scanf("%d", &head->number);
	
	if(head->number == -1)
		head->next = NULL;
	else
	{
		head->next = (node *)malloc(sizeof(node));
		create(head->next);
	}
	return;
}

void print(node *head)
{
	if(head->next != NULL)
	{
		printf("%d\n", head->number);
		print(head->next);
	}
	return;
}

int count(node *head)
{
        if(head->next == NULL)
                return (0);
        else
                return (1 + count(head->next));
}
	
// insert at a given position
	
node *insert(node *head)
{
	node *data;
	node *temp1;
	data = (node *)malloc(sizeof(node));
	int pos,x,i;
	printf("Enter element to be inserted:");
	scanf("%d", &x);
	printf("Enter position:");
	scanf("%d",&pos);
	data->number = x;
	data->next = NULL;
	temp1 = head;
	if(pos == 1)
	{
		data->next = head->next;
		head = data;
	}
	
	else
	{
		for(i = 0; i < pos-2; i++)
		{
			temp1 = temp1->next;
		}
		
		data->next = temp1->next;
		temp1->next = data;
	}
	return head;
}

//insert according to a given value

/*	
node *insert(node *head)
{
	node *new,*n1;

	int key,x;
	printf("Enter element to be inserted:");
	scanf("%d", &x);
	printf("Enter key node:");
	scanf("%d",&key);
	
	if (head->number == key)
	{
		new = (node *)malloc(sizeof(node));
		new->number = x;
		new->next = head;
		head = new;
	}
	
	else
	{
		n1 = find(head,key);
		
		if(n1 == NULL)
			printf("Key cannot be found");
		else
		{
			new = (node *)malloc(sizeof(node));
			new->number = x;
			new->next = n1->next;
			n1->next = new;
		}
	}
	return head;
}

*/

node *find(node *head, int key)
{
	if(head->next->number == key)
		return head;
	else 
		if(head->next->next == NULL)
			return NULL;
		else
			return find(head->next, key);
}

node *delete(node *head)
{
	int element;
	node *p1, *n1;
	printf("Enter the element to be deleted:");
	scanf("%d",&element);
	if(head->number == element)
	{
		p1 = head->next;
		free(head);
		head = p1;
	}
	
	else
	{
		n1 = find(head, element);
		
		if(n1 == NULL)
		{
			printf("Requested element could not be found...\n");
		}
		
		else
		{
			p1 = n1->next->next;
			free(n1->next);
			n1->next = p1;
		}
	}
	
	return head;
}
	
