#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char*);
char inputChar(char *);
void output(int, char);
void myfflush();

int main()
{
	char iterativeChar;
	int iterativeNum;

	iterativeNum = inputIntNum("# �ݺ�ȸ���� �Է��Ͻÿ� : ");
	iterativeChar = inputChar("# �ݺ����ڸ� �Է��Ͻÿ� : ");

	output(iterativeNum, iterativeChar);

}

int inputIntNum(char* str)
{
	int inputInt;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)
		{
			printf("���ڸ� �Է��߽��ϴ�. ����� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputInt < 0)
		{
			printf("����� �Է����ּ���!\n\n");
		}
		else
		{

			break;
		}
	}

	return inputInt;
}

char inputChar(char* str)
{
	char ch;

	printf(str);
	scanf("%c", &ch);

	return ch;
}

void output(int iterativeNum, char iterativeChar)
{
	int i = 0;

	while (1)
	{
		if (i >= iterativeNum)
		{
			printf("\n");
			break;
		}
		printf("%c", iterativeChar);
		i++;
	}

	return;
}


void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}