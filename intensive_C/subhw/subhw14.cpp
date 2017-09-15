#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char*);
void output(int);
void myfflush();

int main()
{
	int iterativeNum;

	iterativeNum = inputIntNum("# 정수값을 입력하시오 : ");
	output(iterativeNum);

	return 0;
}

int inputIntNum(char* str)
{
	int inputInt;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)
		{
			printf("문자를 입력했습니다. 양수만 입력해주세요!\n\n");
			myfflush();
		}
		else if (inputInt <= 0)
		{
			printf("양수만 입력해주세요!\n\n");
		}
		else
		{

			break;
		}
	}

	return inputInt;
}

void output(int iterativeNum)
{
	int total = 0;
	int i = 1;

	while (1)
	{
		if (i > iterativeNum)
		{
			printf("1부터 %d까지의 합은 %d입니다.\n", iterativeNum, total);
			break;
		}
		total += i;
		i++;
	}


	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}