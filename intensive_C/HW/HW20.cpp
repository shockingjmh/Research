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
		inputUserCode = inputIntNum("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용/4:종료) : ");

		if (inputUserCode > 0 && inputUserCode < 4)
		{
			userUse= userInputUse();
			printf("\n");
		}
		switch (inputUserCode)
		{
		case 1:
			strcpy(userCode, "1(가정용)");
			usingFee = userUse * 50;

			break;
		case 2:
			strcpy(userCode, "2(상업용)");
			usingFee = userUse * 45;
			
			break;
		case 3:
			strcpy(userCode, "3(공업용)");
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
			printf("1 ~ 4의 숫자만 입력해주세요!\n\n");
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

	userUse = inputIntNum("* 사용량을 입력하시오(ton단위) : ");

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

	printf("* 사용자코드 : %s\n", userCode);
	printf("* 사용량 : %dton\n", userUse);
	printf("* 총수도요금 : %d원\n\n", totalFee);

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
			printf("문자를 입력했습니다. 양수만 입력해주세요!\n\n");
			myfflush();
		}
		else if (inputInt < 0)
		{
			printf("양수만 입력해주세요!\n\n");
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