#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char* str);
void output(int);
void myfflush();


int main()
{
	int inputNum;

	while (1)
	{
		inputNum = inputIntNum("* ������ �Է��Ͻÿ� : ");
		if (inputNum < 0)
		{
			printf("�����մϴ�!\n");
			break;
		}
		output(inputNum);
	}

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
			printf("���� ������ �Է����ּ���!\n\n");
			myfflush();
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

void output(int inputNum)
{
	int i;

	for (i = inputNum; i < (inputNum + 11); i += 1)
	{
		printf("[%d] ", i);
	}
	printf("\n\n");

	return;
}
void myfflush() {

	while (getchar() != '\n')
	{
		;
	}

	return;
}
