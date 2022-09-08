#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char name[20];
	int rollno;
} ST;

ST stud[200];

void main()
{
	printf("Sorting the text file in C\n");
	printf("---------------------------");
	struct student temp;
	FILE *fp;
	int i = 0, size, j;
	char ch;
	printf("\nReading the file.....\n");
	fp = fopen("stud.txt", "r");
	if (fp == NULL)
	{
		printf("\n Cannot open the file \n");
		exit(0);
	}
	while (ch != EOF)
	{
		fscanf(fp, "%s%d", stud[i].name, &stud[i].rollno);
		ch = fgetc(fp);
		i++;
	}
	printf("Sorting based on Roll Numbers........\n");
	size = i - 1;
	for (i = 1; i < size; ++i)
		for (j = 0; j < size - i; j++)
			if (stud[j + 1].rollno < stud[j].rollno)
			{
				temp = stud[j];
				stud[j] = stud[j + 1];
				stud[j + 1] = temp;
			}
	printf("Writting sorted Data to a text file.....\n");
	fp = fopen("studsorted.txt", "w");
	for (i = 0; i < size; i++)
		fprintf(fp, "%s %d \n", stud[i].name, stud[i].rollno);
	printf("\nThe file is sorted successfully and saved as SortedData.txt. \n \n");
}