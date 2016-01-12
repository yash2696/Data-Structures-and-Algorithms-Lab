#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100],str2[100];
	int i, k = 0, m = 0;
	printf("Enter string 1:\n");
	scanf("%s",str1);
	printf("Enter string 2:\n");
	scanf("%s",str2);
	
	int l1 = strlen(str1),
	    l2 = strlen(str2);


	char str3[l1+l2];

	if(l1 <= l2)
	{
		for(i = 0; str1[k] != '\0'; i++)
		{
			if(i % 2 == 0)
			{
				str3[i] = str1[k++];
			}
			else
			{
				str3[i] = str2[m++];
			}
		}
		
		for(; i < l1 + l2; i++)
		{
			str3[i] = str2[m++];
		}
		str3[i] = '\0';
	}

	else
	{
		for(i = 0; str2[m] != '\0'; i++)
		{
			if(i % 2 == 0)
			{
				str3[i] = str1[k++];
			}
			else
			{
				str3[i] = str2[m++];
			}
		}
		for(; i < l1 + l2; i++)
		{
			str3[i] = str1[k++];
		}
		str3[i] = '\0';

	}

	printf("\n%s\n", str3);
	return 0;
}
