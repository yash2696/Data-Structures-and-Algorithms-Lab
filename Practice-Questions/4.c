#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100],str2[100];
	int i,len1,len2;
	scanf("%s %s",str1,str2);
	len1=strlen(str1);
	len2=strlen(str2);
	puts(str1);
	puts(str2);
	for(i=0;*(str2+i)!='\0';i++)
	{
		*(str1+len1+i) = *(str2+i);
	}
	*(str1+len1+len2) = '\0';
	printf("%s\n",str1); 
}
