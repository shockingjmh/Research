#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i, j, k;
	int money = 3500;
	int totalPayment = 0;

	printf("현재 당신이 소유하고 있는 금액 : %d원\n", money);
	for (i = 1; i < (3600 / 500 + 1); i++)
	{
		for (j = 1; j < (3600 / 700 + 1); j++)
		{
			for (k = 1; k < (3600 / 400 + 1); k++)
			{
				totalPayment = 500 * i + 700 * j + 400 * k;
				if (totalPayment == 3500)
				{
					printf("크림빵(%d개), 새우깡(%d봉지), 콜라(%d병)\n", i, j, k);
				}
				totalPayment = 0;
			}
		}
	}
	printf("어떻게 구입하시겠습니까?\n");

	return 0;
}