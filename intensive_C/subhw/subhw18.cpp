#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char* str);
void output(int);
void myfflush();

int main()
{
	int intNum = 0;
	int sum = 0;

	while (1)
	{
		intNum = inputIntNum("양수를 입력하세요 : ");
		if (intNum == -1)
		{
			printf("\n음수를 입력했습니다. 종료합니다.\n");
			break;
		}
		sum += intNum;
		output(sum);
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
			printf("문자를 입력했습니다. 양수만 입력해주세요!\n\n");
			myfflush();
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

void output(int sum)
{

	printf("지금까지 입력된 값의 합 : %d\n", sum);

	return;
}

void myfflush() {

	while (getchar() != '\n')
	{
		;
	}

	return;
}