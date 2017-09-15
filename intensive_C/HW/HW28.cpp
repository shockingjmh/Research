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

	printf("\n* 영문자대소문자 : %d개\n", engChar);
	printf("* 숫자문자 : %d개\n", numChar);
	printf("* 여백문자(space, tab, enter) : %d개\n", spaceChar);
	printf("* 그외 기타문자 : %d개\n", etcChar);

	return 0;
}