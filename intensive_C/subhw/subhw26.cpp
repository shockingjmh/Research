#pragma warning(disable:4996)
#include <stdio.h>

int inputNum(char*);
void output(char*, int);
void myfflush();

int main()
{
	int input = 0;
	int sum = 0;
	int i;

	for (i = 1; i < 11; i++)
	{
		input = inputNum("# 계란의 무게를 입력하세요(단위 : g) : ");
		output("* 현재 달걀의 수 : %d\n", i);
	}

	printf("\n*** 달걀 포장이 끝났습니다.\n");

	return 0;
}

int inputNum(char* str)
{
	int res;
	int input;

	while (1)
	{
		printf(str);
		res = scanf("%d", &input);

		if (getchar() != '\n' || res == 0)
		{
			printf("* 문자가 입력되었습니다. 다시 입력해주세요!\n");
			myfflush();
		}
		else if (input < 150)
		{
			printf("* 메추리알 가지고 장난하지 마시오~^^\n");
		}
		else
		{
			break;
		}
	}
	
	return input;
}

void output(char* str, int count)
{
	printf(str, count);

	return;
}
void myfflush()
{
	while (getchar() != '\n')
	{

	}

	return;
}