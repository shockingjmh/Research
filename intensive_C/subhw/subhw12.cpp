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

		totalHeight += inputDoubleNum("- %d�� �л��� Ű��? ", count);
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
			printf("���ڸ� �Է��߽��ϴ�. ���� �Ǽ��� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputDouble < 0)
		{
			printf("���� �Ǽ��� �Է����ּ���!\n\n");
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
	printf("\n�ټ����� ��� Ű�� %.1lf cm �Դϴ�.\n", totalHeight / 5);
	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}