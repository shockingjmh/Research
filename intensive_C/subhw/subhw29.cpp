#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void input_string(char*);
void make_toLower(char*);
void output(char*, int);
void myfflush();
int check_palindrome(char*);

int main()
{	
	char inputStr[200];
	char str[200];
	int checkPalin = 0;

	input_string(inputStr);
	strcpy(str, inputStr);

	make_toLower(inputStr);
	checkPalin = check_palindrome(inputStr);
	output(str, checkPalin);

	return 0;
}

void input_string(char *inputStr)
{
	char tempStr[500];
	int res;
	int checkStrLen;

	while (1)
	{
		printf("# ���ڿ��� �Է����ּ��� : ");
		res = scanf("%s", tempStr);
		
		checkStrLen = strlen(tempStr);

		if (checkStrLen > 199)
		{
			printf("* �Է� ������ ���̸� �ʰ��߽��ϴ�. �ٽ� �Է����ּ���!\n\n");
			myfflush();
		}

		if (getchar() !='\n' || res < 1)
		{
			printf("* ������ �ԷµǾ����ϴ�. �ܾ �Է����ּ���!\n\n");
			myfflush();
		}
		else
		{
			strcpy(inputStr, tempStr);
			break;
		}
	}

	return;
}

void make_toLower(char *inputStr)
{
	int i;

	for (i = 0; i < (signed)strlen(inputStr); i++)
	{
		if (inputStr[i] >= 'A' && inputStr[i] <= 'Z')
		{
			inputStr[i] = tolower(inputStr[i]);
		}
	}

	return;
}

int check_palindrome(char *inputStr)
{
	int i;
	int result = 1;
	int strLen = strlen(inputStr);

	for (i = 0; i < (strLen / 2); i++)
	{
		if (inputStr[i] != inputStr[strLen - (i+1)])
		{
			result = 0;
			break;
		}
	}

	return result;
}

void output(char* str, int checkPalin)
{

	switch (checkPalin)
	{
	case 0:
		printf("%s�� ȸ���� �ƴմϴ�!\n\n", str);
		break;
	case 1:
		printf("%s�� ȸ���Դϴ�.\n\n", str);
		break;
	}

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