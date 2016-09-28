#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
	long int data;
	struct linked_list *next;
};

typedef struct linked_list node;

node *front, *rear;

void enqueue(node *, long int);
long int dequeue(node *);
void print_queue(node *);

int count = 0;

int main()
{
	node *queue;
	front = rear = NULL;
	long int ele, element;
  char ch;
	scanf("%c",&ch);
  getchar();
  do
  {
    switch(ch)
    {
	    case 'e':
		    scanf("%ld",&ele);
		    getchar();
		    if(ele > 1073741824 || ele < 0)
        { 
          printf("Enter elements in the given range.\n");
          return 0;
        }
		    enqueue(queue, ele);
		    break;
   
      case 'd':
      	if((ele = dequeue(queue)) != -1)
      	{
        	printf("%ld\n", ele);
        }
        break;
   
      case 'p':
        print_queue(queue);
        break;
      
      case 's':
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

void enqueue(node *queue, long int element)
{  
	node *temp = (node *)malloc(sizeof(node));
	temp->data = element;
	temp->next = NULL;
	count++;
	if(front == NULL)
	{
		front = rear = temp;
		return;
	}
	
	else
	{
		rear->next = temp;
		rear = temp;
		return;
	}
}

long int dequeue(node *queue)
{
	long int element;
	
	if(front == rear->next)
	{
		rear = front = NULL;
		printf("EMPTY\n");
		return -1;
	}
	
	else
	{
		element = front->data;
		front = front->next;
	}
	
	//printf("Dequeue = %d\n", count);
  return element;
}

void print_queue(node *queue)
{
	if(front == rear->next)
	{
		printf("EMPTY\n");
		return;
	}
	
	else
	{
		node *start = front, *end = rear;
		while(start != end)
		{
			printf("%ld ", start->data);
			start = start->next;
		}
		
		if(start == end)
		{
			printf("%ld",start->data);
		}
		printf("\n");
	}
	return;
}