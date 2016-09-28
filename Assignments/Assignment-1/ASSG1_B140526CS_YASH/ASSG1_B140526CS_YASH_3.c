#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct record
{
	char id[20];
	char name[20];
	union
	{
		char grade;
		int marks;
	} MARK;
};

void create_record(char *);
void lessthan30(char *);
void lowatte(char *);
void print(char *);

typedef struct record student;

int main(int argc, char *argv[])
{
	int choice;

	do
	{
		printf("1. Add student record into the file.\n2. Display the names of students who obtained less than 30 marks.\n3. Display the names of students who have less attendance.\n4. Print the contents of the file.\n5. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create_record(argv[1]);
				printf("\n");
				break;
			case 2:
				lessthan30(argv[1]);
				printf("\n");
				break;
			case 3:
				lowatte(argv[1]);
				printf("\n");
				break;
			case 4:
				print(argv[1]);
				printf("\n");
				break;
			case 5:
				printf("Exiting....\n\n");
				break;
			default:
				printf("Enter correct choice...\n\n");
		}
	}	while(choice != 5);
	return 0;
}

void create_record(char *file)
{
	int flag = 0;
	char temp[4];
	FILE *fp;
	fp = fopen(file,"a");

	student new;
	
	printf("Enter name, id and mark:\n");
	scanf("%s%s%s", new.name, new.id, temp);
	
	if((temp[0] == 'A' || temp[0] == 'I') && temp[1] == '\0')
	{
		new.MARK.grade = temp[0];
		flag = 1;
	}
	else
	{
		new.MARK.marks = atoi(temp);
		flag = 2;
	}

	if(flag == 1)
	{
		fprintf(fp,"%-10s\t%4s\t%4c\n", new.name,new.id,new.MARK.grade);
	}
	else if(flag == 2)
	{
		fprintf(fp,"%-10s\t%4s\t%4d\n", new.name,new.id,new.MARK.marks);
	}
	else if(flag == 0)
	{
		printf("Invalid Mark entry\n");
	}

	fclose(fp);
}

void lessthan30(char *file)
{
	FILE *fp;
	fp = fopen(file,"r+");

	if(fp == NULL)
	{
		printf("File Opening failed...\n");
	}

	student new;

	char temp[4];

	printf("Students who scored less than 30:\n");

	while(!feof(fp))
	{
		fscanf(fp,"%s %s %s",new.name,new.id,temp);
		
		if(feof(fp))
		{
			break;
		}

		if((temp[0] == 'A' || temp[0] == 'I') && temp[1] == '\0')
		{
			new.MARK.grade = temp[0];
		}

		else
		{
			new.MARK.marks = atoi(temp);
		}

		if(new.MARK.marks < 30)
		{
			printf("%s\n",new.name);
		}
	}
	fclose(fp);
}

void lowatte(char *file)
{
	FILE *fp;
	fp = fopen(file,"r+");

	if(fp == NULL)
	{
		printf("File Opening failed...\n");
	}

	student new;

	char temp[4];

	printf("Students with insufficient attendance:\n");
	
	while(!feof(fp))
	{
			fscanf(fp,"%s %s %s",new.name,new.id,temp);
			
			if(feof(fp))
			{
				break;
			}

			if((temp[0] == 'A' || temp[0] == 'I') && temp[1] == '\0')
			{
				new.MARK.grade = temp[0];
			}

			else
			{
				new.MARK.marks = atoi(temp);
			}

			if(new.MARK.grade == 'I')
			{
				printf("%s\n",new.name);
			}
	}
	fclose(fp);
}

void print(char *file)
{
	FILE *fp;
	fp = fopen(file,"r5");

	if(fp == NULL)
	{
		printf("File Opening failed...\n");
	}

	student new;

	char temp[4];

	int flag = 0;
	printf("+------------+--------------+------+\n");
	printf("| Student_ID | Student_Name | Mark |\n");
	printf("+------------+--------------+------+\n");
	while(!feof(fp))
	{
			fscanf(fp,"%s %s %s",new.name,new.id,temp);

			if(feof(fp))
			{
				break;
			}

			if((temp[0] == 'A' || temp[0] == 'I') && temp[1] == '\0')
			{
				new.MARK.grade = temp[0];
				printf("| %-10s | %-12s | %-4c |\n", new.id,new.name,new.MARK.grade);
			}

			else
			{
				new.MARK.marks = atoi(temp);
				printf("| %-10s | %-12s | %-4d |\n", new.id,new.name,new.MARK.marks);
			}
	}
	printf("+------------+--------------+------+\n");
	fclose(fp);
}
