#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char* str);
void output(int);
void myfflush();


int main()
{
	int inputNum;

	while (1)
	{
		inputNum = inputIntNum("* 정수를 입력하시오 : ");
		if (inputNum < 0)
		{
			printf("종료합니다!\n");
			break;
		}
		output(inputNum);
	}

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
			printf("양의 정수만 입력해주세요!\n\n");
			myfflush();
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

void output(int inputNum)
{
	int i;

	for (i = inputNum; i < (inputNum + 11); i += 1)
	{
		printf("[%d] ", i);
	}
	printf("\n\n");

	return;
}
void myfflush() {

	while (getchar() != '\n')
	{
		;
	}

	return;
}
