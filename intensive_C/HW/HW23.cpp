#pragma warning(disable:4996)
#include <stdio.h>

void charPrint(char, int, int);
char inputChar(char* str);
int inputIntNum(char* str);
void myfflush();


int main()
{
	char inputCh = '\n';
	int iterativeNum = 0;
	int iterativeLine = 0;

	while (1)
	{
		inputCh = inputChar("* 출력할 문자를 입력하시오 : ");//문자 입력 함수

		if (inputCh == '#')//# 입력시 종료
		{
			printf("종료합니다!\n");
			break;
		}

		iterativeNum = inputIntNum("* 한줄에 반복할 회수를 입력하시오 : ");//정수 입력함수 및 한줄에 반복할 횟수 리턴
		iterativeLine = inputIntNum("* 반복출력할 라인수를 입력하시오 : ");//정수 입력함수 및 반복 출력할 라인수 리턴

		charPrint(inputCh, iterativeNum, iterativeLine); //문자 출력 함수

	}

	return 0;
}

void charPrint(char inputCh, int iterativeNum, int iterativeLine)//문자 출력 함수
{
	int i, j;

	for (i = 0; i < iterativeLine; ++i)//문자 출력 라인수
	{
		printf("\n");
		for (j = 0; j < iterativeNum; ++j)//문자 출력 횟수
		{
			printf("%c", inputCh);
			
		}
	}

	printf("\n\n");

	return;
}

char inputChar(char* str)//문자 입력 함수
{
	char inputOneChar;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%c", &inputOneChar);
		if (getchar() != '\n' || res == 0)
		{
			printf("문자 하나만 입력해주세요!\n\n");//음수 입력시 정확한 char값이 출력되지 않으므로 예외처리
			myfflush();
		}
		else
		{
			break;
		}
	}


	return inputOneChar;
}

int inputIntNum(char* str)//정수 입력 함수
{
	int inputInt;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)//문자 예외처리
		{
			printf("양의 정수만 입력해주세요!\n\n");
			myfflush();
		}
		else if (inputInt <= 0)//0 및 음수 예외처리
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

void myfflush() // 사용자 fflush 함수 
{

	while (getchar() != '\n')
	{
		;
	}

	return;
}