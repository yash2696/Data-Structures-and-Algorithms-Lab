#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
	long int data;
	struct linked_list *next;
};

typedef struct linked_list node;

void push(node **, long int);
long int pop(node **);
void print_stack(node *);

int main()
{
	long int ele;
	node *stack = NULL;
  char ch;
	scanf("%c",&ch);
  getchar();
  do
  {
    switch(ch)
    {
	    case 'a':
		    scanf("%ld",&ele);
		    if(ele > 1073741824 || ele < 0)
        { 
          printf("Enter elements in the given range.\n");
          return 0;
        }
		    getchar();
		    push(&stack, ele);
				break;
    
		case 'r':
			if((ele = pop(&stack)) != -1)
			{
				printf("%ld\n", ele);
			}
			break;

		case 'p':
			print_stack(stack);
			break;

		case 's':
			stack->next = NULL;
			break;

		default:
			printf("Enter correct choice.\n");
			break;
    }
		scanf("%c",&ch);
	  getchar();
  } while(ch != 's');

  return 0;
}

void push(node **stack, long int element)
{
	node *newnode = (node *)malloc(sizeof(node));
  newnode->data = element;
  newnode->next = *stack;
  *stack = newnode;
  return;
}

long int pop(node **stack)
{
	long int element;
	node *newnode = (node *)malloc(sizeof(node));
	if(*stack == NULL)
	{
		printf("EMPTY\n");
		return -1;
	}
	newnode = *stack;
  element = newnode->data;
  *stack = newnode->next;
  free(newnode);
  return element;
}

void print_stack(node *stack)
{
	if(stack == NULL)
	{
		printf("EMPTY\n");
		return;
	}

	node *current;
	current = stack;
	while(current != NULL)
	{
		printf("%ld ", current->data);
		current = current->next;
	}
	printf("\n");
	return;
}
