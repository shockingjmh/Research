#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int secondTime = 54321;
	int hour, minute, second;
	
	hour = secondTime / 3600;
	secondTime = secondTime - (hour * 3600);

	minute = secondTime / 60;
	secondTime = secondTime - (minute * 60);

	second = secondTime;
	secondTime = secondTime - second;

	secondTime = (hour * 3600) + (minute * 60) + second;

	printf("%d�ʴ� %d�ð� %d�� %d�� �Դϴ�.\n", secondTime, hour, minute, second);

	system("pause");

	return 0;
}