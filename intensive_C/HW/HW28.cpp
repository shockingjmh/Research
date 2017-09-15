#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	char ch;
	int engChar = 0;
	int numChar = 0;
	int spaceChar = 0;
	int etcChar = 0;

	while ((ch = getchar()) != EOF)
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			engChar++;
		}
		else if (ch >= '0' && ch <= '9')
		{
			numChar++;
		}
		else if (ch == ' ' || ch == '\t' || ch == '\n')
		{
			spaceChar++;
		}
		else
		{
			etcChar++;
		}
	}

	printf("\n* �����ڴ�ҹ��� : %d��\n", engChar);
	printf("* ���ڹ��� : %d��\n", numChar);
	printf("* ���鹮��(space, tab, enter) : %d��\n", spaceChar);
	printf("* �׿� ��Ÿ���� : %d��\n", etcChar);

	return 0;
}