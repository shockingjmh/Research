#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <windows.h>

void inputStr(char*);
void output(char*);
void scrollStr(char*, int);
void blinkStr(char*);
void gotoxy(int x, int y);
void myfflush();

int main()
{
	char str[100] = "";
	int strLength = 0;
	int i;

	inputStr(str);
	if (strcmp("a", str) != 0)
	{
		strLength = strlen(str);
		for (i = 0; i < 3; i++)
		{
			output(str);
			scrollStr(str, strLength);
		}
		blinkStr(str);
	}
	return 0;
}

void inputStr(char* str)
{
	while (1)
	{
		system("cls");
		gotoxy(10, 11);
		printf("* 출력할 문자열을 입력하시오(a 입력 = 프로그램 종료) : \n");
		gotoxy(10, 13);
		gets(str);
		if (strcmp("\0", str) == 0 || strcmp(" ", str) == 0)
		{
			system("cls");
			gotoxy(10, 13);
			printf("아무것도 입력되지 않았습니다. 다시 입력해주세요!");
			Sleep(1000);
		}
		else
		{
			break;
		}
	}

	return;
}

void scrollStr(char* str, int strLength)
{
	char temp;
	int i;

	for (i = 0; i < strLength; i++)
	{
		if (i == 0)
		{
			temp = str[i];
		}
		else if (i == strLength - 1)
		{
			str[i] = temp;
			break;
		}
		str[i] = str[i + 1];
	}

	return;
}

void output(char* str)
{
	system("cls");
	gotoxy(30, 12);
	printf("[%s]\n", str);
	Sleep(1000);
	
	return;
}

void blinkStr(char* str)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		output(str);
		system("cls");
		if (i < 3)
		{
			Sleep(1000);
		}
	}

	return;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
	return;
}