#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int inputIntNum(char* str);
void myfflush();
void userInputCode();
int userInputUse();
int calcTotalFee(int);
void output(char*, int, int);

int main()
{
	userInputCode();

	return 0;
}

void userInputCode()
{
	char userCode[20] = "";
	int flag = 0;
	int inputUserCode = 0;
	int userUse = 0;
	int usingFee = 0;
	int totalFee = 0;

	while (1)
	{
		flag = 0;
		inputUserCode = inputIntNum("* ����� �ڵ带 �Է��Ͻÿ�(1:������/2:�����/3:������/4:����) : ");

		if (inputUserCode > 0 && inputUserCode < 4)
		{
			userUse= userInputUse();
			printf("\n");
		}
		switch (inputUserCode)
		{
		case 1:
			strcpy(userCode, "1(������)");
			usingFee = userUse * 50;

			break;
		case 2:
			strcpy(userCode, "2(�����)");
			usingFee = userUse * 45;
			
			break;
		case 3:
			strcpy(userCode, "3(������)");
			usingFee = userUse * 30;

			break;
		case 4:
			flag = 1;
			break;
		default:
			flag = 2;
			break;
		}

		if (flag == 1) 
		{ 
			break; 
		}
		else if (flag == 2)
		{
			printf("1 ~ 4�� ���ڸ� �Է����ּ���!\n\n");
		}
		else {
			totalFee = calcTotalFee(usingFee);
			output(userCode, userUse, totalFee);
		}
	}

	return;
}

int userInputUse()
{
	int userUse = 0;

	userUse = inputIntNum("* ��뷮�� �Է��Ͻÿ�(ton����) : ");

	return userUse;
}

int calcTotalFee(int usingFee)
{

	int totalFee;

	totalFee = (int)(usingFee + (usingFee * 0.05));

	return totalFee;
}

void output(char* userCode, int userUse, int totalFee)
{

	printf("* ������ڵ� : %s\n", userCode);
	printf("* ��뷮 : %dton\n", userUse);
	printf("* �Ѽ������ : %d��\n\n", totalFee);

	return;
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

void myfflush() {

	while (getchar() != '\n')
	{
		;
	}

	return;
}