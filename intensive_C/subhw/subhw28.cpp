#pragma warning(disable:4996)
#include <stdio.h>

void inputNum(int*, int);
void output(int*, int);
void myfflush();

int main()
{
	int number[10];
	int sizeArray;

	sizeArray = sizeof(number) / sizeof(number[0]);
	
	inputNum(number, sizeArray);
	output(number, sizeArray);

	return 0;
}

void inputNum(int *number, int sizeArray)
{
	int input;
	int res;
	int count = 0;
	int i = 0;
	int j = 0;

	printf("# 정수 10개를 입력해주세요(순서는 상관없음)\n");

	while (1)
	{
		if (count == 10)
		{
			break;
		}

		printf("* %2d번째 숫자 : ", count + 1);
		res = scanf("%d", &input);
		if (getchar() != '\n' || res < 1)
		{
			printf("* 잘못된 형식입니다. 다시 입력해주세요!\n\n");
			myfflush();
		}
		else
		{
			if (input % 2 == 0)
			{
				number[sizeArray - (j+1)] = input;
				j++;
			}
			else
			{
				number[i] = input;
				i++;
			}
			count++;
		}
	}

	return;
}

void output(int *number, int sizeArray)
{
	int i;

	printf("\n입력 결과 : ");

	for (i = 0; i < sizeArray; i++)
	{
		printf("%d ", number[i]);
	}
	printf("\n");

	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}

	return;
}