#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char* str);
void myfflush();

int main()
{
	int i, j, k;
	int money = 0;
	int totalPayment = 0;
	int count = 0;
	int flag = 0;

	while (flag == 0)
	{
		money = inputIntNum("���� ����� �����ϰ� �ִ� �ݾ��� �Է��Ͻÿ� : ");

		if (money < 1600)
		{
			printf("���� ����� �����ϰ� �ִ� �ݾ����δ� ��� ǰ���� �� �� �̻� ������ �� �����ϴ�.\n");
			printf("1600���̻����� �ٽ� �Է����ּ���! 1600�� �̻� �Է��� ������ ��ӵ˴ϴ�.\n\n");
		}
		else
		{
			printf("\n���� ����� �����ϰ� �ִ� �ݾ� : %d��\n", money);
			for (i = 1; i < (money / 500 + 1); i++)
			{
				for (j = 1; j < (money / 700 + 1); j++)
				{
					for (k = 1; k < (money / 400 + 1); k++)
					{
						totalPayment = 500 * i + 700 * j + 400 * k;
						if (totalPayment == money)
						{
							printf("ũ����(%d��), �����(%d����), �ݶ�(%d��)\n", i, j, k);
							count++;
						}
						totalPayment = 0;
					}
				}
			}
			if (count != 0)
			{
				printf("��� �����Ͻðڽ��ϱ�?\n");
				flag = -1;
			}
		}
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
			printf("���� ������ �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputInt < 0)
		{
			printf("���� ������ �Է����ּ���!\n\n");
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}