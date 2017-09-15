#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	char ch;
	int i;
	
	for (i = 1; i <= 100; i++)
	{
		if ((i % 3 != 0 && i % 5 != 0) || (i % 3 == 0 && i % 5 == 0))
		{
			printf("%2d", i);
		}
		else if (i % 3 == 0)
		{
			ch = '*';
			printf("%2c", ch);
		}
		else if (i % 5 == 0)
		{
			ch = '#';
			printf("%2c", ch);
		}

		if (i % 10 == 0)
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

