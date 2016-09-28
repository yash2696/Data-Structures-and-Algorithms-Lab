#include<stdio.h>
#define MAXSIZE 999

void push(long int [], long int);
long int pop(long int []);
void print_stack(long int []);
int isFull(long int []);
int isEmpty(long int []);

int top, size;
int main()
{
	scanf("%d",&size);
  if(size <= 0 || size >= 1000)
  {
    printf("Please enter the size in given range.\n");
    return 0;
  }
  
  getchar();
  top = -1;
	long int stack[size], ele;
  char ch;
	scanf("%c",&ch);
  getchar();
  do
  {
    switch(ch)
    {
	    case 'a':
		    scanf("%ld",&ele);
		    getchar();
        if(ele > 1073741824 || ele < 0)
        { 
          printf("Enter elements in the given range.\n");
          return 0;
        }
		    push(stack, ele);
		    break;
    
      case 'r':
      	if((ele = pop(stack)) != -1)
      	{
        	printf("%ld\n", ele);
        }
        break;
   
      case 'p':
        print_stack(stack);
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

void push(long int stack[], long int element)
{
  if(isFull(stack))
  {
    printf("OVERFLOW\n");
    return;
  }
	
  top = top + 1;  
  stack[top] = element;

  return;
}

int isFull(long int stack[])
{
  if(top == size-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

long int pop(long int stack[])
{
	long int element;
  if(isEmpty(stack))
  {
    printf("EMPTY\n");
    return -1;
  }

  element = stack[top];
  top = top - 1;
  
  return element;
}

int isEmpty(long int stack[])
{
  if(top < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void print_stack(long int stack[])
{
	if(isEmpty(stack))
	{
		printf("EMPTY\n");
		return;
	}
	
	else
	{
		int start = 0, end = top;
		while(end >= start)
		{
			printf("%ld ", stack[end]);
			end--;
		}
		printf("\n");
	}
	return;
}
