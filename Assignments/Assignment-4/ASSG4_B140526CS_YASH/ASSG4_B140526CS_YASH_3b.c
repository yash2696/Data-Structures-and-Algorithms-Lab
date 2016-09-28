#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ischar isalpha

#define size 1000

struct BST
{
	char key;
	int read;
	struct BST *left, *right, *parent;
};

typedef struct BST tree;

tree *root = NULL;

void inorder(tree *);
void postorder(tree *);
void preorder(tree *);
tree *createBST(char []);
tree *makeNode(char);
tree *getParent(tree *);
void removeChar(char []);

void invalid()
{   printf("INVALID INPUT\n");
    exit(0);
}

tree *rightmost(tree* node)
{
   if(node == NULL)
	    printf("EMPTY");
		else
    if(node->right == NULL)
        return node;
    else
        if(node==node->right->parent) return rightmost(node->right);
        else return node;
}

tree *leftmost(tree* node)
{   if(node == NULL)
        printf("EMPTY");
    else
        if(node->left == NULL)
            return node;
        else
            if(node==node->left->parent) return leftmost(node->left);
            else return node;
}

int main()
{
	tree *binarytree;
	char prefix[size], copy[size];
	scanf("%[^\n]s", prefix);
	strcpy(copy, prefix);
	
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
	
	binarytree = createBST(prefix);
	
	 printf("Inorder: ");
	 inorder(binarytree);
	 printf("\n");
	 
	 printf("Preorder: ");
	 printf("%s", copy);	 
	 printf("\n");
	 
	 printf("Postorder: ");
	postorder(binarytree);
	printf("\n");
}

tree *getParent(tree *n)
{
	tree *q, *r;
  if(n->key==root->key)
    return NULL;
  r=root;
  while(r->key!=n->key)
  {
   	q=r;
    if(r->key>n->key)
      r=r->left;
    else
      r=r->right;
  }      
  return q;
}

tree *makeNode(char vl)
{   tree *result;
    
    
    result = (tree *)malloc(sizeof(tree));
    
    result->key = vl;
    result->left = NULL;
    result->right = NULL;
    result->parent = NULL;
    result->read = 0;
    return result;
}

void removeChar(char str[size])
{   int i,len;
    
    len = strlen(str);
    for(i=1;i<=len;i++)
        str[i-1] = str[i];
}

tree *createBST(char input[size])
{   tree *temp;
    if(input[0] == '\0')
        return NULL;
    else if(strlen(input)==1 && ischar(input[0]))
    {	temp = makeNode(input[0]);
        removeChar(input);
        return temp;
    }
    else if(!ischar(input[0]))
    {	temp = makeNode(input[0]);
        removeChar(input);
        
        temp->left = createBST(input);
        temp->right = createBST(input);

        if(temp->left != NULL)
            temp->left->parent = temp;
        if(temp->right != NULL)
            temp->right->parent = temp;

        if(!isalpha(leftmost(temp)->key)) invalid();
        if(!isalpha(rightmost(temp)->key)) invalid();
        
        return temp;
    }
    else if(ischar(input[0]))
    {	temp = makeNode(input[0]);
        removeChar(input);
        return temp;
    }
}

void inorder(tree *node)
{
    tree *temp,*pre;
    
    if(node == NULL)
        return;
    
    temp = node;
    
    while(temp != NULL)
    {
        if(temp->left == NULL)
        {   printf("%c", temp->key);
            
            for(;temp->read>0;temp->read--) printf(")");
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
            {   printf("(");
                pre->right = temp;
                temp = temp->left;
            }
            
            else
            {
                pre->right = NULL;
                printf("%c",temp->key);
                rightmost(temp)->read++;
                temp = temp->right;
            }
        }
    }
}

void postorder(tree *node)
{   tree *temp;

    temp = (tree *)malloc(sizeof(tree));
    
    for(temp = node; temp!=NULL;)
    {	if(temp->left != NULL && temp->left->read != -1) temp = leftmost(temp);
        
        printf("%c",temp->key);
        temp->read = -1;
        if(temp->parent!= NULL && temp != temp->parent->right)
            temp = temp->parent->right;
        else
            temp = temp->parent;
    }
}
