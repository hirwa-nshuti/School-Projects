#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char name[20];
	int rollno;
} ST;

int size;
ST stud[200];
FILE *fp;

void read()
{
	int i = 0, size, j;
	char ch;

	fp = fopen("stud.txt", "r");
	if (fp == NULL)
	{
		printf("\n Cannot open the file \n");
		exit(0);
	}
	//Reading all the contents of text file
	while (ch != EOF)
	{
		fscanf(fp, "%s%d", stud[i].name, &stud[i].rollno);
		ch = fgetc(fp);
		i++;
	}
	size = i - 1;
}

void sortdata()
{
	ST temp;
	int i, j;
	for (i = 1; i < size; ++i)
		for (j = 0; j < size - i; j++)
			if (stud[j + 1].rollno < stud[j].rollno)
			{
				temp = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = temp;
			}	
}

void dumpSorted()
{	
	int i;
	fp = fopen("SortedData.txt", "w");
	for (i = 0; i < size; i++)
		fprintf(fp, "%s %d \n", stud[i].name, stud[i].rollno);
	printf("\n The file is sorted successfully and saved as SortedData.txt \n \n");
	fclose(fp);
}


void main()
{
	printf("Sorting the text file in C\n");
	printf("---------------------------");
	printf("\nReading the file.....\n");
	read();
	printf("Sorting based on Roll Numbers........\n");
	sortdata();
	printf("Writting sorted Data to a text file.....\n");
	dumpSorted();
}