#pragma warning(disable:4996)
#include <stdio.h>

int inputNum(char*);
void output(char*, int);
void myfflush();

int main()
{
	int input = 0;
	int sum = 0;
	int i;

	for (i = 1; i < 11; i++)
	{
		input = inputNum("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
		output("* ���� �ް��� �� : %d\n", i);
	}

	printf("\n*** �ް� ������ �������ϴ�.\n");

	return 0;
}

int inputNum(char* str)
{
	int res;
	int input;

	while (1)
	{
		printf(str);
		res = scanf("%d", &input);

		if (getchar() != '\n' || res == 0)
		{
			printf("* ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���!\n");
			myfflush();
		}
		else if (input < 150)
		{
			printf("* ���߸��� ������ �峭���� ���ÿ�~^^\n");
		}
		else
		{
			break;
		}
	}
	
	return input;
}

void output(char* str, int count)
{
	printf(str, count);

	return;
}
void myfflush()
{
	while (getchar() != '\n')
	{

	}

	return;
}