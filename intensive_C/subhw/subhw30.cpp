#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void input_string(char*);
void output(char*, int);
int calc_number(char*);
void myfflush();

int main()
{
	char inputStr[200];
	int sumOfChar;

	input_string(inputStr);
	sumOfChar = calc_number(inputStr);
	output(inputStr, sumOfChar);

	return 0;
}

void input_string(char *inputStr)
{
	char tempStr[500];
	int checkStrLen;

	while (1)
	{
		printf("# ���ڿ��� �Է����ּ��� : ");
		gets(tempStr);

		checkStrLen = strlen(tempStr);

		if (checkStrLen > 199)
		{
			printf("* �Է� ������ ���̸� �ʰ��߽��ϴ�. �ٽ� �Է����ּ���!\n\n");
		}
		else
		{
			strcpy(inputStr, tempStr);
			break;
		}
	}

	return;
}

int calc_number(char *inputStr)
{
	int sum = 0;
	int i;
	int strLen = strlen(inputStr);

	for (i = 0; i < strLen; i++)
	{
		if (inputStr[i] >= 48 && inputStr[i] <= 57)
		{
			sum += inputStr[i] - '0';
		}

	}

	return sum;
}

void output(char* inputStr, int sum)
{
	printf("\n%s�ȿ� ������ �� : %3d\n", inputStr, sum);

	return;
}


void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}

	return;
}