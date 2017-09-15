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
int checkDate(int*, int*, int*, int);
int calcTotalDays(int*, int*, int);
void output(int*, int*);
int leapYearCheck(int);
void gotoxy(int x, int y);
void textcolor(int foreground, int background);

int main()
{
	char inputCh;
	int exit = 0;
	int year = 2016;
	int month = 1;
	
	while (1)
	{
		output(&year, &month);
		inputCh = inputChar();
		system("cls");
		switch (inputCh)
		{
		case 'w':
			if (year == 1)
			{
				year = 1;
			}
			else
			{
				year -= 1;
				output(&year, &month);//전년도와 같은 월
			}
			break;
		case 's':
			year += 1;
			output(&year, &month);//다음 년도 같은 월
			break;
		case 'a':
			if (month == 1)
			{
				if (year == 1)
				{
					year = 1;
					month = 1;
				}
				else
				{
					year -= 1;
					month = 12;
				}
			}
			else
			{
				month -= 1;
			}
			output(&year, &month);//전월(1월 상태였을 경우 전년도 12월로 변경)
			break;
		case 'd':
			if (month == 12)
			{
				year += 1;
				month = 1;
			}
			else
			{
				month += 1;
			}
			output(&year, &month);//다음월(12월 상태였을 경우 다음 년도 1월로 변경)
			break;
		case 27:
			system("cls");
			gotoxy(34, 11);
			textcolor(LIGHTRED, BLACK);
			printf("종료합니다!\n");
			gotoxy(22, 13);
			exit = -1;
			break;
		default:
			textcolor(LIGHTRED, BLACK);
			gotoxy(15, 11);
			printf("잘못된 입력입니다. w, s, a, d 중 하나만 입력해주세요!\n");
			textcolor(LIGHTRED, BLACK);
			gotoxy(16, 13);
			printf("아무키나 누르시면 최근 보여졌던 달력으로 넘어갑니다.");
			getch();
			system("cls");
		}
		if (exit == -1)
		{
			break;
		}
	}

	return 0;
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

int calcTotalDays(int* year, int* month, int* monthNow)
{
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totalDays = 0;
	int i;

	for (i = 1; i < *year; i++)
	{
		if (leapYearCheck(i) == 1)//평년이라면
		{
			totalDays += 365;
		}
		else//윤년이라면
		{
			totalDays += 366;
		}
	}

	for (i = 1; i <= *month; i++)
	{
		if (i == *month)
		{
			*monthNow = monthDay[i];
			if (leapYearCheck(*year) == 0 && *month == 2)
			{
				*monthNow += 1;
			}
		}
		else
		{
			totalDays += monthDay[i];
		}
	}

	if (leapYearCheck(*year) == 0 && *month > 2)//윤년에 2월달 이상이라면 하루 추가
	{
		totalDays += 1;
	}

	return totalDays;
}

void output(int* year, int* month)
{
	char day[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int i;
	int sx = 15;
	int sy = 12;
	int monthNow = 0;
	int totalDays = 0;
	int whatDay = 0;

	textcolor(WHITE, BLACK);
	gotoxy(sx, sy - 6);
	printf("전년도와 같은 월 = 'w', 다음 년도 같은 월 = 's'");
	gotoxy(sx+5, sy - 4);
	printf("전월 = 'a', 다음 월 = 'd', 종료 = ESC");
	gotoxy(sx + 16, sy - 2);
	printf("%d년        %d월", *year, *month);

	for (i = 0; i < 7; i++)
	{
		gotoxy(sx, sy);
		if (i == 0)
		{
			textcolor(LIGHTRED, BLACK);
		}
		else if(i == 6)
		{
			textcolor(LIGHTBLUE, BLACK);
		}
		else
		{
			textcolor(WHITE, BLACK);
		}
		printf("%s", day[i]);
		sx += 8;
	}
	totalDays = calcTotalDays(year, month, &monthNow);

	sx = 15;
	sy += 1;

	for (i = 1; i <= monthNow; i++)
	{
		whatDay = (totalDays += 1) % 7;

		if (i == 1)//처음 위치 잡기
		{
			sx += (8 * whatDay);
		}

		if (whatDay == 6)
		{
			gotoxy(sx, sy);
			sy += 1;
			sx = 7;
			textcolor(LIGHTBLUE, BLACK);			
		}
		else if (whatDay == 0)
		{
			gotoxy(sx, sy);
			textcolor(LIGHTRED, BLACK);
		}
		else
		{
			gotoxy(sx, sy);
			textcolor(WHITE, BLACK);
		}
		printf("%2d", i);
		sx += 8;
	}
	printf("\n");

	return;
}

int leapYearCheck(int inputYear) {

	int leapYear;

	if (inputYear % 4 != 0) {
		leapYear = 1;//1이 평년
	}
	else if (inputYear % 100 != 0) {
		leapYear = 0;//0이 윤년
	}
	else if (inputYear % 400 != 0) {
		leapYear = 1;//1이 평년
	}
	else
	{
		leapYear = 0;//1이 윤년
	}

	return leapYear;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}