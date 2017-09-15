#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void input(char*, char*);
int stringCheck(char, char);
void output(char*, char*, int);
void myfflush();

int main()
{
	char inputStr[20];
	char inputChar;
	int strLength = 0;

	input(inputStr, &inputChar);
	strLength = strlen(inputStr);
	output(inputStr, &inputChar, strLength);

	return 0;
}

void input(char* inputStr, char* inputChar)
{
	int res;

	printf("# ���ڿ��� �Է��Ͻÿ� : ");
	gets(inputStr);

	while (1)
	{
		printf("# ���ڸ� �Է��Ͻÿ� : ");
		res = scanf("%c", inputChar);
		if (getchar() != '\n' || res == 0)
		{
			printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���!\n\n");
			myfflush();
		}
		else
		{
			break;
		}
	}

	return;
}

int stringCheck(char inputStr, char inputChar)
{
	int result;

	if (inputChar == inputStr)
	{
		result = 1;
	}
	else
	{
		result = -1;
	}
	
	return result;
}

void output(char* inputStr, char* inputChar, int strLen)
{
	int count = 0;
	int result;
	int i;

	for (i = 0; i < strLen; i++)
	{
		result = stringCheck(inputStr[i], *inputChar);
		
		if (result == 1)
		{
			printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� %d��° �����Դϴ�.\n", inputStr, *inputChar, i + 1);
			count++;
		}
		else if (i == strLen - 1 && count == 0)
		{
			printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� �������� �ʽ��ϴ�.\n", inputStr, *inputChar);
		}
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