#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char* str);
void output(int);
void myfflush();

int main()
{
	int intNum = 0;
	int sum = 0;

	while (1)
	{
		intNum = inputIntNum("����� �Է��ϼ��� : ");
		if (intNum == -1)
		{
			printf("\n������ �Է��߽��ϴ�. �����մϴ�.\n");
			break;
		}
		sum += intNum;
		output(sum);
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
			printf("���ڸ� �Է��߽��ϴ�. ����� �Է����ּ���!\n\n");
			myfflush();
		}
		else
		{
			break;
		}
	}

	return inputInt;
}

void output(int sum)
{

	printf("���ݱ��� �Էµ� ���� �� : %d\n", sum);

	return;
}

void myfflush() {

	while (getchar() != '\n')
	{
		;
	}

	return;
}