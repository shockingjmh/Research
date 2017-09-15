#include <stdio.h>
#include <stdlib.h>

int main(void) {

	double day = 365.2422;
	double tempDay;
	int iday, ihour, iminute;
	double isecond;
	
	tempDay = day;

	iday = (int)day;
	day = day - iday;

	ihour = (int)(day * 24);
	day = day * 24 - ihour;

	iminute = (int)(day * 60);
	day = day * 60 - iminute;

	isecond = day * 60;

	day = tempDay;

	printf("%.4lf일은 %d일 %d시간 %d분 %.2lf초입니다.\n", day, iday, ihour, iminute, isecond);

	return 0;
}