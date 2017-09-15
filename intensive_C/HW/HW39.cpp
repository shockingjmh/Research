#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int menu();
int input(char*, char*);
int search(char(*)[80], char*, int*);
void word_input(char(*)[80], int*);
void word_output(char(*)[80], int*);
void word_search(char(*)[80], int*);
void word_delete(char(*)[80], int*);
void myfflush();

int main()
{
	char inputStr[20][80];
	int menuNum;
	int countStr = 0;

	while (1)
	{
		menuNum = menu();
		system("cls");

		switch (menuNum)
		{
		case 1:
			word_input(inputStr, &countStr);
			break;
		case 2:
			word_output(inputStr, &countStr);
			break;
		case 3:
			word_search(inputStr, &countStr);
			break;
		case 4:
			word_delete(inputStr, &countStr);
			break;
		default:
			break;
		}
		if (menuNum == 5)
		{
			break;
		}
	}

	return 0;
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

int input(char *str, char *inputStr)
{
	int strLen;
	int exit = 0;

	printf(str);
	gets(inputStr);
	strLen = strlen(inputStr);
	if (strLen > 79)
	{
		printf("* �Է� ������ ���̸� �ʰ��Ͽ����ϴ�. �ٽ� �Է����ּ���!\n\n");
	}
	else
	{
		if (strcmp(inputStr, "end") == 0 || strcmp(inputStr, "End") == 0 || strcmp(inputStr, "END") == 0)
		{
			exit = 1;
		}
	}

	return exit;
}

int search(char(*p)[80], char *temp, int *countStr)
{
	int i, count;

	for (i = 0, count = -1; i < *countStr; i++)
	{
		if (strcmp(p[i], temp) == 0)
		{
			count = i;
			break;
		}
	}

	return count;
}

void word_input(char(*p)[80], int *countStr)
{
	char temp[500];
	int exit;

	while (1)
	{
		if (*countStr > 19)
		{
			printf("* �޸𸮰� ��á���ϴ�.\n");
			printf("�ƹ� ��ư�̳� ������ �޴��� ���ư��ϴ�.\n\n");
			getch();
			break;
		}

		exit = input("# ���� �ܾ �Է��ϼ��� : ", temp);
		printf("\n");

		if (exit == 1)
		{
			break;
		}
		else
		{
			strcpy(p[*countStr], temp);
			(*countStr)++;
		}
	}

	system("cls");

	return;
}

void word_output(char(*p)[80], int *countStr)
{
	int i;

	if (*countStr == 0)
	{
		printf("�����Ͱ� �����ϴ�.\n\n");
	}

	for (i = 0; i < *countStr; ++i)
	{
		printf("�ܾ� %2d : %s\n", i + 1, p[i]);
		if (i == 9)
		{
			printf("\n\n�ƹ� ��ư�̳� �����ø� �������� ��µ˴ϴ�.\n\n");
			getch();
		}
	}
	printf("\n\n3�� �� �޴��� ���ư��ϴ�.\n");
	Sleep(3000);

	system("cls");

	return;
}

void word_search(char(*p)[80], int *countStr)
{
	char temp[500];
	int exit;
	int count;

	if (*countStr == 0)
	{
		printf("@ �����Ͱ� �����ϴ�.\n\n");
		printf("@ �ƹ� ��ư�̳� �����ø� �޴��� ���ư��ϴ�\n");
		getch();
		return;
	}

	while (1)
	{
		exit = input("# ã�� �ܾ �Է��ϼ��� : ", temp);
		if (exit == 1)
		{
			break;
		}

		count = search(p, temp, countStr);
		
		if (count == -1)
		{
			printf("@ %s ���ڿ��� �������� �ʽ��ϴ�.\n\n", temp);
		}
		else
		{
			printf("@ %s ���ڿ��� %2d��° ���ڿ��Դϴ�.\n\n", temp, count + 1);
		}
	}
	system("cls");

	return;
}

void word_delete(char(*p)[80], int *countStr)
{
	char temp[500];
	char deleteWord;
	int exit;
	int i, count;
	int res = 0;

	if (*countStr == 0)
	{
		printf("�����Ͱ� �����ϴ�.\n\n");
		printf("@ �ƹ� ��ư�̳� �����ø� �޴��� ���ư��ϴ�\n");
		getch();
		return;
	}

	while (1)
	{
		exit = input("# ������ �ܾ �Է��ϼ��� : ", temp);
		if (exit == 1)
		{
			break;
		}
		else
		{
			while (1)
			{
				printf("# ������ ���� �Ͻðڽ��ϱ�? (Y/N) : ");
				res = scanf("%c", &deleteWord);
				if (getchar() != '\n' || res < 1)
				{
					printf("* �߸��� �Է��Դϴ�. �ٽ� �Է����ּ���!\n\n");
					myfflush();
				}
				else if (deleteWord == 'y' || deleteWord == 'Y' || deleteWord == 'n' || deleteWord == 'N')
				{
					if (deleteWord == 'y' || deleteWord == 'Y')
					{
						count = search(p, temp, countStr);
						if (count == -1)
						{
							printf("@ %s ���ڿ��� �������� �ʽ��ϴ�.\n\n", temp);
						}
						else
						{
							for (i = count; i < *countStr-1; i++)
							{
								strcpy(p[i], p[i+1]);
							}
							*countStr -= 1;
							printf("@ �����Ǿ����ϴ�.\n\n");
						}
					}
					else
					{
						printf("@ ������ ��ҵǾ����ϴ�.\n\n");
					}
					break;
				}
				else
				{
					printf("* �߸��� �Է��Դϴ�. �ٽ� �Է����ּ���!\n\n");
				}
			}
		}

	}
	system("cls");

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