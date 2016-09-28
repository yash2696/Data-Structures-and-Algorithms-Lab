#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10000

struct BST
{
	char key;
	int flag;
	struct BST *left, *right, *parent;
};

typedef struct BST tree;

tree *root = NULL;

void inorder(tree *);
void postorder(tree *);
void preorder(tree *);
void removeChar(char []);
tree *createBST(char []);
tree *makeNode(char);
tree *getParent(tree *);
tree *getRightMostChild(tree*);
tree *getLeftMostChild(tree*);

int main()
{
	tree *binarytree;
	char postfix[size], rev[size];
	scanf("%[^\n]s", postfix);
	
	int i = 0, j = 0;
	while(postfix[i] != '\0')
	{
		if(postfix[i] == ' ' || postfix[i] == '\t' || (postfix[i] >= 65 && postfix[i] <=90) || (postfix[i] >= 48 && postfix[i] <=57))
		{
			printf("Invalid Input\n");
			return 0;
		}
		i++;
	}
	
	i = 0;
	while(postfix[i] != '\0')
	{
		i++;
	}

	while(i >= 0)
	{
		rev[j++] = postfix[--i];
	}

	binarytree = createBST(rev);

	printf("Inorder: ");
	inorder(binarytree);
	printf("\n");

	printf("Preorder: ");
	preorder(binarytree);
	printf("\n");

	printf("Postorder: ");
	postorder(binarytree);
	printf("\n");
}

tree *getRightMostChild(tree* node)
{
	if(node == NULL)
	{
	  printf("EMPTY");
	}
	else
	{
		if(node->right == NULL)
		{
			return node;
		}
		else
		{
			if(node == node->right->parent)
			{
				return getRightMostChild(node->right);
			}
			else
			{
				return node;
			}
		}
	}
}

tree *getLeftMostChild(tree* node)
{   
	if(node == NULL)
	{
		printf("EMPTY");
	}
	else
	{
		if(node->left == NULL)
		{
			return node;
		}
		else
		{
			if(node==node->left->parent)
			{
				return getLeftMostChild(node->left);
			}
			else
			{
				return node;
			}
		}
	}
}

tree *makeNode(char character)
{ 
	tree *newnode;
  newnode = (tree *)malloc(sizeof(tree));

	newnode->key = character;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;
	newnode->flag = 0;
	return newnode;
}

void removeChar(char str[])
{   
	int i,len = 0;
    
	while(str[len] != '\0')
	{
		len++;
	}

	for(i = 1; i <= len; i++)
	{
	  str[i-1] = str[i];
	}
}

tree *createBST(char input[])
{   
	tree *temp;
	if(input[0] == '\0')
	{
		return NULL;
	}

	else if(strlen(input) == 1 && (input[0] >= 97 && input[0] <= 122))
	{
		temp = makeNode(input[0]);
		removeChar(input);
		return temp;
	}

	else if(input[0] < 97 || input[0] > 122)
	{
		temp = makeNode(input[0]);
		removeChar(input);
		
		temp->right = createBST(input);
		temp->left = createBST(input);

		if(temp->left != NULL)
		{
			temp->left->parent = temp;
		}
		if(temp->right != NULL)
		{
			temp->right->parent = temp;
		}

		return temp;
	}

	else if(input[0] >= 97 && input[0] <=122)
	{
		temp = makeNode(input[0]);
		removeChar(input);
		return temp;
	}
}

void inorder(tree *node)
{
  tree *temp,*pre;
  
  if(node == NULL)
  {
    return;
  }
  
  temp = node;
  
  while(temp != NULL)
  {
    if(temp->left == NULL)
    {   
    	printf("%c", temp->key);
      
      while(temp->flag > 0)
      {
				printf(")");
				temp->flag--;
			}
      temp = temp->right;
    }
    else
    {
      pre = temp->left;
      while(pre->right != NULL && pre->right != temp)
      {
          pre = pre->right;
      }
      
      if(pre->right == NULL)
      { 
        printf("(");
        pre->right = temp;
        temp = temp->left;
      }
      
      else
      {
        pre->right = NULL;
        printf("%c",temp->key);
        getRightMostChild(temp)->flag++;
        temp = temp->right;
			}
    }
  }
}

void postorder(tree *node)
{   tree *temp;

    temp = (tree *)malloc(sizeof(tree));
    
    temp = node;
    while(temp != NULL)
    {	
    	if(temp->left != NULL && temp->left->flag != -1)
    	{
    		while(temp->left != NULL)
    		{
    			temp = temp->left;
    		}
    	}
      
      printf("%c",temp->key);
      temp->flag = -1;
      if(temp->parent != NULL && temp != temp->parent->right)
      {
        temp = temp->parent->right;
      }
      else
      {
    	  temp = temp->parent;
    	}
    }
}

void preorder(tree* node)
{
	tree *temp;
  while (node != NULL)
  {
    if (node->left == NULL)
    {
        printf( "%c", node->key);
        node = node->right;
    }
    else
    {
      temp = node->left;
      while (temp->right && temp->right != node)
      {
        temp = temp->right;
      }
      
      if (temp->right == node)
      {
          temp->right = NULL;
          node = node->right;
      }
      
      else
      {
          printf("%c", node->key);
          temp->right = node;
          node = node->left;
      }
    }
  }
}