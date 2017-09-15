#pragma warning(disable:4996)
#include <stdio.h>

double inputDoubleNum(char*, int);
void output(double);
void myfflush();

int main()
{
	int count = 0;
	double totalHeight = 0;

	while (1)
	{
		count += 1;
		if (count > 5)
		{
			break;
		}

		totalHeight += inputDoubleNum("- %d번 학생의 키는? ", count);
	}

	output(totalHeight);
}

double inputDoubleNum(char* str, int count)
{
	double inputDouble;
	int res;

	while (1)
	{
		printf(str, count);

		res = scanf("%lf", &inputDouble);
		if (getchar() != '\n' || res == 0)
		{
			printf("문자를 입력했습니다. 양의 실수만 입력해주세요!\n\n");
			myfflush();
		}
		else if (inputDouble < 0)
		{
			printf("양의 실수만 입력해주세요!\n\n");
		}
		else
		{

			break;
		}
	}

	return inputDouble;
}

void output(double totalHeight)
{
	printf("\n다섯명의 평균 키는 %.1lf cm 입니다.\n", totalHeight / 5);
	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}