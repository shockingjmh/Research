#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char*);
void output(int, int);
void myfflush();

int main()
{
	int age = 0;
	int numberOfaudience = 0;
	int entranceFee = 0;
	int discount = 0;

	age = inputIntNum("���尴�� ���̸� �Է��Ͻÿ� : ");
	numberOfaudience = inputIntNum("���尴�� ���� �Է��Ͻÿ� : ");
	if (age < 8)
	{
		entranceFee = 500 * numberOfaudience;
		if (numberOfaudience >= 5)
		{
			discount = (int)(entranceFee *0.1);
		}
	}
	else if (age < 14)
	{
		entranceFee = 700 * numberOfaudience;
		if (numberOfaudience >= 5)
		{
			discount = (int)(entranceFee *0.1);
		}
	}
	else if (age < 20)
	{
		entranceFee = 1000 * numberOfaudience;
		if (numberOfaudience >= 5)
		{
			discount = (int)(entranceFee *0.1);
		}
	}
	else if (age < 56)
	{
		entranceFee = 1500 * numberOfaudience;
		if (numberOfaudience >= 5)
		{
			discount = (int)(entranceFee *0.1);
		}
	}
	else
	{
		entranceFee = 500 * numberOfaudience;
		if (numberOfaudience >= 5)
		{
			discount = (int)(entranceFee *0.1);
		}
	}

	output(entranceFee, discount);


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

void output(int entranceFee, int discount)
{
	printf("\n����� => %d\n", entranceFee);
	printf("���αݾ� => %d\n", discount);
	printf("�����ݾ� => %d\n", entranceFee - discount);
	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}