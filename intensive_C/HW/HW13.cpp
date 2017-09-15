#pragma warning(disable:4996)
#include <stdio.h>

int input();
int leapYearCheck(int);
void output(int,int);

int main(void) {

	int inputYear;
	int yearChecking;

	inputYear = input();
	yearChecking = leapYearCheck(inputYear);
	output(inputYear,yearChecking);

	return 0;
}

int input() {

	int year;

	printf("년도를 입력하시오 : ");
	scanf("%d", &year);

	return year;
}

int leapYearCheck(int inputYear) {

	int leapYear;

	if (inputYear % 4 != 0) {
		leapYear = 0;
	}
	else if (inputYear % 100 != 0) {
		leapYear = 1;
	}
	else if (inputYear % 400 != 0) {
		leapYear = 0;
	}
	else {
		leapYear = 1;
	}

	return leapYear;
}

void output(int inputYear, int yearChecking) {

	if (yearChecking == 0) {

		printf("%d년은 평년(Common year)입니다.\n", inputYear);

	}
	else {

		printf("%d년은 윤년(Leap year)입니다.\n", inputYear);

	}

	return;
}