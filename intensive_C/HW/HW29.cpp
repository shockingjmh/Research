#pragma warning(disable:4996)
#include <stdio.h>

int inputDateNum(int*, int*, int*);
int checkDate(int*, int*, int*, int);
int calcTotalDays(int, int, int);
void output(int, int, int, int);
int leapYearCheck(int);

int main()
{
	int year = 0;
	int month = 0;
	int day = 0;
	int exit = 0;
	int totalDays = 0;

	while (1)
	{
		exit = inputDateNum(&year, &month, &day);
		if (exit == -1)
		{
			break;
		}
		totalDays = calcTotalDays(year, month, day);
		output(year, month, day, totalDays);
	}

	return 0;
}

int inputDateNum(int* year, int* month, int* day)
{
	
	int res;
	int check = 0;

	while (1)
	{
		printf("* 년월일을 입력하시오 : ");

		res = scanf("%d %d %d", year, month, day);
		check = checkDate(year, month, day, res);

		if (check == 0 || check == -1)//제대로 입력 0, 문자 입력 -1
		{
			break;
		}		
	}

	return check;
}

int checkDate(int* year, int* month, int* day, int res)
{
	int check = 0;
	int leapYear;
	char what;

	if ((what = getchar()) != '\n' || res < 3)
	{
		check = -1;//프로그램 종료
		printf("문자가 입력되었습니다. 종료합니다!\n\n");
	}
	else if ((*year < 1) || (*month < 1 || *month > 12) || (*day < 1 || *day > 31))
	{
		check = 1;//재입력 요구
		printf("올바른 형식으로 입력해주세요!\n\n");
	}
	else
	{
		if (*month == 2 && *day == 29)
		{
			leapYear = leapYearCheck(*year);
			if (leapYear != 0)
			{
				check = 1;//재입력 요구
				printf("%d년은 평년입니다. 그래서 2월은 28일까지만 있습니다. 다시 입력해주세요\n\n", *year);
			}
		}
		else if (*month == 4 || *month == 6 || *month == 9 || *month == 11)
		{
			if (*day > 30)
			{
				check = 1;//재입력 요구
				printf("%d월은 30일까지만 있습니다. 다시 입력해주세요.\n\n", *month);
			}
		}
	}

	return check;
}
int calcTotalDays(int year, int month, int day)
{
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totalDays = 0;
	int i;

	for (i = 1; i < year; i++)
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

	for (i = 1; i < month; i++)
	{
		totalDays += monthDay[i];
	}

	totalDays += day;

	if (leapYearCheck(year) == 0 && month > 2)//윤년에 3월달 이상이라면 하루 추가
	{
		totalDays += 1;
	}

	return totalDays;
}
void output(int year, int month, int day, int totalDays)
{
	char dayName[7][3] = {"일", "월", "화", "수", "목", "금", "토"};

	printf("%d년 %d월 %d일은 %s요일 입니다.\n\n", year, month, day, dayName[totalDays%7]);

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