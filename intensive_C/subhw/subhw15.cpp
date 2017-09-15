#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char*);
void output(int);
void myfflush();

int main()
{
	int iterativeNum;

	iterativeNum = inputIntNum("# �������� �Է��ϼ��� : ");
	output(iterativeNum);

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
			printf("���ڸ� �Է��߽��ϴ�. ����� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputInt <= 0)
		{
			printf("����� �Է����ּ���!\n\n");
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

void output(int iterativeNum)
{
	int i = 1;

	while (1)
	{
		if (i > iterativeNum)
		{
			printf("\n");
			break;
		}
		else
		{
			printf("*");
			if ((i % 5) == 0)
			{
				printf("\n");
			}
		}
		i++;
	}


	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}