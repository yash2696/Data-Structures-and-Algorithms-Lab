#include<stdio.h>
#include<string.h>

struct STUDENT
{
	char roll_no[10];
	char name[20];
	int mark;
};

void quickSort(struct STUDENT [], int, int);
int partition(struct STUDENT [], int, int);
void swap(struct STUDENT [], int, int);

int main()
{
	int n, i;
	scanf("%d", &n);
	if(n<=0)
	{
		printf("Invalid size of array.\n");
		return 0;
	}
	
	struct STUDENT STUDENT_LIST[n];
	for(i=0;i<n;i++)
	{
		char roll_no[10];
		int mark, length;
		scanf("%s%s%d",roll_no,STUDENT_LIST[i].name,&mark);
		length = strlen(roll_no);
		if(length != 9)
		{
			printf("Invalid Roll No..\n");
			return 0;
		}
		
		if((roll_no[0]>='A' && roll_no[0]<='Z') && (roll_no[1]>='0' && roll_no[1]<='9') && (roll_no[2]>='0' && roll_no[2]<='9') && (roll_no[3]>='0' && roll_no[3]<='9') && (roll_no[4]>='0' && roll_no[4]<='9') && (roll_no[5]>='0' && roll_no[5]<='9') && (roll_no[6]>='0' && roll_no[6]<='9') && (roll_no[7]>='A' && roll_no[7]<='Z') && (roll_no[8]>='A' && roll_no[8]<='Z') && roll_no[10] == '\0')
		{
			strcpy(STUDENT_LIST[i].roll_no, roll_no);
		}
		else
		{
			printf("Invalid Roll No..\n");
			return 0;
		}
		
		if(mark >= 0 && mark <= 100)
		{
			STUDENT_LIST[i].mark = mark;
		}
		else
		{
			printf("Invalid Marks..\n");
			return 0;
		}
	}

	quickSort(STUDENT_LIST,0,n-1);
	printf("+----------+------+------+\n");
	printf("| ROLL_NO  | NAME | MARK |\n");
	printf("+----------+------+------+\n");
	for(i=0;i<n;i++)
	{
		printf("|%-10s|%-6s|%-6d|\n",STUDENT_LIST[i].roll_no, STUDENT_LIST[i].name, STUDENT_LIST[i].mark);
	}
	printf("+----------+------+------+\n");
	return 0;
}

void quickSort(struct STUDENT record[], int start, int end)
{
	int index;
	if(start >= end)
	{
		return;
	}
	else
	{
		index = partition(record,start,end);
		quickSort(record,start,index-1);
		quickSort(record,index+1,end);
	}
}

int partition(struct STUDENT array[], int start, int end)
{
	int pIndex = start, i, key = array[end].mark;
	for(i=start;i<end;i++)
	{
		if(key <= array[i].mark)
		{
			swap(array, i, pIndex);
			pIndex++;
		}
	}
	swap(array, pIndex, end);
	return pIndex;
}

void swap(struct STUDENT array[], int i, int pIndex)
{
	int temp;
	temp = array[i].mark;
	array[i].mark = array[pIndex].mark;
	array[pIndex].mark = temp;
	
	char roll_no[10];
	strcpy(roll_no, array[i].roll_no);
	strcpy(array[i].roll_no, array[pIndex].roll_no);
	strcpy(array[pIndex].roll_no, roll_no);
	
	char name[20];
	strcpy(name, array[i].name);
	strcpy(array[i].name, array[pIndex].name);
	strcpy(array[pIndex].name, name);
}
