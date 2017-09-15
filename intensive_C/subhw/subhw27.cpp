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

	startNum = inputNum("# ���۰��� �Է��Ͻÿ� : ");
	while (1)
	{
		endNum = inputNum("# ������ �Է��Ͻÿ� : ");
		if (startNum >= endNum)
		{
			printf("* ���۰��� �������� ũ�ų� �����ϴ�. �ٽ� �Է����ּ���!\n");
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
			printf("* ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է��ϼ���!\n");
			myfflush();
		}
		else if (inputInt <= 0)
		{
			printf("* ���� ������ �Է����ּ���!\n");
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
		printf("* %d~%d������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", *startNum, *endNum);
		res = scanf("%c", &inputCh);
		if (getchar() != '\n' || res < 1)
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���!\n");
			myfflush();
		}
		else if ((inputCh == 'e' || inputCh == 'E') || (inputCh == 'o' || inputCh == 'O'))
		{
			break;
		}
		else
		{
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���!\n");
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
		printf("  %d~%d������ ¦��(", *startNum, *endNum);
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
		printf("  %d~%d������ Ȧ��(", *startNum, *endNum);
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

	printf(")�� ���� %d�Դϴ�.\n", sum);

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