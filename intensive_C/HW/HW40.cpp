#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void input_rand(int*, int);
void check_ballcount(int*, int);
void input_integer(int*, int);
int output(int, int);

int main()
{
	srand((unsigned int)time(NULL));
	int randNum[4];
	int sizeArray = sizeof(randNum) / sizeof(randNum[0]);
	int i;

	input_rand(randNum, sizeArray);

	printf("정답 :");
	for (i = 0; i < 4; i++)
	{
		printf("%3d", randNum[i]);
	}
	printf("\n\n");

	check_ballcount(randNum, sizeArray);

	return 0;
}

void input_rand(int *randNum, int sizeArray)
{
	int count;
	int i, j;

	while (1)
	{
		count = 0;

		for (i = 0; i < sizeArray; ++i)
		{
			randNum[i] = rand() % 10;
		}

		for (i = 0; i < sizeArray - 1; ++i)
		{
			for (j = i + 1; j < sizeArray; ++j)
			{
				if (randNum[i] == randNum[j])
				{
					++count;
					break;
				}
			}
			if (count != 0)
			{
				break;
			}
		}

		if (count == 0)
		{
			break;
		}
	}

	return;
}

void check_ballcount(int *randNum, int sizeArray)
{
	int inputNum[4];
	int strike = 0;
	int ball = 0;
	int gameCount = 0;
	int result;
	int i, j;

	while (1)
	{
		strike = 0;
		ball = 0;

		input_integer(inputNum, sizeArray);

		for (i = 0; i < sizeArray; ++i)
		{
			for (j = 0; j < sizeArray; ++j)
			{
				if (randNum[i] == inputNum[j])
				{
					if (i == j)
					{
						++strike;
					}
					else
					{
						++ball;
					}
				}
			}
		}

		result = output(strike, ball);

		if (result == 1)
		{
			break;
		}
	}

	return;
}

int output(int strike, int ball)
{
	int result = 0;

	if (strike == 0 && ball == 0)
	{
		printf("  NO!\n");
	}
	else if (strike == 4)
	{
		printf("  OK!!!\n");
		result = 1;
	}
	else
	{
		printf("  %dS  %dB\n", strike, ball);
	}

	return result;
}

void input_integer(int *inputNum, int sizeArray)
{
	static int gameCount = 0;
	char inputCh;
	int flag;
	int i;

	++gameCount;

	while (1)
	{
		printf("# %d차:", gameCount);

		for (i = 0; i < sizeArray; ++i)
		{
			flag = 0;
			printf(" ");
			inputCh = getche();
			if (inputCh < '0' || inputCh > '9')
			{
				printf("\n* 잘못된 입력입니다. 다시 입력하세요\n\n");
				i -= 1;
				break;
			}
			else
			{
				inputNum[i] = inputCh - '0';
				flag = 1;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}

	return;
}