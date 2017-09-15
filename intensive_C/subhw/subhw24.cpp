#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int i, j;
	int sum;

	for (i = 0; i < 10; ++i)
	{
		sum = 0;
		for (j = 1; j < 11; ++j)
		{
			sum += (10 * i) + j;
		}
		printf("%2d ~ %3d = %3d\n", (10 * i) + 1, (10 * (i+1)), sum);
	}

	return 0;
}