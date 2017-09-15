#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void input_integer(int*, int);
void output(int*, int);
void myfflush();

int main()
{
	int input[10];
	int sizeArray = sizeof(input) / sizeof(input[0]);

	input_integer(input, sizeArray);
	output(input, sizeArray);

	return 0;
}

void input_integer(int *input, int sizeArray)
{
	int res, inputNum;
	int i;

	printf("정수 %d개를 입력해주세요!\n", sizeArray);

	for (i = 0; i < sizeArray; i++)
	{
		printf("%d 번째 숫자 : ", i);
		res = scanf("%d", &inputNum);

		if (getchar() != '\n' || res < 1)
		{
			printf("문자가 입력되었습니다. 다시 입력해주세요!\n\n");
			i -= 1;
			myfflush();
		}
		else
		{
			input[i] = inputNum;
		}
	}

	return;
}

void output(int *input, int sizeArray)
{
	int i;
	
	printf("홀수 :");
	for (i = 0; i < sizeArray; ++i)
	{
		if (input[i] % 2 != 0)
		{
			printf("%5d", input[i]);
		}
	}
	
	printf("\n짝수 :");
	for (i = 0; i < sizeArray; ++i)
	{
		if (input[i] % 2 == 0)
		{
			printf("%5d", input[i]);
		}
	}

	printf("\n");

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