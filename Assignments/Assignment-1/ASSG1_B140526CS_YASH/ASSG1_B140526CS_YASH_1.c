#include<stdio.h>
#include<string.h>
void sort(char []);

int main()
{
	int i;
	char str1[100000], str2[100000];
	printf("\nEnter str1:");
	scanf("%s",str1);
	printf("\nEnter str2:");
	scanf("%s",str2);
	
	for(i=0; str1[i]!='\0';i++)
	{
		if(str1[i] < 'a' || str1[i] > 'z')
		{
			printf("\nEnter only lower case english alphabets\n");
			return 0;
		}
	}
	
	for(i=0; str2[i]!='\0';i++)
	{
		if(str2[i] < 'a' || str2[i] > 'z')
		{
			printf("\nEnter only lower case english alphabets\n");
			return 0;
		}
	}
	
	sort(str1);
	sort(str2);

	for(i=0; str1[i]!='\0' && str2[i]!='\0'; i++)
	{
		if(str1[i] != str2[i])
		{
			break;
		}
	}
	
	if(i-1 != strlen(str1) && i != strlen(str2))
	{
		printf("\nNO");
	}
	else
	{
		printf("\nYES");
	}
	printf("\n");
	return 0;
}

void sort(char str[])
{
	int i,j;
	for(i=1;str[i]!='\0';i++)
	{
		char temp = str[i];
		j=i-1;
		while(j>=0 && str[j]>temp)
		{
			str[j+1]=str[j];
			j--;
		}
		str[j+1]=temp;
	}
}		
