#include <stdio.h>

int main(void) {

	double fahrenheit;
	double celcius;

	printf("화씨 온도를 입력하세요 : ");
	scanf("%lf", &fahrenheit);

	celcius = 5.0 / 9.0 * (fahrenheit - 32.0);

	printf("섭씨 온도는 %.1lf도입니다.\n", celcius);

	return 0;
}