#include<stdio.h>

float add(float a, float b)
{
	return (a + b);
}

float sub(float a, float b)
{
	return (a - b);
}

float mul(float a, float b)
{
	return (a * b);
}

float div(float a, float b)
{
	return (a / b);
}

int main()
{
	float a,b;
	int choice;
	printf("Enter the numbers: ");
	scanf("%f",&a);
	scanf("%f",&b);
	
	// function pointers
	
	float (*addition)(float, float);
	addition = add;
	
	float (*subtraction)(float, float);
	subtraction = sub;
	
	float (*multiplication)(float, float);
	multiplication = mul;
	
	float (*division)(float, float);
	division = div;
	
	do {
		printf("Menu\n");
		printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
		printf("Enter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				
				printf("%.2f\n\n",(*addition)(a,b));
				break;
			case 2:
				printf("%.2f\n\n",(*subtraction)(a,b));
				break;
			case 3:
				printf("%.2f\n\n",(*multiplication)(a,b));
				break;
			case 4:
				if(b == 0)
					printf("Undefined Operation\n\n");
				else
					printf("%.2f\n\n",(*division)(a,b));
				break;
			case 5:
				printf("Exiting\n");
				break;
			default:
				printf("Enter correct choice..\n");
		}
	} while(choice!=5);
	return 0;
}


