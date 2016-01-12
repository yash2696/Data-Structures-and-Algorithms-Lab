#include<stdio.h>
int main()
{
	FILE *fp1;
	char word[1000],str[100];
	int i,count = 0;
	scanf("%s",str);
	fp1 = fopen("input.txt","r");
	if(fp1 == NULL)
		printf("Invalid filename");
	else
	{
		while(feof(fp1) == 0)
		{
			fscanf(fp1,"%s",word);
			if(strcmp(str,word) == 0)
				count++;
		}
	}
	
	printf("%d\n", count);
	return 0;
}

