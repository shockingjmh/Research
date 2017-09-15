#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int menu();
void mInput();
void mOutput();
void mSearch();
void mDelete();
void myfflush();

int main()
{
	int menuNum;

	while (1)
	{
		menuNum = menu();
		system("cls");

		if (menuNum == 1)
		{
			mInput();
		}
		else if (menuNum == 2)
		{
			mOutput();
		}
		else if (menuNum == 3)
		{
			mSearch();
		}
		else if (menuNum == 4)
		{
			mDelete();
		}
		else 
		{
			break;
		}
	}

	return 0;
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
			printf("문자를 입력했습니다. 양수만 입력해주세요!\n\n");
			myfflush();
		}
		else if (inputInt < 0)
		{
			printf("양수만 입력해주세요!\n\n");
		}
		else
		{

			break;
		}
	}

	return inputInt;
}

int menu()
{
	int menuNum = 0;
	int res;

	while (1)
	{
		printf("\n\n\n\n\n\n\t\t\t\t1. 입력하기\n\n");
		printf("\t\t\t\t2. 출력하기\n\n");
		printf("\t\t\t\t3. 검색하기\n\n");
		printf("\t\t\t\t4. 삭제하기\n\n");
		printf("\t\t\t\t5. 종    료\n\n");
		printf("\t\t\t# 메뉴를 선택하세요 : ");
		res = scanf("%d", &menuNum);
		system("cls");

		if (getchar() != '\n' || res == 0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t1 ~ 5 사이의 숫자만 입력해주세요!\n\n");
			printf("\t\t      # 아무 키나 누르면 주 메뉴로 돌아갑니다.");
			getch();
			myfflush();
			system("cls");
		}
		else if (menuNum < 1 || menuNum > 5)
		{
			
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t1 ~ 5 사이의 숫자만 입력해주세요!\n\n");
			printf("\t\t      # 아무 키나 누르면 주 메뉴로 돌아갑니다.");
			getch();
			myfflush();
			system("cls");
		}
		else
		{
			break;
		}
	}

	return menuNum;
}

void mInput()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t   1번 입력하기 메뉴입니다.\n\n");
	printf("\t\t      # 아무 키나 누르면 주 메뉴로 돌아갑니다.");
	getch();
	system("cls");

	return;
}

void mOutput()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t   2번 출력하기 메뉴입니다.\n\n");
	printf("\t\t      # 아무 키나 누르면 주 메뉴로 돌아갑니다.");
	getch();
	system("cls");
	
	return;
}

void mSearch()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t   3번 검색하기 메뉴입니다.\n\n");
	printf("\t\t      # 아무 키나 누르면 주 메뉴로 돌아갑니다.");
	getch();
	system("cls");

	return;
}

void mDelete()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t   4번 삭제하기 메뉴입니다.\n\n");
	printf("\t\t      # 아무 키나 누르면 주 메뉴로 돌아갑니다.");
	getch();
	system("cls");

	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}