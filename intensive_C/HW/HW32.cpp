#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void input(char*, char*);
int stringCheck(char*, char*, int);
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

	while (1)
	{
		printf("# 문자열을 입력하시오 : ");
		scanf(" %s", inputStr);
		if (getchar() != '\n')
		{
			printf("공백 없이 입력해주세요!\n");
			myfflush();
		}
		else
		{
			break;
		}
	}

	while (1)
	{
		printf("# 문자를 입력하시오 : ");
		res = scanf("%c", inputChar);
		if (getchar() != '\n' || res == 0)
		{
			printf("잘못된 형식입니다. 다시 입력해주세요!\n\n");
			myfflush();
		}
		else
		{
			break;
		}
	}

	return;
}

int stringCheck(char* inputStr, char* inputChar, int strLength)
{
	int result = -1;
	int i;

	for (i = 0; i < strLength; i++)
	{
		if (*inputChar == inputStr[i])
		{
			result = i + 1;
			break;
		}
		else
		{
			result = -1;
		}
	}

	return result;
}

void output(char* inputStr, char* inputChar, int strLen)
{
	int result = 0;

	result = stringCheck(inputStr, inputChar, strLen);

	if (result == -1)
	{
		printf("\"%s\" 문자열 안에 '%c' 문자는 존재하지 않습니다.\n\n", inputStr, *inputChar);
	}
	else
	{
		printf("\"%s\" 문자열 안에 '%c' 문자는 %d번째 문자입니다.\n\n", inputStr, *inputChar, result);
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