#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linked_list
{
	char data;
	struct linked_list *next, *left, *right;
};

typedef struct linked_list stack;

void push(stack **, char );
stack *pop(stack **);
void inorder(stack *);
void postorder(stack *);
void preorder(stack *);

int main()
{
	stack *top = NULL, *root;
	char prefix[100], rev[100];
	scanf("%[^\n]s", prefix);
	int i = 0;
	while(prefix[i] != '\0')
	{
		if(prefix[i] == ' ' || prefix[i] == '\t' || (prefix[i] >= 65 && prefix[i] <=90) || (prefix[i] >= 48 && prefix[i] <=57))
		{
			printf("Invalid Input\n");
			return 0;
		}
		i++;
	}

	i = 0;

	while(prefix[++i] != '\0');

	int j = 0;
	while(i>0)
	{
		rev[j++] = prefix[--i];
	}
	rev[j] = '\0';
	
	i=0;
	while(rev[i] != '\0')
	{
		while(rev[i] == ' ' || rev[i] == '\t')
		{
			i++;
		}
		
		if(rev[i] < 97 || rev[i] > 122)
		{
			stack *ope1, *ope2;
			ope1 = pop(&top);
			ope2 = pop(&top);
			stack *newnode = (stack *)malloc(sizeof(stack));			
			newnode->data = rev[i];
			newnode->left = ope2;
			newnode->right = ope1;
			newnode->next = NULL;

			if(top == NULL)
				top = newnode;
			else
			{
				newnode->next = top;
				top = newnode;
			}
		}

		else
		{
			push(&top, rev[i]);
		}
		i++;
	}
	
	root = top;
	printf("Inorder: ");
	inorder(root);
	printf("\n");
	
	printf("Preorder: ");
	preorder(root);
	printf("\n");

	printf("Postorder: ");
	postorder(root);
	printf("\n");
}

void push(stack **node, char ch)
{
	stack *temp = (stack *)malloc(sizeof(stack));
	temp->data = ch;
	temp->left = temp->right = temp->next = NULL;

	if(*node == NULL)
	{
		*node = temp;
	}

	else
	{
		(temp)->next = *node;
		*node = temp;
	}
}

stack *pop(stack **node)
{
	if(*node == NULL)
	{
		return NULL;
	}

	else
	{
		stack *temp = *node;
		*node = (*node)->next;
		return temp;
	}
}

void inorder(stack *node)
{
	if(node != NULL)
	{
		if(node->left != NULL && node->right != NULL)
	    {
	      printf("(");
	    }
		inorder(node->right);
		printf("%c", node->data);		
		inorder(node->left);
		if(node->left != NULL && node->right != NULL)
	    {
	      printf(")");
	    }
	}
}

void postorder(stack *node)
{
	if(node != NULL)
	{
		postorder(node->right);
		postorder(node->left);
		printf("%c", node->data);
	}
}

void preorder(stack *node)
{
	if(node != NULL)
	{
		printf("%c", node->data);
		preorder(node->right);
		preorder(node->left);				
	}
}
