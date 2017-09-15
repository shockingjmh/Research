#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputNum(int (*)[5], int, int);
void output(int (*)[5], int, int);
void sum(int (*)[5], int, int);

int main()
{
	srand((unsigned int)time(NULL));

	int num[5][5] = { 0, };
	int sizeRow = sizeof(num)/sizeof(num[0]);
	int sizeCol = sizeof(num[0])/sizeof(num[0][0]);

	inputNum(num, sizeRow, sizeCol);
	output(num, sizeRow, sizeCol);

	return 0;
}

void inputNum(int (*p)[5], int sizeRow, int sizeCol)
{
	int i, j;

	for (i = 0; i < sizeRow; i++)
	{
		for (j = 0; j < sizeCol; j++)
		{
			p[i][j] = rand() % 20 + 1;
		}
	}

	return;
}

void output(int(*p)[5], int sizeRow, int sizeCol)
{
	int i, j;

	for (i = 0; i < sizeRow; i++)
	{
		printf("%d¹ø Çà :", i);
		for (j = 0; j < sizeCol; j++)
		{
			printf("%4d", p[i][j]);
			sum(p, i, j);
		}
		printf("\n");
	}

	return;
}

void sum(int (*p)[5], int i, int j)
{
	static int sum1 = 0;
	static int sum2 = 0;
	static int sum3 = 0;
	static int count = 0;

	count++;

	if (i < j)
	{
		sum2 += p[i][j];
	}
	else if (i > j)
	{
		sum3 += p[i][j];
	}
	else
	{
		sum1 += p[i][j];
	}

	if (count == 25)
	{
		printf("\n\nsum1 = %3d\n", sum1);
		printf("sum2 = %3d\n", sum2);
		printf("sum3 = %3d\n", sum3);
	}

	return;
}