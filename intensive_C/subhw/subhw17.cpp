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

	printf("* ���� �ܾ��� 0�� �Դϴ�.\n\n");

	while (1)
	{
		menuChar = menu("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");

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
			printf("* �߸� �Է��ϼ̽��ϴ�.\n\n");
			myfflush();

		}
		else if (menuChar == 'i' || menuChar == 'o' || menuChar == 'q')
		{
			break;
		}
		else
		{
			printf("* �߸� �Է��ϼ̽��ϴ�.\n\n");
		}
	}

	return menuChar;
}

void deposit(int* mBalance)
{
	int mDeposit = 0;

	mDeposit = inputIntNum("# �Աݾ��� �Է��ϼ��� : ");
	
	*mBalance += mDeposit;

	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", *mBalance);

	return;
}

void withdraw(int* mBalance)
{
	int mWithdraw = 0;

	mWithdraw = inputIntNum("# ��ݾ��� �Է��ϼ��� : ");

	if (*mBalance < mWithdraw)
	{
		printf("* �ܾ��� �����մϴ�.\n");
	}
	else
	{
		*mBalance -= mWithdraw;
	}
	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", *mBalance);

	return;
}

int inputIntNum(char* str)
{
	char* sentence;
	char sen[100] = "* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ";
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