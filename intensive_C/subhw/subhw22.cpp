#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int inputIntNum(char* str);
int output(int, char*, char*);
void myfflush();

int main()
{
	srand((unsigned)time(NULL));

	int player = 0;
	int computer = 0;
	int checkResult = 0;
	int win = 0;
	int draw = 0;
	int exit = 0;
	char playerState[20];
	char computerState[20];

	while (1)
	{	
		computer = rand() % 3 + 1;

		checkResult = 0;

		player = inputIntNum("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");//바위는 1, 가위는 2, 보는 3 입력함수
		switch (player)
		{
		case 1:
			strcpy(playerState, "바위");
			switch (computer)
			{
			case 1:
				draw += 1;
				strcpy(computerState, "바위");
				break;
			case 2:
				win += 1;
				strcpy(computerState, "가위");
				checkResult = 1;
				break;
			case 3:
				checkResult = -1;
				strcpy(computerState, "보");
				break;
			}
			break;
		case 2:
			strcpy(playerState, "가위");
			switch (computer)
			{
			case 1:
				checkResult = -1;
				strcpy(computerState, "바위");
				break;
			case 2:
				draw += 1;
				strcpy(computerState, "가위");
				break;
			case 3:
				win += 1;
				checkResult = 1;
				strcpy(computerState, "보");
				break;
			}
			break;
		case 3:
			strcpy(playerState, "보");
			switch (computer)
			{
			case 1:
				win += 1;
				checkResult = 1;
				strcpy(computerState, "바위");
				break;
			case 2:
				checkResult = -1;
				strcpy(computerState, "가위");
				break;
			case 3:
				draw += 1;
				strcpy(computerState, "보");
				break;
			}
			break;
		}

		exit = output(checkResult, playerState, computerState);//출력함수
		if (exit == -1)
		{
			printf("%d 승 %d 무\n\n", win, draw);
			break;
		}
	}
	return 0;
}

int inputIntNum(char* str)//바위는 1, 가위는 2, 보는 3 입력함수
{
	int inputInt;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)
		{
			printf("바위는 1, 가위는 2, 보는 3 만 입력해주세요!\n\n");
			myfflush();
		}
		else if (inputInt < 1 || inputInt > 3)
		{
			printf("바위는 1, 가위는 2, 보는 3 만 입력해주세요!\n\n");
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

int output(int checkResult, char* playerState, char* computerState)
{
	int exit = 0;
	
	switch (checkResult)
	{
	case -1:
		printf("당신은 %s 선택, 컴퓨터는 %s 선택 : 당신이 졌습니다.\n\n", playerState, computerState);
		exit = -1;
		break;
	case 0:
		printf("당신은 %s 선택, 컴퓨터는 %s 선택 : 비겼습니다.\n\n",playerState, computerState);
		break;
	case 1:
		printf("당신은 %s 선택, 컴퓨터는 %s 선택 : 이겼습니다.\n\n", playerState, computerState);
		break;
	}
	return exit;
}

void myfflush()//사용자정의 fflush함수 
{
	while (getchar() != '\n')
	{
		;
	}

	return;
}