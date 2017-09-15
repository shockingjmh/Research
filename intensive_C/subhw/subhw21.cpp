#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputIntNum(char* str, int, int);
int output(int, int, int);
void myfflush();

int main()
{
	srand((unsigned)time(NULL));

	int randNum = 0;
	int intNum = 0;
	int checkResult = 0;
	int count = 0;
	int max = 101;
	int min = 0;
	int flag;
	int exit = 0;

	
	randNum = rand() % 100 + 1;

	while (1)
	{
		intNum = inputIntNum("# 숫자를 입력하시오 : ",min, max);//1 ~ 100 정수 입력
		count += 1;

		if (count == 10)//10번의 게임이 끝난 후
		{
			checkResult = 4;
			flag = count;
		}
		else if (min < randNum && randNum < intNum )//난수값이 입력값보다 작고 최소값보다 큰 경우
		{
			max = intNum;
			checkResult = 1;
			flag = min;
		}
		else if (intNum < randNum && randNum < max)//난수값이 입력값보다 크고 최대값보다 작은 경우
		{
			min = intNum;
			checkResult = 2;
			flag = max;
		}
		else//정답을 맞춘 경우
		{
			checkResult = 0;
			flag = count;
		}

		exit = output(checkResult, flag, intNum);//출력함수
		if (exit == -1)
		{
			break;
		}
	}
	return 0;
}

int inputIntNum(char* str, int min, int max)//1~100 정수 입력 함수
{
	int inputInt;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)
		{
			printf("1 ~ 100 양수만 입력해주세요!\n\n");
			myfflush();
		}
		else if (inputInt <= 0)
		{
			printf("1 ~ 100 양수만 입력해주세요!\n\n");
		}
		else
		{
			if (inputInt<min || inputInt > max)
			{
				printf("잘못 입력하셨습니다. %d와 %d사이의 숫자를 입력해주세요!\n\n", min, max);//최대값과 최소값 사이의 숫자를 입력하지 않은 경우
			}
			else
			{
				break;
			}
		}
	}

	return inputInt;
}

int output(int checkResult, int flag, int intNum)
{
	int exit = 0;

	switch (checkResult)
	{
	case 0:
		printf("우와~ 맞았당~~~ 추카추카~~ %d번째 만에 맞추셨습니다.\n게임을 종료합니다!\n\n", flag);
		exit = -1;
		break;
	case 1:
		printf("%d보다는 크고 %d보다는 작습니다.\n\n", flag, intNum);
		break;
	case 2:
		printf("%d보다는 크고 %d보다는 작습니다.\n\n", intNum, flag);
		break;
	default:
		printf("%d번이나 했다. 고마하자\n\n", flag);
		exit = -1;
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