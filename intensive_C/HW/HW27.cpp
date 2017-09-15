#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>

int inputIntNum(char* str);
int primeNumber(int);
void myfflush();

int main()
{
	int inputNum;
	int count = 0;
	int primeResult = 0;
	int i;

	inputNum = inputIntNum("*정수값 하나를 입력하시오 : ");

	printf("1~%d까지의 소수값은 다음과 같습니다.\n", inputNum);
	for (i = 2; i < inputNum; i++)
	{
		primeResult = primeNumber(i);

		if (primeResult == 1)
		{
			printf("%d", i);
			count += 1;
			if (count % 5 == 0)
			{
				printf("\n");
			}
			else
			{
				printf("\t");
			}
		}
	}

	printf("\n1~%d까지의 총 소수는 %d개 입니다.\n", inputNum, count);

	
	
	return 0;
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
			printf("문자를 입력했습니다. 양의 정수만 입력해주세요!\n\n");
			myfflush();
		}
		else if (inputInt <= 0)
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

int primeNumber(int number)
{
	int primeResult = 1;
	int i;

	for (i = 2; i < number; i++)
	{
		if ((number % i) == 0)
		{
			primeResult = 0;
			break;
		}
	}

	return primeResult;
}

void myfflush() {

	while (getchar() != '\n')
	{
		;
	}

	return;
}