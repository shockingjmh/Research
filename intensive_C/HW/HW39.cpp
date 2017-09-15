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

int input(char *str, char *inputStr)
{
	int strLen;
	int exit = 0;

	printf(str);
	gets(inputStr);
	strLen = strlen(inputStr);
	if (strLen > 79)
	{
		printf("* 입력 가능한 길이를 초과하였습니다. 다시 입력해주세요!\n\n");
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
			printf("* 메모리가 꽉찼습니다.\n");
			printf("아무 버튼이나 누르면 메뉴로 돌아갑니다.\n\n");
			getch();
			break;
		}

		exit = input("# 영문 단어를 입력하세요 : ", temp);
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
		printf("데이터가 없습니다.\n\n");
	}

	for (i = 0; i < *countStr; ++i)
	{
		printf("단어 %2d : %s\n", i + 1, p[i]);
		if (i == 9)
		{
			printf("\n\n아무 버튼이나 누르시면 나머지가 출력됩니다.\n\n");
			getch();
		}
	}
	printf("\n\n3초 뒤 메뉴로 돌아갑니다.\n");
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
		printf("@ 데이터가 없습니다.\n\n");
		printf("@ 아무 버튼이나 누르시면 메뉴로 돌아갑니다\n");
		getch();
		return;
	}

	while (1)
	{
		exit = input("# 찾는 단어를 입력하세요 : ", temp);
		if (exit == 1)
		{
			break;
		}

		count = search(p, temp, countStr);
		
		if (count == -1)
		{
			printf("@ %s 문자열은 존재하지 않습니다.\n\n", temp);
		}
		else
		{
			printf("@ %s 문자열은 %2d번째 문자열입니다.\n\n", temp, count + 1);
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
		printf("데이터가 없습니다.\n\n");
		printf("@ 아무 버튼이나 누르시면 메뉴로 돌아갑니다\n");
		getch();
		return;
	}

	while (1)
	{
		exit = input("# 삭제할 단어를 입력하세요 : ", temp);
		if (exit == 1)
		{
			break;
		}
		else
		{
			while (1)
			{
				printf("# 정말로 삭제 하시겠습니까? (Y/N) : ");
				res = scanf("%c", &deleteWord);
				if (getchar() != '\n' || res < 1)
				{
					printf("* 잘못된 입력입니다. 다시 입력해주세요!\n\n");
					myfflush();
				}
				else if (deleteWord == 'y' || deleteWord == 'Y' || deleteWord == 'n' || deleteWord == 'N')
				{
					if (deleteWord == 'y' || deleteWord == 'Y')
					{
						count = search(p, temp, countStr);
						if (count == -1)
						{
							printf("@ %s 문자열은 존재하지 않습니다.\n\n", temp);
						}
						else
						{
							for (i = count; i < *countStr-1; i++)
							{
								strcpy(p[i], p[i+1]);
							}
							*countStr -= 1;
							printf("@ 삭제되었습니다.\n\n");
						}
					}
					else
					{
						printf("@ 삭제가 취소되었습니다.\n\n");
					}
					break;
				}
				else
				{
					printf("* 잘못된 입력입니다. 다시 입력해주세요!\n\n");
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