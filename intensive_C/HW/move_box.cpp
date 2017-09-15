#pragma warning(disable:4996)
#include <stdio.h> 
#include <conio.h>
#include <windows.h> 

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

char inputChar();
int inputPositionNum(char* str, int*, int*, int*, int*);
void box(int, int, int, int);
void gotoxy(int, int);
void myfflush();
void textcolor(int, int);

int main(void)
{
	int sx, sy, ex, ey;
	int exit = 0;
	char inputCh;

	sx = sy = ex = ey = 0;
	printf("box는 위 = 'w' 아래 = 's' 왼쪽 = 'a' 오른쪽 = 'd' 버튼으로 움직입니다.\n\n");
	printf("문자를 입력하거나 box 출력 후 ESC를 누르면 종료됩니다.\n\n");
	exit = inputPositionNum("시작하는 x, y, 끝나는 x, y를 차례대로 입력해주세요 : ", &sx, &sy, &ex, &ey);
	if (exit == -1)
	{
		return 0;
	}

	while (1)
	{
		system("cls");
		box(sx, sy, ex, ey);
		inputCh = inputChar();
		switch (inputCh)
		{
		case 'w':
			if (sy == 1)
			{
				sy = 1;
			}
			else
			{
				sy -= 1;
				ey -= 1;
			}
			break;
		case 's':
			if (ey == 24)
			{
				ey = 24;
			}
			else
			{
				sy += 1;
				ey += 1;
			}
			break;
		case 'a':
			if (sx == 1)
			{
				sx = 1;
			}
			else
			{
				sx -= 1;
				ex -= 1;
			}
			break;
		case 'd':
			if (ex == 79)
			{
				ex = 79;
			}
			else
			{
				sx += 1;
				ex += 1;
			}
			break;
		case 27:
			system("cls");
			gotoxy(34, 11);
			textcolor(LIGHTRED, BLACK);
			printf("종료합니다!\n");
			gotoxy(22, 13);
			exit = -1;
			break;

		}
		if (exit == -1)
		{
			break;
		}
	}

	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int inputPositionNum(char* str, int* sx, int* sy, int* ex, int* ey)
{
	int res;
	int exit = 0;

	while (1)
	{
		printf(str);

		res = scanf("%d %d %d %d", sx, sy, ex, ey);
		if (getchar() != '\n' || res < 4)
		{
			printf("\n문자를 입력했습니다. 종료합니다!\n\n");
			exit = -1;
			myfflush();
			break;
		}
		else if ((*sx < 1 || *sx > 70) || (*sy < 1 || *sy > 20))
		{
			printf("시작하는 x 는 1<= x <=70, 시작 y 는 1 <= y <= 20 사이의 숫자만 입력해주세요!!\n\n");
		}
		else if (((*ex < *sx) || (*ex > 80)) || ((*ey < *sy) || (*ey > 24)))
		{
			printf("끝나는 x는 %d< x < 80, y는 %d < y < 24 사이의 숫자만 입력해주세요!!\n\n", *sx, *sy);
		}
		else
		{
			break;
		}
	}

	return exit;
}

void box(int sx, int sy, int ex, int ey)
{
	int i;
	int j;

	gotoxy(sx, sy);

	for (i = sy; i < ey + 1; i++)
	{
		for (j = sx; j < ex + 1; j++)
		{
			if (i == sy || i == ey)
			{
				gotoxy(j, i);
				printf("*");
			}
			else
			{
				if ((j == sx) || (j == ex))
				{
					gotoxy(j, i);
					printf("*");
				}
			}
		}
	}
	printf("\n");

	return;
}

char inputChar()
{
	char inputCh;

	inputCh = getch();
	if (inputCh == 'w' || inputCh == 'W')
	{
		inputCh = 'w';
	}
	else if (inputCh == 's' || inputCh == 'S')
	{
		inputCh = 's';
	}
	else if (inputCh == 'a' || inputCh == 'A')
	{
		inputCh = 'a';
	}
	else if (inputCh == 'd' || inputCh == 'D')
	{
		inputCh = 'd';
	}

	return inputCh;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}