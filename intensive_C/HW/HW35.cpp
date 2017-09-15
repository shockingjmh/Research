#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputNum(int (*)[4], int, int);
void output(int (*)[4], int, int);

int main()
{
	srand((unsigned int)time(NULL));

	int num[3][4] = {0, };
	int sizeRow;
	int sizeCol;

	sizeRow = sizeof(num) / sizeof(num[0]);
	sizeCol = sizeof(num[0]) / sizeof(num[0][0]);

	inputNum(num, sizeRow, sizeCol);
	output(num, sizeRow, sizeCol);
	
	return 0;
}

void inputNum(int(*p)[4], int sizeRow, int sizeCol)
{
	int i, j;

	for (i = 0; i < sizeRow; i++)
	{
		for (j = 0; j < sizeCol; j++)
		{
			p[i][j] = rand() % 100 + 1;
		}
	}

	return;
}

void output(int(*p)[4], int sizeRow, int sizeCol)
{
	int i, j;
	int sum;

	for (i = 0; i < sizeRow; i++)
	{
		sum = 0;
		printf("%5d행 :", i);
		for (j = 0; j < sizeCol; j++)
		{
			printf("%5d", p[i][j]);
			sum += p[i][j];
		}
		printf("%5d행의 합 :%5d\n", i, sum);
	}
	
	printf("열의 합 :");
	for (i = 0; i < sizeCol; i++)
	{
		sum = 0;
		for (j = 0; j < sizeRow; j++)
		{
			sum += p[j][i];
		}
		printf("%5d", sum);
	}
	printf("\n");

	return;
}