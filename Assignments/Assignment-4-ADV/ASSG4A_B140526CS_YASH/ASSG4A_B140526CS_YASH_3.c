#include <stdio.h>
#include <stdlib.h>

#define size 10000

struct BT
{
	int key;
	struct BT *left, *right;
};

typedef struct BT tree;

int index_expr = 0;

tree *createBinaryTree(char []);
int height(tree *);
void zigZagOrder(tree *);
void levelPrint(tree *, int, int);
void preorder(tree *);

int main()
{
	int i;
	tree *root = NULL;
	char str[size];

	scanf("%[^\n]s", str);

	int len = 0;

	while(str[len++] != '\0')
	{
		len++;
	}

	int count = 0;
	for(i = 0; i < len; i++)
	{
		if(str[i] == ')')
		{
			count++;
		}

		else if(str[i] == '(')
		{
			count--;
		}
	}

	if(count != 0)
	{
		printf("INVALID INPUT\n");
		return 0;
	}
	
	root = createBinaryTree(str);
	
	preorder(root);					//Some Bug is there in the code. Due Checking
	zigZagOrder(root);
	printf("\n");
	return 0;
}

tree *createBinaryTree(char str[])
{   
	char character = str[index_expr];
    index_expr += 2;

    if(character == ')')
    {
        return createBinaryTree(str);
    }

    else if(character == '(')
    {   
    	int val = 0;
        char character = str[index_expr];
        index_expr += 1;
        
        if(character == ')')
        {   
        	index_expr += 1;
            return NULL;
        }
        else if(character >= '0' && character <= '9')
        {
            val = character - '0';
            while(character != ' ')
            {   
            	character = str[index_expr];
            	index_expr++;

                if(character == ' ' || character == '\n')
                {
                    break;
                }

                else if(character < '0' || character > '9')
                {   
                	printf("INVALID INPUT\n");
                	exit(0);
                }

                int digit = character - '0';
                val = val * 10 + digit;
            }
        }
        
        tree *newnode = (tree *)malloc(sizeof(tree));
        
        newnode->key = val;
        newnode->left = createBinaryTree(str);
        newnode->right = createBinaryTree(str);

        return newnode;
    }    
  
    else
    {
        return NULL;
    }
}

int height(tree *node)
{
	if(node == NULL)
	{
		return 0;
	}

	else
	{
		int leftheight = height(node->left);
		int rightheight = height(node->right);

		if(leftheight > rightheight)
		{
			return leftheight + 1;
		}
			
		else
		{
			return rightheight + 1;
		}
	}
}

void zigZagOrder(tree *root)
{
	int i, p = -1, h = height(root);
    for(i = 0; i < h; i++)
    {
    	p *= (-1);
    	levelPrint(root, i, p);
    }	
}

void levelPrint(tree *node, int n, int p)
{
	if(node == NULL)
	{
		return;
	}

	if(n == 0)
	{
		printf("%d ", node->key);
		return;
	}

	if(n > 0)
	{
		if(p == 1)
		{
			levelPrint(node->left, n - 1, p);
			levelPrint(node->right, n - 1, p );
		}
		if(p == -1)
		{
			levelPrint(node->right, n - 1, p);
			levelPrint(node->left, n - 1, p);
		}
	}
}

void preorder(tree *node)
{
	if(node != NULL)
	{
		//printf("%d ", node->key);
		preorder(node->left);		
		preorder(node->right);
	}
}
