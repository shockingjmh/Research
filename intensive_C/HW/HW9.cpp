#include <stdio.h>

int main(void) {

	int inputDay;
	int week;
	int day;

	printf("*������ �Է��Ͻÿ� : ");
	scanf("%d", &inputDay);

	week = inputDay / 7;
	day = inputDay - (week * 7);

	printf("%d���� %d�� %d�� �Դϴ�\n", inputDay, week, day);

	return 0;
}