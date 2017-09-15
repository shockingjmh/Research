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

	printf("���� %d���� �Է����ּ���!\n", sizeArray);

	for (i = 0; i < sizeArray; i++)
	{
		printf("%d ��° ���� : ", i);
		res = scanf("%d", &inputNum);

		if (getchar() != '\n' || res < 1)
		{
			printf("���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���!\n\n");
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
	
	printf("Ȧ�� :");
	for (i = 0; i < sizeArray; ++i)
	{
		if (input[i] % 2 != 0)
		{
			printf("%5d", input[i]);
		}
	}
	
	printf("\n¦�� :");
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