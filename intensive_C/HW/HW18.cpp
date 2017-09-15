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

int menu()
{
	int menuNum = 0;
	int res;

	while (1)
	{
		printf("\n\n\n\n\n\n\t\t\t\t1. �Է��ϱ�\n\n");
		printf("\t\t\t\t2. ����ϱ�\n\n");
		printf("\t\t\t\t3. �˻��ϱ�\n\n");
		printf("\t\t\t\t4. �����ϱ�\n\n");
		printf("\t\t\t\t5. ��    ��\n\n");
		printf("\t\t\t# �޴��� �����ϼ��� : ");
		res = scanf("%d", &menuNum);
		system("cls");

		if (getchar() != '\n' || res == 0)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t1 ~ 5 ������ ���ڸ� �Է����ּ���!\n\n");
			printf("\t\t      # �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.");
			getch();
			myfflush();
			system("cls");
		}
		else if (menuNum < 1 || menuNum > 5)
		{
			
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t1 ~ 5 ������ ���ڸ� �Է����ּ���!\n\n");
			printf("\t\t      # �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.");
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
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t   1�� �Է��ϱ� �޴��Դϴ�.\n\n");
	printf("\t\t      # �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.");
	getch();
	system("cls");

	return;
}

void mOutput()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t   2�� ����ϱ� �޴��Դϴ�.\n\n");
	printf("\t\t      # �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.");
	getch();
	system("cls");
	
	return;
}

void mSearch()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t   3�� �˻��ϱ� �޴��Դϴ�.\n\n");
	printf("\t\t      # �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.");
	getch();
	system("cls");

	return;
}

void mDelete()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t   4�� �����ϱ� �޴��Դϴ�.\n\n");
	printf("\t\t      # �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.");
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