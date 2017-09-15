#pragma warning(disable:4996)
#include <stdio.h>

void printLine(int);
int inputIntNum(char* str);
void myfflush();


int main()
{
	int Line;

	while (1)
	{
		Line = inputIntNum("# ��� ���μ��� �Է��Ͻÿ� : ");
		if (Line == -1)
		{
			printf("�����մϴ�!\n");
			break;
		}
		printLine(Line);
	}

	return 0;
}

void printLine(int Line)
{
	int i, j;

	for (i = 0; i < Line; ++i)
	{
		for (j = 0; j < Line; ++j)
		{
			if (j < i + 1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}

		printf("  ");

		for (j = 0; j < Line; ++j)
		{
			if (j > (Line-2) - i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	printf("\n\n");
	return;
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
			inputInt = -1;
			break;
		}
		else if (inputInt < 0)
		{
			printf("0�� ���� ������ �Է����ּ���!\n\n");
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

void myfflush() {

	while (getchar() != '\n')
	{
		;
	}

	return;
}