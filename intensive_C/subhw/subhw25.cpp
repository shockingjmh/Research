#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i, j, k;
	int money = 3500;
	int totalPayment = 0;

	printf("���� ����� �����ϰ� �ִ� �ݾ� : %d��\n", money);
	for (i = 1; i < (3600 / 500 + 1); i++)
	{
		for (j = 1; j < (3600 / 700 + 1); j++)
		{
			for (k = 1; k < (3600 / 400 + 1); k++)
			{
				totalPayment = 500 * i + 700 * j + 400 * k;
				if (totalPayment == 3500)
				{
					printf("ũ����(%d��), �����(%d����), �ݶ�(%d��)\n", i, j, k);
				}
				totalPayment = 0;
			}
		}
	}
	printf("��� �����Ͻðڽ��ϱ�?\n");

	return 0;
}