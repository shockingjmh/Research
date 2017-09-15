#pragma warning(disable:4996)
#include <stdio.h>

void inputNum(int*, int);
void output(int*, int);
void myfflush();

int main()
{
	int number[10];
	int sizeArray;

	sizeArray = sizeof(number) / sizeof(number[0]);
	
	inputNum(number, sizeArray);
	output(number, sizeArray);

	return 0;
}

void inputNum(int *number, int sizeArray)
{
	int input;
	int res;
	int count = 0;
	int i = 0;
	int j = 0;

	printf("# ���� 10���� �Է����ּ���(������ �������)\n");

	while (1)
	{
		if (count == 10)
		{
			break;
		}

		printf("* %2d��° ���� : ", count + 1);
		res = scanf("%d", &input);
		if (getchar() != '\n' || res < 1)
		{
			printf("* �߸��� �����Դϴ�. �ٽ� �Է����ּ���!\n\n");
			myfflush();
		}
		else
		{
			if (input % 2 == 0)
			{
				number[sizeArray - (j+1)] = input;
				j++;
			}
			else
			{
				number[i] = input;
				i++;
			}
			count++;
		}
	}

	return;
}

void output(int *number, int sizeArray)
{
	int i;

	printf("\n�Է� ��� : ");

	for (i = 0; i < sizeArray; i++)
	{
		printf("%d ", number[i]);
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