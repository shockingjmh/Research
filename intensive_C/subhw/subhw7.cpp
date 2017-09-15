#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char*);
int calcFee(int);
void output(int);
void myfflush();

int main()
{
	int stationNum;
	int fee;

	stationNum = inputIntNum("역수를 입력하시오 ; ");
	fee = calcFee(stationNum);
	output(fee);

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

int calcFee(int stationNum)
{
	int totalFee;
	int extraFee;
	int remainStation = 0;

	if (stationNum < 6)
	{
		totalFee = 500;
	}
	else if (stationNum < 11)
	{
		totalFee = 800;
	}
	else
	{
		remainStation = stationNum - 10;

		if ((remainStation % 2) == 1)
		{
			extraFee = ((remainStation / 2)+1) * 100;
			totalFee = 800 + extraFee;
		}
		else
		{
			extraFee = (remainStation / 2) * 100;
			totalFee = 800 + extraFee;
		}
	}

	return totalFee;
}
void output(int fee)
{
	printf("요금 : %d원\n", fee);

	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}