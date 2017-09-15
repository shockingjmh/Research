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

	stationNum = inputIntNum("������ �Է��Ͻÿ� ; ");
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
			printf("���ڸ� �Է��߽��ϴ�. ����� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputInt <= 0)
		{
			printf("����� �Է����ּ���!\n\n");
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
	printf("��� : %d��\n", fee);

	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}