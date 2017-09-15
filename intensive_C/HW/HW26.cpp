#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i, j, count;

	count = 0;

	for (i = 1; i <= 9; i++)
	{
		if (count < 36)
		{
			for (j = 2; j <= 5; j++)
			{
				printf("%d*%d=%2d\t", j, i, j*i);
				count += 1;
			}

			if (i == 9)
			{
				i = 0;
				printf("\n");
			}
		}
		else
		{
			for (j = 6; j <= 9; j++)
			{
				printf("%d*%d=%2d\t", j, i, j*i);
				count += 1;
			}
		}
		printf("\n");
	}

	return 0;
}