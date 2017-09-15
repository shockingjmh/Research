#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char*);
int calcTotalFee(int);
int calcChange(int, int);
void output(char*, int);
void myfflush();

int main()
{
	int distance = 0;
	int totalFee = 0;
	int payingFee = 0;
	int change = 0;
	int flag = 0;
	int result = 0;

	distance = inputIntNum("레저카를 사용한 거리를 KM 단위로 입력하세요 : ");
	totalFee = calcTotalFee(distance);
	output("총 이용료 : %d원\n", totalFee);
	flag++;

	while (1)
	{
		payingFee = inputIntNum("이용료 정산을 위해 지불한 금액을 원단위로 입력하세요 : ");
		if (payingFee >= totalFee)
		{
			break;
		}
		else
		{
			printf("지불 금액이 이용료보다 작습니다. 다시 입력해주세요!\n\n");
		}
	}
	change = calcChange(payingFee, totalFee);
	output("거스름돈 : %d원\n", change);

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

int calcTotalFee(int distance)
{
	int totalFee;

	totalFee = distance * 500;
	totalFee += (int)(totalFee*0.1);

	return totalFee;
}

int calcChange(int payingFee, int totalFee)
{
	int change;

	change = payingFee - totalFee;

	return change;
}

void output(char *str, int currentValue)
{

	printf(str, currentValue);

	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}