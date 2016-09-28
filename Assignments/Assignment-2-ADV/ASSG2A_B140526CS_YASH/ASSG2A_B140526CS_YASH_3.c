#include<stdio.h>
#include<string.h>

#define INTEGERS 524288

void quickSort(int [], int, int);
int partition(int [], int, int);
void swap(int [], int, int);
void merge(int [], int [], int, int, int);
void merge8into1();
void merge4into1();
void merge2into1();

int main()
{
	FILE *fp,*fp1,*fp2;
	
	fp = fopen("Bigfile","r");
	if(fp == NULL)
	{
		printf("Error");
	}
	
	int i,a=0,j,k,l;
	
	//creating 64 sorted files from Bigfile
	for(i=1;i<=64;i++)
	{
		int a1[INTEGERS], b1[INTEGERS];
		for(j=0;j<INTEGERS;j++)
		{
			if(feof(fp))
			{
				printf("Error\n");
				return 0;
			}
			fscanf(fp,"%d",&a1[j]);
		}
		quickSort(a1,0,INTEGERS-1);
		
		for(k=0;k<INTEGERS;k++)
		{
			if(feof(fp))
			{
				printf("Error\n");
				return 0;
			}
			fscanf(fp,"%d",&b1[k]);
		}
		
		quickSort(b1,0,INTEGERS-1);
		
		merge(a1,b1,0,(INTEGERS-1),i);
	}
	merge8into1();
	merge4into1();
	merge2into1();
	fclose(fp);
	return 0;
}

void quickSort(int record[], int start, int end)
{
	int index;
	if(start < end)
	{
		index = partition(record,start,end);
		quickSort(record,start,index-1);
		quickSort(record,index+1,end);
	}
}

int partition(int array[], int start, int end)
{
	int pIndex = start, i, key = array[end];
	for(i=start;i<end;i++)
	{
		if(key >= array[i])
		{
			swap(array, i, pIndex);
			pIndex++;
		}
	}
	swap(array, pIndex, end);
	return pIndex;
}

void swap(int array[], int i, int pIndex)
{
	int temp;
	temp = array[i];
	array[i] = array[pIndex];
	array[pIndex] = temp;
}

void merge(int a1[], int a2[], int start, int end, int name)
{
	int k=0;
	int i = start, j = start;
	int auxarray[2*INTEGERS];
	
	FILE *fp;
	char filename[5];
	sprintf(filename,"%d",name);
	fp = fopen(filename,"w");

	while(i<INTEGERS && j<INTEGERS)
	{
		if(a1[i] < a2[j])
		{
			auxarray[k++] = a1[i++];
		}
		else
		{
			auxarray[k++] = a2[j++];
		}
	}
	
	while(i<INTEGERS)
	{
		auxarray[k++] = a1[i++];
	}
	
	while(j<INTEGERS)
	{
		auxarray[k++] = a2[j++];
	}
	
	for(i=0;i<2*INTEGERS;i++)
	{		
		fprintf(fp,"%d\n",auxarray[i]);
	}
	fclose(fp);
}

void merge8into1()
{
	int i,k=0;
	for(i=1;i<=8,k<=56;i++,k+=8)
	{
		FILE *fp[8], *fp1;
		char filename[5];
		int l,x,j,n;
		for(j=0;j<8;j++)
		{
			sprintf(filename,"%d",k+j+1);
			fp[j] = fopen(filename,"r");
			if(fp[j] == NULL)
			{
				printf("Error in opening file %d\n",k+j+1);
				return;
			}
		}
				
		sprintf(filename,"%d",i+100);
		fp1 = fopen(filename,"w");
		for(x=0;x<8;x++)
		{
			int m=0,a1[2*INTEGERS]={0};
			for(j=0;j<8;j++)
			{
				for(l=0;l<INTEGERS/4;l++)
				{
					fscanf(fp[j],"%d",&a1[m++]);
				}
			}
			quickSort(a1,0,(2*INTEGERS - 1));
			for(n=0;n<(2*INTEGERS - 1);n++)
			{
				fprintf(fp1,"%d\n",a1[n]);
			}
		}
		for(j=(i-1)*8;j<i*8;j++)
		{
			sprintf(filename,"%d",j+1);
			remove(filename);
		}
		fcloseall();
	}
}

void merge4into1()
{
	int i,k=0;
	for(i=101;i<=102,k<=4;i++,k+=4)
	{
		FILE *fp[4], *fp1;
		char filename[5];
		int l,x,j,n;
		for(j=0;j<4;j++)
		{
			sprintf(filename,"%d",k+j+101);
			fp[j] = fopen(filename,"r");
			if(fp[j] == NULL)
			{
				printf("Error in opening file %d\n",k+j+1);
				return;
			}
		}
				
		sprintf(filename,"%d",i+100);
		fp1 = fopen(filename,"w");
		for(x=0;x<32;x++)
		{
			int m=0,a1[2*INTEGERS]={0};
			for(j=0;j<4;j++)
			{
				for(l=0;l<INTEGERS/2;l++)
				{
					fscanf(fp[j],"%d",&a1[m++]);
				}
			}
			quickSort(a1,0,2*INTEGERS-1);
			for(n=0;n<2*INTEGERS-1;n++)
			{
				fprintf(fp1,"%d\n",a1[n]);
			}
		}
		
		for(j=100+k+1;j<=k+104;j++)
		{
			sprintf(filename,"%d",j);
			remove(filename);
		}
		fcloseall();
	}
}

void merge2into1()
{
	FILE *fp[2], *fp1;
	char filename[5];
	int l,x,j,n;
	for(j=0;j<2;j++)
	{
		sprintf(filename,"%d",j+201);
		fp[j] = fopen(filename,"r");
		if(fp[j] == NULL)
		{
			printf("Error in opening file %d\n",j+201);
			return;
		}
	}
			
	fp1 = fopen("BigfileOutput","w");
	for(x=0;x<32;x++)
	{
		int m=0,a1[2*INTEGERS]={0};
		for(j=0;j<2;j++)
		{
			for(l=0;l<INTEGERS;l++)
			{
				fscanf(fp[j],"%d",&a1[m++]);
			}
		}
		quickSort(a1,0,2*INTEGERS-1);
		for(n=0;n<2*INTEGERS-1;n++)
		{
			fprintf(fp1,"%d\n",a1[n]);
		}
	}
	
	for(j=200+1;j<=202;j++)
	{
		sprintf(filename,"%d",j);
		remove(filename);
	}
	fcloseall();
}
