#pragma warning(disable:4996)
#include <stdio.h>

void output(int*, int);

int main()
{
	int ary[] = { 2, 8, 15, 1, 8, 10, 5, 19, 19, 3, 5, 6, 6, 2, 8, 2, 12, 16, 3, 8, 17, 12, 5, 3, 14, 13, 3, 2, 17, 19, 16, 8, 7, 12, 19, 10, 13, 8, 20, 16,
		15, 4, 12, 3, 14, 14, 5, 2, 12, 14, 9, 8, 5, 3, 18, 18, 20, 4 };
	int count[21] = { 0, };
	int sizeArray = sizeof(ary) / sizeof(ary[0]);
	int i;

	for (i = 0; i < sizeArray; ++i)
	{
		++count[ary[i] - 0];
	}

	sizeArray = sizeof(count) / sizeof(count[0]);

	output(count, sizeArray);

	return 0;
}

void output(int *count, int sizeArray)
{
	int i;

	for (i = 1; i < sizeArray; ++i)
	{
		printf("%3d - %3d °³\n", i, count[i]);
	}
}

