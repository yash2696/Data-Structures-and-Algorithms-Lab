#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A 0.6180339887

int capacity;

struct node
{
	int key, flag;
};

int capacity;

int hashFunction(int, int);
void chainedHashInsert(struct node [], int);
void chainedHashSearch(struct node [], int);

int main()
{
	int ele, i, count = 0;
	scanf("%d", &capacity);
	if(capacity < 0)
	{
		printf("INVALID INPUT\n");
		return 0;
	}
	
	else if(capacity == 0)
	{
		printf("Empty list\n");
		return 0;
	}
	getchar();
	struct node chainedHash[capacity];

	for(i = 0; i < capacity; i++)
	{
		chainedHash[i].flag = 0;		//initially empty
	}

	char ch;
	scanf("%c",&ch);
  getchar();
  do
  {
    switch(ch)
    {
	    case 'i':
	    	if(count < capacity)
	    	{
			    scanf("%d",&ele);
			    if(ele > 2147483648 || ele < -2147483648)
			    {
			    	printf("INVALID INPUT\n");
			    }
			    else
			    {
			    getchar();
			    chainedHashInsert(chainedHash, ele);
			    count++;
			    }
			  }
			  else
			  {
			  	printf("CANNOT INSERT\n");
			  	return 0;
			  }
		    break;
    
      case 'f':
        scanf("%d",&ele);
        if(ele > 2147483648 || ele < -2147483648)
			    {
			    	printf("INVALID INPUT\n");
			    }
			    else
			    {
		    getchar();
		    chainedHashSearch(chainedHash, ele);
		    }
		    break;
      
      case 's':
        break;

      default:
        printf("Enter correct choice. %c\n", ch);
        break;
    }
	scanf("%c",&ch);
  getchar();
  } while(ch != 's');

	return 0;
}

void chainedHashInsert(struct node array[], int value)
{
	int r = value % capacity;
	while(r < 0)
	{
		r = (r + capacity) % capacity;
	}
	int steps = floor(capacity * (A * value - floor(A * value)));
	int index = r;
	
	while(1)
	{
		if(array[index].flag == 0)
		{
			array[index].key = value;
			array[index].flag = 1;
			printf("%d\n", index);
			break;
		}
		printf("%d ", index);
		index = (index + steps) % capacity;
	}
}

void chainedHashSearch(struct node array[], int value)
{
	int i = 0, r = value % capacity;
	while(r < 0)
	{
		r = (r + capacity) % capacity;
	}	

	int steps = floor(capacity * (A * value - floor(A * value)));
	int index = r;
	while(1)
	{
		if(array[index].key == value)
		{
				printf("%d FOUND\n", index);
				return;
		}
		else if(array[index].flag == 0)
		{
			printf("%d NOT FOUND\n", index);
			return;
		}

		printf("%d ", index);
		index = (index + steps) % capacity;
	}
}
