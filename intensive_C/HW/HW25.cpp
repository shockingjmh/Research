#pragma warning(disable:4996)
#include <stdio.h>

char inputChar(char* str);
void output(char);
void myfflush();


int main()
{
	char inputCh;

	while (1)
	{
		inputCh = inputChar("* ������ �빮�� �Է�( 'A' ~ 'Z' ) : ");
		if (inputCh == 91)
		{
			break;
		}
		output(inputCh);
	}
	return 0;
}

char inputChar(char* str)
{
	char ch;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%c", &ch);
		
		if (ch < 65 || ch > 90 )
		{
			printf("'A' ~ 'Z'�̿� �ٸ� ���ڰ� �ԷµǾ����ϴ�. �����մϴ�.\n\n");
			ch = 91;
			myfflush();
			break;
		}
		else if (getchar() != '\n' || res == 0)
		{
			printf("'A' ~ 'Z'�̿� �ٸ� ���ڰ� �ԷµǾ����ϴ�. �����մϴ�.\n\n");
			ch = 91;
			myfflush();
			break;
		}
		else
		{
			break;
		}
	}

	return ch;
}

void output(char inputCh)
{
	int i, j;

	for (i = 0; i < inputCh - 64; ++i)
	{
		for (j = inputCh; j > inputCh - (i + 1); j -= 1)
		{
			printf("%c", j);
		}
		printf("\n");
	}

	return;
}

void myfflush() {

	while (getchar() != '\n')
	{
		;
	}

	return;
}