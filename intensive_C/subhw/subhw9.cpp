#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char*);
void output(int, int);
void myfflush();

int main()
{
	int quantitiy;
	int requestUnit;

	quantitiy = inputIntNum("오늘 생산된 노란 고무줄의 수량 : ");
	requestUnit = inputIntNum("고객이 요청한 묶음 단위 : ");

	output(quantitiy, requestUnit);

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
		else if (inputInt < 0)
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

void output(int quantity, int requestUnit)
{
	printf("오늘 생산된 노란 고무줄을 %d개 단위로 포장하면 총 %d개의 묶음을 만들고 %d개의 고무줄이 낱개로 남습니다.\n", requestUnit, quantity / requestUnit, quantity%requestUnit);
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}