#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i, j;

	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			printf("%d", (10 * j) + i);
			if (j == 10)
			{
				printf("\n");
			}
			else
			{
				printf("\t");
			}
	}

	return 0;
}