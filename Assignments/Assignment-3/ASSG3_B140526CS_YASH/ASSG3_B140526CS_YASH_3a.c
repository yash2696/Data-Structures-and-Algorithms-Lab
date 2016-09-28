#include <stdio.h>

void enqueue(long int [], long int);
long int dequeue(long int []);
void print_queue(long int []);
int isFull(long int []);
int isEmpty(long int []);

int front = -1, rear = -1, size;
int main()
{
	scanf("%d",&size);
  if(size <= 0 || size >= 100)
  {
    printf("Enter capacity in given range.\n");
    return 0;
  }

  size--;
  getchar();
	long int queue[size], ele, element;
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
        	printf("%d\n", ele);
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
  }while(ch != 's');

  return 0;
}

void enqueue(long int queue[], long int element)
{
  if((front == 0 && rear == size - 1) || (front == rear + 1))
  {
    printf("OVERFLOW\n");
    return;
  }
  
  if(front == -1)
  {
    front = 0;
  }

  if(rear == size-1)
  {
    rear = 0;
  }
  else
  {
    rear = rear + 1;
  }
    
  queue[rear] = element;
}

long int dequeue(long int queue[])
{
	long int element;
  if(front == -1)
  {
    printf("EMPTY\n");
    return -1;
  }

  element = queue[front];

  if(front == rear)
  {
    front = -1;
    rear = -1;
  }

  else if(front == size-1)
  {
    front = 0;
  }
  
  else
  {
    front = front + 1;
  }

  return element;
}

void print_queue(long int queue[])
{
	if(front == -1)
	{
		printf("EMPTY\n");
		return;
	}
	
  int start = front;
  if(front <= rear)
	{
    while(start <= rear)
  	{
  		printf("%ld ", queue[start]);
  		start++;
  	}
  }
  else
  {
    while(start <= size-1)
    {
      printf("%ld ", queue[start++]);
    }

    start = 0;
    while(start <= rear)
    {
      printf("%ld ", queue[start++]);
    }
  }
  printf("\n");
}