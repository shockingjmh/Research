#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int inputIntNum(char*);
int menu();
void fanOpen(unsigned char*, int);
void fanOff(unsigned char*, int);
void fanReverse(unsigned char*, int);
void fanDisplay(unsigned char*, int);
void myfflush();

int main()
{
	unsigned char fanState = 0;
	int sizeBit = sizeof(unsigned char) * 8;
	int menuNum;
	int exit = 0;
	
	while (exit == 0)
	{
		menuNum = menu();

		switch (menuNum)
		{
		case 1:
			fanOpen(&fanState, sizeBit);
			break;
		case 2:
			fanOff(&fanState, sizeBit);
			break;
		case 3:
			fanReverse(&fanState, sizeBit);
			break;
		case 4:
			exit = -1;
			break;
		}
	}

	return 0;
}

int inputIntNum(char* str)
{
	int result;
	int res;

	while (1)
	{
		printf(str);
		res = scanf("%d", &result);
		printf("--------------------------------------------------------------------\n\n");

		if (getchar() != '\n' || res < 1)
		{
			printf("문자가 입력되었습니다. 다시 입력해주세요!\n\n");
			myfflush();
		}
		else if (result <= 0)
		{
			printf("양의 정수만 입력해주세요!\n\n");
		}
		else
		{
			break;
		}
	}

	return result;
}

int menu()
{
	int inputNum;

	while (1)
	{
		inputNum = inputIntNum("1. 환풍구 열기/ 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");

		if (inputNum > 4)
		{
			printf("1 ~ 4 중 하나를 선택해주세요!\n\n");
		}
		else
		{
			break;
		}
	}

	return inputNum;
}
void fanOpen(unsigned char *p, int sizeBit)
{
	unsigned char bitController = 1;
	int inputNum;
	int i;

	while (1)
	{
		printf("--------------------------------------------------------------------\n");
		inputNum = inputIntNum("* OPEN할 FAN 번호를 입력하시오(1-8) : ");

		if (inputNum > 8)
		{
			printf("1 ~ 8 중 하나를 선택해주세요!\n\n");
		}
		else
		{
			for (i = 1; i < inputNum; i++)
			{
				bitController *= 2;
			}

			*p |= bitController;

			fanDisplay(p, sizeBit);
			break;
		}
	}

}
void fanOff(unsigned char *p, int sizeBit)
{
	unsigned char bitController = 1;
	int inputNum;
	int i;

	while (1)
	{
		printf("--------------------------------------------------------------------\n");
		inputNum = inputIntNum("* CLOSE할 FAN 번호를 입력하시오(1-8) : ");

		if (inputNum > 8)
		{
			printf("1 ~ 8 중 하나를 선택해주세요!\n\n");
		}
		else
		{
			for (i = 1; i < inputNum; i++)
			{
				bitController *= 2;
			}
			
			bitController = ~ bitController;
			*p &= bitController;

			fanDisplay(p, sizeBit);
			break;
		}
	}
	return;
}

void fanReverse(unsigned char *p, int sizeBit)
{

	(*p)=~(*p);
	printf("--------------------------------------------------------------------\n");
	printf("       전체 FAN의 상태가 전환되었습니다. (ON, OFF 상태 뒤바뀜)\n");
	printf("--------------------------------------------------------------------\n");
	fanDisplay(p, sizeBit);

	return;
}

void fanDisplay(unsigned char *p, int sizeBit)
{
	unsigned char temp = *p;
	unsigned char current = 0;
	char state[4];
	int i;

	printf("8번FAN   7번FAN   6번FAN   5번FAN   4번FAN   3번FAN   2번FAN   1번FAN\n");

	for (i = 0; i < sizeBit; i++)
	{
		current = temp & 0x80;
		if (current == 0)
		{
			strcpy(state, "OFF");
			printf("%5s    ", state);
		}
		else
		{
			strcpy(state, "ON");
			printf("%5s    ", state);
		}
		temp <<= 1;
	}

	printf("\n--------------------------------------------------------------------\n\n");

	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}

	return;
}