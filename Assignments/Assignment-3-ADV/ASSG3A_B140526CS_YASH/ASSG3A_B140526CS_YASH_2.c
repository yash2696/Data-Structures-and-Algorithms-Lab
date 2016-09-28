#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linked_list
{
	int number;
	struct linked_list *next;
};

typedef struct linked_list node;

void push(node **, int);
void print_list(node *);
node *sum_of_digits(node *, node *);

int carry = 0;

int main()
{
	int n, i;
	scanf("%d",&n);
	if(n < 1 || n > 10000)
	{
		printf("Invalid Input\n");
		return 0;
	}
	getchar();
	
	node *list1 = NULL, *list2 = NULL;

	char str1[n + 1], str2[n + 1];

	scanf("%s", str1);
	getchar();
	int len1 = strlen(str1);

	scanf("%s", str2);
	getchar();
	int len2 = strlen(str2);

	if(len1 != len2 || len1 != n || len2 != n)
	{
		printf("Please enter correct input.\n");
		return 0;
	}

	for(i=n-1;i>=0;i--)
	{
		char ch = str1[i];
		if(ch >= 48 && ch <= 57)
		{
			int num = (int ) ch - 48;
			push(&list1, num);
		}
		else
		{
			printf("Please enter correct input.\n");
			return 0;
		}
	}

	for(i=n-1;i>=0;i--)
	{
		char ch = str2[i];
		if(ch >= 48 && ch <= 57)
		{
			int num = (int ) ch - 48;
			push(&list2, num);
		}
		else
		{
			printf("Please enter correct input.\n");
			return 0;
		}
	}

	list1 = sum_of_digits(list1, list2);
	
	if(carry)
	{
		push(&list1, carry);
	}
	print_list(list1);
	return 0;
}

void push(node **head, int num)
{
	node *new = (node *)malloc(sizeof(node));
	new->number = num;
	new->next = *head;

	*head = new;
	return;
}

void print_list(node *head)
{
	while(head != NULL)
	{
		printf("%d", head->number);
		head = head->next;
	}
	return;
}

node* sum_of_digits(node *list1, node *list2)
{
	if(list1 == NULL)
	{
		return;
	}

	sum_of_digits(list1->next, list2->next);

	int sum;
	sum = list1->number + list2->number + carry;
	carry = sum / 10;
	sum = sum % 10;

	list1->number = sum;
	return list1;
}