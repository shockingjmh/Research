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

	distance = inputIntNum("����ī�� ����� �Ÿ��� KM ������ �Է��ϼ��� : ");
	totalFee = calcTotalFee(distance);
	output("�� �̿�� : %d��\n", totalFee);
	flag++;

	while (1)
	{
		payingFee = inputIntNum("�̿�� ������ ���� ������ �ݾ��� �������� �Է��ϼ��� : ");
		if (payingFee >= totalFee)
		{
			break;
		}
		else
		{
			printf("���� �ݾ��� �̿�Ẹ�� �۽��ϴ�. �ٽ� �Է����ּ���!\n\n");
		}
	}
	change = calcChange(payingFee, totalFee);
	output("�Ž����� : %d��\n", change);

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
		else if (inputInt < 0)
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