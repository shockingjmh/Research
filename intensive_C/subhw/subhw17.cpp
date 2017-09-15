#pragma warning(disable:4996)
#include <stdio.h>

char menu(char*);
int inputIntNum(char*);
void deposit(int*);
void withdraw(int*);
void myfflush();

int main()
{
	char menuChar = ' ';
	int myBalance = 0;

	printf("* 현재 잔액은 0원 입니다.\n\n");

	while (1)
	{
		menuChar = menu("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");

		if (menuChar == 'i')
		{
			deposit(&myBalance);
		}
		else if (menuChar == 'o')
		{
			withdraw(&myBalance);
		}
		else
		{
			break;
		}
	}

	return 0;

}

char menu(char* str)
{
	char menuChar;
	int res = 0;;

	while (1)
	{
		printf(str);
		res = scanf("%c", &menuChar);
		
		if (getchar() != '\n' || res == 0)
		{
			printf("* 잘못 입력하셨습니다.\n\n");
			myfflush();

		}
		else if (menuChar == 'i' || menuChar == 'o' || menuChar == 'q')
		{
			break;
		}
		else
		{
			printf("* 잘못 입력하셨습니다.\n\n");
		}
	}

	return menuChar;
}

void deposit(int* mBalance)
{
	int mDeposit = 0;

	mDeposit = inputIntNum("# 입금액을 입력하세요 : ");
	
	*mBalance += mDeposit;

	printf("* 현재 잔액은 %d원 입니다.\n\n", *mBalance);

	return;
}

void withdraw(int* mBalance)
{
	int mWithdraw = 0;

	mWithdraw = inputIntNum("# 출금액을 입력하세요 : ");

	if (*mBalance < mWithdraw)
	{
		printf("* 잔액이 부족합니다.\n");
	}
	else
	{
		*mBalance -= mWithdraw;
	}
	printf("* 현재 잔액은 %d원 입니다.\n\n", *mBalance);

	return;
}

int inputIntNum(char* str)
{
	char* sentence;
	char sen[100] = "* 잘못 입력하셨습니다. 다시 입력하십시오 : ";
	int inputInt;
	int res;

	sentence = str;

	while (1)
	{
		printf(sentence);

		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)
		{
			sentence = sen;
			myfflush();
		}
		else if (inputInt < 0)
		{
			sentence = sen;
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