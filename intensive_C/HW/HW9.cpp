#include <stdio.h>

int main(void) {

	int inputDay;
	int week;
	int day;

	printf("*날수를 입력하시오 : ");
	scanf("%d", &inputDay);

	week = inputDay / 7;
	day = inputDay - (week * 7);

	printf("%d일은 %d주 %d일 입니다\n", inputDay, week, day);

	return 0;
}