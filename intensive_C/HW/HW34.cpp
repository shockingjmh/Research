#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputArray(int*, int);
void ascendingSort(int*, int);
void descendingSort(int*, int);
void outputArray(char*, int*, int);
void swap(int*, int, int);

int main()
{
	srand((unsigned int)time(NULL));

	int intArray[10];
	int arrayLen = 10;

	inputArray(intArray, arrayLen);
	ascendingSort(intArray, arrayLen);
	descendingSort(intArray, arrayLen);

	return 0;
}

void inputArray(int* intArray, int arrayLen)
{
	int i;

	for (i = 0; i < arrayLen; i++)
	{
		intArray[i] = rand()%1001;
	}

	outputArray("초기 배열 상태 : ", intArray, arrayLen);
}
void ascendingSort(int* intArray, int arrayLen)
{
	int i, j;

	for (i = 0; i < arrayLen - 1; i++)
	{
		for (j = i+1; j < arrayLen; j++)
		{
			if (intArray[i] > intArray[j])
			{
				swap(intArray, i, j);
			}
		}
	}

	outputArray("오름차순 정렬 : ", intArray, arrayLen);

	return;
}

void descendingSort(int* intArray, int arrayLen)
{
	int i, j;

	for (i = 0; i < arrayLen - 1; i++)
	{
		for (j = i + 1; j < arrayLen; j++)
		{
			if (intArray[i] < intArray[j])
			{
				swap(intArray, i, j);
			}
		}
	}

	outputArray("내림차순 정렬 : ", intArray, arrayLen);

	return;
}

void outputArray(char* str, int* intArray, int arrayLen)
{
	int i;

	printf(str);

	for (i = 0; i < 10; i++)
	{
		printf("%d ", intArray[i]);
		if (i == 9)
		{
			printf("\n");
		}
	}

	return;
}

void swap(int* intArray, int i, int j)
{
	int temp = 0;

	temp = intArray[i];
	intArray[i] = intArray[j];
	intArray[j] = temp;

	return;
}
