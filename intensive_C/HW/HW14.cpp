#pragma warning(disable:4996)
#include <stdio.h>

char input();
void output(char);
void myfflush();

int main(void) 
{
	char inputChar;
	int i = 0;

	while (1)
	{
		if (i == 5){break;}

		inputChar = input();
		output(inputChar);

		i++;
	}

	return 0;
}

char input() 
{

	char inputChar;

	printf("f, m, b, s (��ҹ��� �������) �� �ϳ��� ���ڸ��� �Է��Ͻÿ� : ");
	inputChar = getchar();
	if (getchar() != '\n') 
	{ 
		inputChar = 'a';
		myfflush();
	}

	return inputChar;
}

void output(char inputChar)
{
	if (inputChar == 'f' || inputChar == 'F')
	{
		printf("Father\n");
	}
	else if (inputChar == 'm' || inputChar == 'M')
	{
		printf("Mother\n");
	}
	else if (inputChar == 'b' || inputChar == 'B')
	{
		printf("Brother\n");
	}
	else if (inputChar == 's' || inputChar == 'S')
	{
		printf("Sister\n");
	}
	else
	{
		printf("Input Error!!!\n");
	}

	return;
}

void myfflush() {

	while (getchar() != '\n'){ ; }

	return;
}