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
		money = inputIntNum("현재 당신이 소유하고 있는 금액을 입력하시오 : ");

		if (money < 1600)
		{
			printf("현재 당신이 소유하고 있는 금액으로는 모든 품목을 한 개 이상씩 구입할 수 없습니다.\n");
			printf("1600원이상으로 다시 입력해주세요! 1600원 이상 입력할 때까지 계속됩니다.\n\n");
		}
		else
		{
			printf("\n현재 당신이 소유하고 있는 금액 : %d원\n", money);
			for (i = 1; i < (money / 500 + 1); i++)
			{
				for (j = 1; j < (money / 700 + 1); j++)
				{
					for (k = 1; k < (money / 400 + 1); k++)
					{
						totalPayment = 500 * i + 700 * j + 400 * k;
						if (totalPayment == money)
						{
							printf("크림빵(%d개), 새우깡(%d봉지), 콜라(%d병)\n", i, j, k);
							count++;
						}
						totalPayment = 0;
					}
				}
			}
			if (count != 0)
			{
				printf("어떻게 구입하시겠습니까?\n");
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
			printf("양의 정수만 입력해주세요!\n\n");
			myfflush();
		}
		else if (inputInt < 0)
		{
			printf("양의 정수만 입력해주세요!\n\n");
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