#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int key;
	struct BST *left, *right;
};

typedef struct BST tree;

void insert(tree **, int);
void inorder(tree *);
void preorder(tree *);
void postorder(tree *);
tree *toBinaryTree(int [], int [], int, int);

int main()
{
	int n, i;
	scanf("%d", &n);

	if(n <= 0)
	{
		printf("INVALID INPUT\n");
		return 0;
	}

	int pre[n], in[n];

	for(i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
		if(pre[i] >= 2147483648 || pre[i] <= -2147483648)
		{
			printf("INVALID INPUT\n");
			return 0;
		}
	}

	scanf("%d", &in[0]);
	int max = in[0];
	for(i = 1; i < n; i++)
	{
		scanf("%d", &in[i]);
		if(in[i] < in[i - 1])
		{
			printf("INVALID INORDER TRAVERSAL\n");
			return 0;
		}
	}

	tree *root = toBinaryTree(pre, in, 0, n - 1);
	preorder(root);

	return 0;
}

tree *toBinaryTree(int pre[], int in[], int start, int end)
{
	static int index = 0;
	if(start > end)
	{
		return NULL;
	}

	tree *newnode = (tree *)malloc(sizeof(tree));
	newnode->key = pre[index];
	newnode->left = NULL;
	newnode->right = NULL;
	
	index++;

	if(start == end)
	{
		return newnode;
	}

	int i, pos;
	for(i = start; i <= end; i++)
	{
		if(in[i] == newnode->key)
		{
			pos = i;
		}
	}

	newnode->left = toBinaryTree(pre, in, start, pos - 1);
	newnode->right = toBinaryTree(pre, in, pos + 1, end);
	
	return newnode;
}

void insert(tree **node, int element)
{
	tree *temp, *previous, *current;
	temp = (tree *)malloc(sizeof(tree));
	temp->key = element;
	temp->left = temp->right = NULL;
	if(*node == NULL)
	{		
		*node = temp;
	}

	else
	{
		current = *node;
		while(current != NULL)
		{
			previous = current;
			if(temp->key > current->key)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}

		if(temp->key > previous->key)
		{
			previous->right = temp;
		}
		else
		{
			previous->left = temp;
		}
	}	
}

void preorder(tree *node)
{
	if(node != NULL)
	{
		printf(" ( ");
		printf("%d ", node->key);
		preorder(node->left);
		preorder(node->right);
		printf(" ) ");
	}
	else
	{
		printf(" ( ) ");
		return;
	}
}
