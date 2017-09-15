#pragma warning(disable:4996)
#include <stdio.h>

char inputIntNum(char*, int*, int*);
void output(int, int);
void myfflush();

int main()
{
	int inputInt1 = 0, inputInt2 = 0;

	while (1)
	{
		if (inputIntNum("두개의 정수를 입력하세요 : ", &inputInt1, &inputInt2) == 'e')
		{
			break;
		}
		else
		{
			output(inputInt1, inputInt2);
			inputInt1 = inputInt2 = 0;
		}
	}

	return 0;
}

char inputIntNum(char* str, int* inputInt1, int* inputInt2)
{
	char exit = 'a';
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d %d", inputInt1, inputInt2);
		if (getchar() != '\n' || res < 2)
		{
			printf("문자를 입력했습니다. 종료합니다.!\n\n");
			exit = 'e';
			break;
			myfflush();
		}
		else
		{
			break;
		}
	}

	return exit;
}

void output(int inputInt1, int inputInt2)
{
	int temp;

	if (inputInt1 < inputInt2)
	{
		temp = inputInt2;
		inputInt2 = inputInt1;
		inputInt1 = temp;
	}
	printf("%d - %d = %d\n", inputInt1, inputInt2, inputInt1 - inputInt2);

	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}