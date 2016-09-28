#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct array
{
  long int number;
  long int priority;
};

typedef struct array record;

int parent(int );
void insert(record *, long int, long int);
void get_min(record *);
void extract_min(record *);
void decrease_priority(record *, long int, long int);
void minHeapify(record *, int, int);
void swap(long int *, long int *);
int checkNumber(long int );

int size = 0;

int main()
{
  record queue[10000]; 
	long int ele, pr;
	char ch;
	scanf("%c",&ch);
  getchar();
  do
  {
    switch(ch)
    {
	    case 'a':
		    scanf("%ld",&ele);
		    scanf("%ld",&pr);
		    getchar();
        if(checkNumber(ele) && checkNumber(pr) && ele >= 0 && pr >=1)
        {
		      insert(queue, ele, pr);
          size++;
        }
        else
        {
          printf("Enter elements in given range.\n");
        }
		    break;
    
        case 'e':
      	extract_min(queue);
        break;
   
      case 'g':
				get_min(queue);
        break;
      
      case 'd':
		    scanf("%ld",&ele);
		    scanf("%ld",&pr);
		    getchar();
        if(checkNumber(ele) && checkNumber(pr) && ele >= 0 && pr >=1)
        {
          decrease_priority(queue, ele, pr);
        }
        else
        {
          printf("Enter elements in given range.\n");
        }
      	
        break;
  
      case 's':
        printf("\n");
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

int parent(int i)
{
  float p;
  p = ( (float) i / 2.0) - 1.0;
  return ceil(p);
}

void insert(record *queue, long int ele, long int pr)
{
  int i = size;
  queue[i].number = ele;
  queue[i].priority = pr;

  while(i > 0 && (queue[i].priority < queue[parent(i)].priority))
  {
    swap(&queue[parent(i)].priority, &queue[i].priority);
    swap(&queue[parent(i)].number, &queue[i].number);
    i = parent(i);
  }  
  return;
}

void get_min(record * queue)
{
  printf("%ld (%ld)\n", queue[0].number, queue[0].priority);
  return;
}

void extract_min(record *queue)
{
  if(size == 0)
  {
    printf("EMPTY\n");
    return;
  }
  long int minNumber = queue[0].number;
  long int minPriority = queue[0].priority;
  queue[0].number = queue[size-1].number;
  queue[0].priority = queue[size-1].priority;
  size = size - 1;
  minHeapify(queue, 0, size);
  printf("%ld (%ld)\n", minNumber, minPriority);
}

void decrease_priority(record *queue, long int ele, long int pr)
{
  int i, pos = -1;
  for(i=0;i<size;i++)
  {
    if(ele == queue[i].number)
    {
      pos = i;
      break;
    }
  }

  if(pos == -1)
  {
    printf("Element not found\n");
    return;
  }
  else if(queue[pos].priority < pr)
  {
    printf("New key is larger than current key\n");
    return;
  }

  queue[pos].priority = pr;

  while(pos > 0 && (queue[parent(pos)].priority > queue[pos].priority))
  {
    swap(&queue[parent(pos)].priority, &queue[pos].priority);
    swap(&queue[parent(pos)].number, &queue[pos].number);
    pos = parent(pos);
  }
}

void minHeapify(record *queue, int i, int heap_size)
{
  int l = (2*i+1),
      r = (2*i+2),
      largest;
    
  if((l < heap_size) && (queue[l].priority < queue[i].priority))
  {
    largest = l;
  }
  else
  {
    largest = i;
  }

  if((r < heap_size) && (queue[r].priority < queue[largest].priority))
  {
    largest = r;
  }
  
  if(largest != i)
  {
    swap(&queue[i].priority,&queue[largest].priority);
    swap(&queue[i].number, &queue[largest].number);
    minHeapify(queue,largest,heap_size);
  }
}

void swap(long int *a, long int *b)
{
  long int temp = *a;
  *a = *b;
  *b = temp;
}

int checkNumber(long int num)
{
  if(num <= 1073741824 || num >= -1073741824)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}