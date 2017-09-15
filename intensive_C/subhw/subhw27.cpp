#pragma warning(disable:4996)
#include <stdio.h>

int inputNum(char*);
char inputChar(int*, int*);
void output(char, int*, int*);
void myfflush();

int main()
{
	int startNum = 0;
	int endNum = 0;
	int inputCh;

	startNum = inputNum("# 시작값을 입력하시오 : ");
	while (1)
	{
		endNum = inputNum("# 끝값을 입력하시오 : ");
		if (startNum >= endNum)
		{
			printf("* 시작값이 끝값보다 크거나 같습니다. 다시 입력해주세요!\n");
		}
		else
		{
			break;
		}
	}
	inputCh = inputChar(&startNum, &endNum);
	output(inputCh, &startNum, &endNum);

	return 0;
}

int inputNum(char* str)
{
	int res;
	int inputInt;

	while (1)
	{
		printf(str);
		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)
		{
			printf("* 문자가 입력되었습니다. 다시 입력하세요!\n");
			myfflush();
		}
		else if (inputInt <= 0)
		{
			printf("* 양의 정수만 입력해주세요!\n");
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

char inputChar(int* startNum, int* endNum)
{
	char inputCh;
	int res = 0;

	while (1)
	{
		printf("* %d~%d까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", *startNum, *endNum);
		res = scanf("%c", &inputCh);
		if (getchar() != '\n' || res < 1)
		{
			printf("잘못된 입력입니다. 다시 입력해주세요!\n");
			myfflush();
		}
		else if ((inputCh == 'e' || inputCh == 'E') || (inputCh == 'o' || inputCh == 'O'))
		{
			break;
		}
		else
		{
			printf("잘못된 입력입니다. 다시 입력해주세요!\n");
		}
	}

	return inputCh;
}

void output(char inputCh, int* startNum, int* endNum)
{
	int sum = 0;
	int i;

	if (inputCh == 'e' || inputCh == 'E')
	{
		printf("  %d~%d까지의 짝수(", *startNum, *endNum);
		for (i = *startNum; i <= *endNum; i++)
		{
			if (i % 2 == 0)
			{
				sum += i;
				printf("%d", i);
			}

			if (i < *endNum)
			{
				printf(" ");
			}
		}
	}
	else
	{
		printf("  %d~%d까지의 홀수(", *startNum, *endNum);
		for (i = *startNum; i <= *endNum; i++)
		{
			if (i % 2 != 0)
			{
				sum += i;
				printf("%d", i);
			}

			if (i < *endNum)
			{
				printf(" ");
			}
		}
	}

	printf(")의 합은 %d입니다.\n", sum);

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