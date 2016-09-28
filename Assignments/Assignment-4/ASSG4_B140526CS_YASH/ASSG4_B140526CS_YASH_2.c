#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int key;
	struct BST *left, *right;
};

typedef struct BST tree;

void insert(tree **, int);
tree *search(tree *, int);
tree *findMin(tree *);
tree *findMax(tree *);
tree *predecessor(tree *, int);
tree *successor(tree *, int);
void inorder(tree *);
void preorder(tree *);
void postorder(tree *);
tree *delete(tree *, int);

int main()
{
	int ele, val1;
	tree *root = NULL, *val = NULL;
	while(1)
	{
		char choice[5];
		scanf("%s", choice);
		if(strcmp(choice, "stop") == 0)
		{
			exit(0);
		}
		else if(strcmp(choice, "insr") == 0)
		{
			scanf("%d", &ele);
			if(ele > 2147483648 || ele < -2147483648)
	    {
	    	printf("INVALID INPUT\n");
	    }
	    else
	    {
				insert(&root, ele);
			}
		}
		else if(strcmp(choice, "minm") == 0)
		{
			val = findMin(root);
			if(val == NULL)
			{
				printf("NIL\n");
			}
			else
			{
				printf("%d\n", val->key);
			}
		}
		else if(strcmp(choice, "maxm") == 0)
		{
			val = findMax(root);
			if(val == NULL)
			{
				printf("NIL\n");
			}
			else
			{
				printf("%d\n", val->key);
			}
		}
		else if(strcmp(choice, "srch") == 0)
		{
			scanf("%d", &ele);
			if(ele > 2147483648 || ele < -2147483648)
	    {
	    	printf("INVALID INPUT\n");
	    }
	    else
	    {
				val = search(root, ele);
				if(val == NULL)
				{
					printf("NOT FOUND\n");
				}
				else
				{
					printf("FOUND\n");
				}
			}
		}
		else if(strcmp(choice, "delt") == 0)
		{
			scanf("%d", &ele);
			if(ele > 2147483648 || ele < -2147483648)
	    {
	    	printf("INVALID INPUT\n");
	    }
	    else
	    {
				if(root == NULL)
				{
					printf("EMPTY LIST\n");
				}
				else
				{
					root = delete(root, ele);
				}
			}
		}

		else if(strcmp(choice, "pred") == 0)
		{
			scanf("%d", &ele);
			if(ele > 2147483648 || ele < -2147483648)
	    {
	    	printf("INVALID INPUT\n");
	    }
	    else
	    {
				val = search(root, ele);
				if(val == NULL)
				{
					printf("NOT FOUND\n");
				}
				else
				{
					tree *res = predecessor(root, ele);
					if(res == NULL)
					{
						printf("NIL\n");
					}
					else
					{
						printf("%d\n", res->key);
					}
				}
			}
		}

		else if(strcmp(choice, "succ") == 0)
		{
			scanf("%d", &ele);
			if(ele > 2147483648 || ele < -2147483648)
	    {
	    	printf("INVALID INPUT\n");
	    }
	    else
	    {
				val = search(root, ele);
				if(val == NULL)
				{
					printf("NOT FOUND\n");
				}
				else
				{
					tree *res = successor(root, ele);
					if(res == NULL)
					{
						printf("NIL\n");
					}
					else
					{
						printf("%d\n", res->key);
					}
				}
			}
		}

		else if(strcmp(choice, "inor") == 0)
		{
			if(root == NULL)
			{
				printf("EMPTY LIST\n");
			}
			else
			{
				inorder(root);
				printf("\n");
			}
		}
		else if(strcmp(choice, "prer") == 0)
		{
			if(root == NULL)
			{
				printf("EMPTY LIST\n");
			}
			else
			{
				preorder(root);
				printf("\n");
			}
		}
		else if(strcmp(choice, "post") == 0)
		{
			if(root == NULL)
			{
				printf("EMPTY LIST\n");
			}
			else
			{
				postorder(root);
				printf("\n");
			}
		}
	}
	return 0;
}

tree *findMax(tree *node)
{
	if(node == NULL)
	{
		return node;
	}

	tree *current = node;
	while(current->right != NULL)
	{
		current = current->right;
	}
	return current;
}

tree *findMin(tree *node)
{
	if(node == NULL)
	{
		return node;
	}

	tree *current = node;
	while(current->left != NULL)
	{
		current = current->left;
	}
	return current;
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

tree *search(tree *node, int element)
{
	if(node == NULL)
	{
		return node;
	}

	else
	{
		if(node->key == element)
		{
			return node;
		}

		else if(node->key > element)
		{
			return search(node->left, element);
		}

		else
		{
			return search(node->right, element);
		}
	}
}

tree *predecessor(tree *root, int element)
{
	tree *node;
	node = search(root, element);

//	printf("pre = %d\n", node->key);
	if(node->left != NULL)
	{
		return findMax(node->left);
	}

	tree *pred = NULL;

	while(root != NULL)
	{
		if(root->key < element)
		{
			pred = root;
			root = root->right;
		}

		else if(root->key > element)
		{
			root = root->left;
		}

		else
		{
			break;
		}
	}
	return pred;
}

tree *successor(tree *root, int element)
{
	tree *node;
	node = search(root, element);
//	printf("succ = %d\n", node->key);

	if(node->right != NULL)
	{
		return findMin(node->right);
	}

	tree *succ = NULL;

	while(root != NULL)
	{
		if(root->key > element)
		{
			succ = root;
			root = root->left;
		}

		else if(root->key < element)
		{
			root = root->right;
		}
		else
		{
			break;
		}
	}
	return succ;
}

void inorder(tree *node)
{
	if(node != NULL)
	{
		inorder(node->left);
		printf("%d ", node->key);
		inorder(node->right);
	}
}

void preorder(tree *node)
{
	if(node != NULL)
	{
		printf("%d ", node->key);
		preorder(node->left);		
		preorder(node->right);
	}
}

void postorder(tree *node)
{
	if(node != NULL)
	{
		postorder(node->left);		
		postorder(node->right);
		printf("%d ", node->key);
	}
}

tree *delete(tree *node, int key)
{
	if(node == NULL)
	{
		return node;
	}

	if(node->key > key)
	{
		node->left = delete(node->left, key);
	}

	else if(node->key < key)
	{
		node->right = delete(node->right, key);
	}

	else
	{
		tree *temp;
		if(node->left == NULL)
		{
			temp = node->right;
			free(node);
			return temp;
		}
		else if(node->right == NULL)
		{
			temp = node->left;
			free(node);
			return temp;
		}

		temp = findMin(node->right);
		node->key = temp->key;
		node->right = delete(node->right, temp->key);
	}
	return node;
}

