/*
    Algorithm for this program:
        1) Open the file using fopen().
        2) Scan the file and copy it to the array using fscanf().
        3) Apply any sorting algorithm that you want.
        4) Print to console.
*/
#include <stdio.h>
#include <stdlib.h>

#ifndef Reader
#define Reader

typedef struct student
{
	char name[20];
	int rollno;
} ST;

#endif