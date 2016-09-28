#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *next;
};

typedef struct node hashTable;

int capacity;

int hashFunction(int);
void chainedHashInsert(hashTable *[], int);
void chainedHashSearch(hashTable *[], int);

int main()
{
	int ele, i, count = 0;
	scanf("%d", &capacity);
	if(capacity < 0)
	{
		printf("Invalid Input\n");
		return 0;
	}

	else if(capacity == 0)
	{
		printf("EMPTY LIST\n");
		return 0;
	}
	getchar();
	hashTable *chainedHash[capacity];

	for(i = 0; i < capacity; i++)
	{
		chainedHash[i] = NULL;
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
			    	return 0;
			    }
			    getchar();
			    chainedHashInsert(chainedHash, ele);
			    count++;
			  }
			  else
			  {
			  	printf("CANNOT INSERT\n");
			  	return 0;
			  }
		    break;
    
      case 'f':
        scanf("%d",&ele);
		    getchar();
		    if(ele > 2147483648 || ele < -2147483648)
			    {
			    	printf("INVALID INPUT\n");
			    	return 0;
			    }
		    chainedHashSearch(chainedHash, ele);
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

int hashFunction(int val)
{
	int key = val % capacity;
	while(key < 0)
	{
		key = (key + capacity) % capacity;
	}
	return key;
}

void chainedHashInsert(hashTable *array[], int value)
{
	int index = hashFunction(value);
	printf("%d\n", index);
	if(array[index] == NULL)
	{
		hashTable *node = (hashTable *)malloc(sizeof(hashTable));
		node->key = value;
		node->next = NULL;
		array[index] = node;
	}
	else
	{
		hashTable *temp = array[index];
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		hashTable *temp1 = (hashTable *)malloc(sizeof(hashTable));
		temp1->key = value;
		temp1->next = NULL;
		temp->next = temp1;
	}
}

void chainedHashSearch(hashTable *array[], int value)
{
	int index = hashFunction(value);

	while(array[index] != NULL)
	{
		if(array[index]->key == value)
		{
				printf("%d FOUND\n", index);
				return;
		}
		array[index] = array[index]->next;
	}
	printf("%d NOT FOUND\n", index);
	return;
}