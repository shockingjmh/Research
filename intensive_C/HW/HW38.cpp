#pragma warning(disable:4996)
#include <stdio.h>

void initializeArray(int (*)[3][4], int, int);
void calcSum(int (*)[3][4], int, int);
void output(int (*)[3][4], int, int);

int main()
{
	int num[3][3][4] = { 0, };
	int sizeRow = sizeof(num[0]) / sizeof(num[0][0]);
	int sizeCol = sizeof(num[0][0]) / sizeof(num[0][0][0]);

	initializeArray(num, sizeRow, sizeCol);
	calcSum(num, sizeRow, sizeCol);
	output(num, sizeRow, sizeCol);

	return 0;
}

void initializeArray(int(*p)[3][4], int sizeRow, int sizeCol)
{
	int i, j, k;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < sizeRow; j++)
		{
			for (k = 0; k < sizeCol; k++)
			{
				if (i == 0)
				{
					p[i][j][k] = j + k + 1;
				}
				else
				{
					p[i][j][k] = j + k + 4;
				}
			}
		}
	}

	return;
}

void calcSum(int(*p)[3][4], int sizeRow, int sizeCol)
{
	int i, j;

	for (i = 0; i < sizeRow; i++)
	{
		for (j = 0; j < sizeCol; j++)
		{
			p[2][i][j] = p[0][i][j] + p[1][i][j];
		}
	}

	return;
}

void output(int(*p)[3][4], int sizeRow, int sizeCol)
{
	int i, j, k;

	for (i = 0; i < 3; i++)
	{
		printf("(%d¸é)\n", i);
		for (j = 0; j < sizeRow; j++)
		{
			for (k = 0; k < sizeCol; k++)
			{
				printf("%3d", p[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	return;
}