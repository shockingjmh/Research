#pragma warning(disable:4996)
#include <stdio.h>

void myfflush();

int main()
{
	int inputInt = 0;
	int res = 0;
	int sum = 0;;
	int i;

	for (i = 1; i <= 5; ++i)
	{
		printf("0���� ū���� �Է��Ͻÿ�(%d��°) : ", i);
		res = scanf("%d", &inputInt);

		if (getchar() != '\n' || res == 0)
		{
			i -= 1;
			myfflush();
		}
		else if (inputInt <= 0)
		{
			i -= 1;
		}
		else
		{
			sum += inputInt;
		}
	}

	printf("�Էµ� ���� �� �� : %d\n", sum);

	return 0;
}

void myfflush() {

	while (getchar() != '\n')
	{
		;
	}

	return;
}