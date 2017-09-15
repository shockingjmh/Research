#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char*);
void output(int, int);
void myfflush();

int main()
{
	int quantitiy;
	int requestUnit;

	quantitiy = inputIntNum("���� ����� ��� ������ ���� : ");
	requestUnit = inputIntNum("���� ��û�� ���� ���� : ");

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

void output(int quantity, int requestUnit)
{
	printf("���� ����� ��� ������ %d�� ������ �����ϸ� �� %d���� ������ ����� %d���� ������ ������ �����ϴ�.\n", requestUnit, quantity / requestUnit, quantity%requestUnit);
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}